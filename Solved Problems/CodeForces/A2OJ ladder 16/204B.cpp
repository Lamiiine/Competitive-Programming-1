#include <bits/stdc++.h>
#define MAX 100005
#define OO 100000000
using namespace std;
map<int, int> ups;
map<int, int> downs;
map<int, int> repitions;
int n, half;
inline void increment(map<int, int> & m, const int v)
{
	if (m.find(v) == m.end())
	{
		m[v] = 1;
	}
	else
	{
		m[v]++;
	}
}
inline int get_count(map<int, int> & m, const int v)
{
	if (m.find(v) == m.end()) return 0;
	return m[v];
}
inline int solve_for_color(const int v)
{
	const int count_ups = get_count(ups, v),
			count_downs = get_count(downs, v),
			count_repitions = get_count(repitions, v);
	if (count_ups >= half) return 0;
	if (count_ups + count_downs - count_repitions < half)
		return OO;
	return half - count_ups;
}
inline int solve_for_map(const map<int, int> & m)
{
	int ans = OO;
	for (auto iter : m)
	{
		ans = min(ans, solve_for_color(iter.first));
	}
	return ans;
}
inline int solve()
{
	return min(solve_for_map(ups), solve_for_map(downs));
}
inline void read()
{
	scanf("%d", &n);
	half = (n >> 1) + (n & 1);
	for (int i = 0, x, y; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		increment(ups, x);
		increment(downs, y);
		if (x == y)
			increment(repitions, x);
	}
}
int main()
{
	read();
	const int ans = solve();
	printf("%d", ans == OO ? -1 : ans);
	return 0;
}
/*
3
4 7
4 7
7 4

5
4 7
7 4
2 11
9 7
1 1
 */

