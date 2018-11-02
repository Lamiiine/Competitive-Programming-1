#include <bits/stdc++.h>
#define MAX_V 100010
#define MAX_E 300010
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
enum color : char {white = 0, gray, black} vis[MAX_V];

vector<ii> comp[MAX_V];	// cost, node
int head[MAX_V], cost[MAX_V], nxt[MAX_E], to[MAX_E], en;
int dfs_num[MAX_V], dfs_low[MAX_V], dfs_count;
int n, m;

inline void init()
{
	memset(head, -1, sizeof head); en = 0;
	memset(vis, 0, sizeof vis);
	dfs_count = 0;
}
inline void add_edge(const int i, const int j)
{
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	++en;
}
inline void read(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", cost + i);
	}
	scanf("%d", &m);
	for (int x, y, i = 0; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		--x; --y;
		add_edge(x, y);
	}
}
vector<int> dfs_v;
inline void dfs(const int i)
{
	dfs_v.push_back(i);
	dfs_num[i] = dfs_low[i] = dfs_count++;
	vis[i] = gray;
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int t = to[j];
		if (vis[t] == white) dfs(t);
		if (vis[t] == gray) dfs_low[i] = min(dfs_low[i], dfs_low[t]);
	}
	if (dfs_low[i] == dfs_num[i])
	{
		vector<ii> & v = comp[i];
		for(int j = -1; j != i;)
		{
			j = dfs_v.back(); dfs_v.pop_back();
			v.push_back(ii(cost[j], j));
			vis[j] = black;
		}
	}
}
int main()
{
	init();
	read();
	for (int i = 0; i < n; ++i)
	{
		if (!vis[i])
		{
			dfs(i);
		}
	}
	ll ans = 0LL;
	ll count = 1LL;
	for (int i = 0; i < n; ++i)
	{
		vector<ii> & v = comp[i];
		if (v.size())
		{
			const ll comp_cost = min_element(v.begin(), v.end())->first;
			ans += comp_cost;
			ll cur_count = 0;
			for (const ii & neighbor : v)
			{
				if (neighbor.first == comp_cost)
				{
					++cur_count;
				}
			}
			count = (count * cur_count) % MOD;
		}
	}
	cout << ans << " " << count;
}
/*
3
1 2 3
3
1 2
2 3
3 2

5
2 8 0 6 0
6
1 4
1 3
2 4
3 4
4 5
5 1


10
1 3 2 2 1 3 1 4 10 10
12
1 2
2 3
3 1
3 4
4 5
5 6
5 7
6 4
7 3
8 9
9 10
10 9

2
7 91
2
1 2
2 1
 */
