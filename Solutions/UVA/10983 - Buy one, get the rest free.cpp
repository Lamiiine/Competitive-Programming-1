#include<bits/stdc++.h>
#define MAX_N 35
#define MAX_D 15
#define MAX_M 3000
#define OO 10000000
#define S 0
using namespace std;
typedef pair<int, int> ii;
int head[MAX_N][MAX_D], nxt[MAX_M], cost[MAX_M], cap[MAX_M], en;
ii to[MAX_M];
int n, d, m;
int work[MAX_M];
int tot_z;
inline void add_edge(const int f_n, const int f_d, const int t_n, const int t_d, const int c, const int p)
{
	nxt[en] = head[f_n][f_d];
	head[f_n][f_d] = en;
	to[en] = ii(t_n, t_d);
	cost[en] = p;
	cap[en] = c;
	++en;
}
inline void add_bi_edge(const int f_n, const int f_d, const int t_n, const int t_d, const int c, const int p)
{
	add_edge(f_n, f_d, t_n, t_d, c, p);
	add_edge(t_n, t_d, f_n, f_d, 0, p);
}
inline void read(void)
{
	scanf("%d%d%d", &n, &d, &m);
	for (int u, v, c, p, e, i = 0; i < m; ++i)
	{
		scanf("%d%d%d%d%d", &u, &v, &c, &p, &e);
		// a trip from city u to city v on day e costing p dollars carrying c passengers
		add_bi_edge(u, e, v, e + 1, c, p);
	}
	tot_z = 0;
	for (int i = 1, z; i <= n; ++i)
	{
		scanf("%d", &z);
		tot_z += z;
		add_bi_edge(S, S, i, 0, z, 0);
	}
}
inline void init(void)
{
	memset(head, -1, sizeof head);
	en = 0;
}
int vis[MAX_N][MAX_D] = { 0 }, vis_id;
int buy;
inline int dfs(const int i, const int j, const int cur_flow)
{
	if (vis[i][j] == vis_id || !cur_flow) return 0;
	vis[i][j] = vis_id;
	if (i == n && j == d)
		return cur_flow;
	for (int k = head[i][j]; ~k; k = nxt[k])
		if (cost[k] <= buy)
		{
			int t = dfs(to[k].first, to[k].second, min(cur_flow, cap[k]));
			if (t)
			{
				cap[k] -= t;
				cap[k ^ 1] += t;
				return t;
			}
		}
	return 0;
}
inline int max_flow()
{
	memcpy(work, cap, sizeof cap);
	int ans = 0;
	while(true)
	{
		++vis_id;
		const int cur = dfs(S, S, OO);
		if (!cur) break;
		ans += cur;
	}
	memcpy(cap, work, sizeof cap);
	return ans;
}
inline int solve(void)
{
	if (n == 1) return 0;
	set<int> s;
	for (int i = 0; i < en; ++i)
		s.insert(cost[i]);
	vector<int> v(s.begin(), s.end());
	int lo = 0, hi = v.size();
	while(lo != hi)
	{
		const int mid = (lo + hi) >> 1;
		buy = v[mid];
		const int cur = max_flow();
		if (cur == tot_z)
			hi = mid;
		else
			lo = mid + 1;
	}
	return lo == v.size() ? OO : v[lo];
}
inline void add_edges(void)
{
	for (int i = 1; i <= n; ++i)
		for (int e = 0; e < d; ++e)
			add_bi_edge(i, e, i, e + 1, OO, 0);
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		init();
		read();
		add_edges();
		const int ans = solve();
		printf("Case #%d: ", tc);
		if (ans == OO) printf("Impossible"); else printf("%d", ans);
		printf("\n");
	}
	return 0;
}

