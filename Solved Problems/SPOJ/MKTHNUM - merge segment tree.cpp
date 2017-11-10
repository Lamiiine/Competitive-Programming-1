#include <bits/stdc++.h>
#define MAX 100005
#define OO 1000000000
#define left(s) ((s) << 1)
#define right(s) (left(s) + 1)
#define avg(a, b) (((a) + (b)) >> 1)
using namespace std;
int n, m;
vector<int> st[MAX * 4];	// each node is a vector!
int arr[MAX];
inline void build(const int p, const int l, const int r)
{
	if (l == r)
	{
		st[p].push_back(arr[l]);
	}
	else
	{
		build(left(p), l, avg(l, r));
		build(right(p), avg(l, r) + 1, r);
		const vector<int> & a = st[left(p)];
		const vector<int> & b = st[right(p)];
		vector<int> & cur = st[p];
		int i = 0, j = 0;
		while (i < a.size() && j < b.size())
		{
			if (a[i] < b[j])
			{
				cur.push_back(a[i++]);
			}
			else
			{
				cur.push_back(b[j++]);
			}
		}
		while (i < a.size())
		{
			cur.push_back(a[i++]);
		}
		while (j < b.size())
		{
			cur.push_back(b[j++]);
		}
	}
}
int i, j, k, val;
inline int query(const int p, const int l, const int r)
{
	/*
	 * Return the number of elements in this interval that is less than or equal to val!
	 */
	if (l > j || r < i) return 0;
	if (l >= i && r <= j) return upper_bound(st[p].begin(), st[p].end(), val) - st[p].begin();
	return query(left(p), l, avg(l, r)) + query(right(p), avg(l, r) + 1, r);
}
inline int solve()
{
	int lo = -OO, hi = OO;
	while (lo != hi)
	{
		val = avg(lo, hi);
		const int cur = query(1, 0, n - 1);
		if (cur < k)
		{
			lo = val + 1;
		}
		else
		{
			hi = val;
		}
	}
	return lo;
}
inline void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
	}
}
int main()
{
	read();
	build(1, 0, n - 1);
	while(m--)
	{
		scanf("%d%d%d", &i, &j, &k); --i; --j;
		printf("%d\n", solve());
	}
	return 0;
}

