#include<bits/stdc++.h>
#define MAX 100005
#define avg(a, b) (((a) + (b)) >> 1)
#define left(a) ((a) << 1)
#define right(a) (left(a) + 1)
#define INF 1000000000
using namespace std;


int n;
int arr[MAX];
int i, j;


struct segment
{
	int val, sz;
};
inline bool operator < (const segment & a, const segment & b)
{
	return (a.val != b.val) ? (a.val < b.val) : (a.sz < b.sz);
}
inline segment operator + (const segment & a, const segment & b)
{
	return {a.val + b.val, a.sz + b.sz};
}
struct node
{
	segment pref, suf, mx, sum;
} st[MAX * 4];
inline void build(const int p, const int l, const int r)
{
	if (l == r)
	{
		node & ans = st[p];
		ans.pref = ans.suf = ans.mx = ans.sum = {arr[l], 1};
		return;
	}
	build(left(p), l, avg(l, r));
	build(right(p), avg(l, r) + 1, r);
	const node & lft = st[left(p)];
	const node & rght = st[right(p)];
	node & ans = st[p];
	ans.sum = lft.sum + rght.sum;
	ans.pref = max(lft.pref, lft.sum + rght.pref);
	ans.suf = max(rght.suf, rght.sum + lft.suf);
	ans.mx = max(max(lft.mx, rght.mx), lft.suf + rght.pref);
}
inline node rsq(const int p, const int l, const int r)
{
	if (l > j || r < i)
	{
		node ans;
		ans.pref = ans.suf = ans.mx = ans.sum = {-INF, 0};
		return ans;
	}
	if (l >= i && r <= j)
		return st[p];
	const node lft = rsq(left(p), l, avg(l, r)),
			rght = rsq(right(p), avg(l, r) + 1, r);
	node ans;
	if (lft.sum.sz == 0)
		return rght;
	if (rght.sum.sz == 0)
		return lft;

	ans.sum = lft.sum + rght.sum;
	ans.pref = max(lft.pref, lft.sum + rght.pref);
	ans.suf = max(rght.suf, rght.sum + lft.suf);
	ans.mx = max(max(lft.mx, rght.mx), lft.suf + rght.pref);
	return ans;
}
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);

	build(1, 0, n - 1);
	int q; scanf("%d", &q);
	while(q--)
	{
		scanf("%d%d", &i, &j);
		--i, --j;
		const node ans = rsq(1, 0, n - 1);
		printf("%d %d\n", ans.mx.val, ans.mx.sz);
	}
	return 0;
}
