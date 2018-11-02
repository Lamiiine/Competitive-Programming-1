#include <bits/stdc++.h>
#define MAX_N 17
#define MAX (1 << MAX_N)
#define left(a) ((a) << 1)
#define right(a) (left(a) + 1)
#define avg(a, b) (((a) + (b)) >> 1)
using namespace std;
int n, m;
int arr[MAX + 5];
int st[MAX * 4];
int update_idx, update_val;

inline int log_2(int i)
{
	int ans = 0;
	while(i != 1) ++ans, i >>= 1;
	return ans;
}
inline void _update(const int p, const int l, const int r)
{
	if (log_2(r - l + 1) & 1)
	{
		st[p] = st[left(p)] | st[right(p)];
	}
	else
	{
		st[p] = st[left(p)] ^ st[right(p)];
	}
}
inline void build(const int p, const int l, const int r)
{
	if (l == r)
	{
		st[p] = arr[l];
	}
	else
	{
		build(left(p), l, avg(l, r));
		build(right(p), avg(l, r) + 1, r);
		_update(p, l, r);
	}
}
inline void update(const int p, const int l, const int r)
{
	if (r < update_idx || l > update_idx)
	{
		return;
	}
	else if (l == r)
	{
		st[p] = update_val;
	}
	else
	{
		update(left(p), l, avg(l, r));
		update(right(p), avg(l, r) + 1, r);
		_update(p, l, r);
	}
}
inline void read()
{
	scanf("%d%d", &n, &m);
	n = 1 << n;
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
		scanf("%d%d", &update_idx, &update_val);
		--update_idx;
		update(1, 0, n - 1);
		printf("%d\n", st[1]);
	}
}
/*
2 4
1 6 3 5
1 4
3 4
1 2
1 2
 */

