#include<bits/stdc++.h>
#define MAX 1024
#define MAX_E 50005
using namespace std;
int n, m;
int head[MAX], to[MAX_E], nxt[MAX_E], en;
inline void add_edge(const int i, const int j)
{
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	++en;
}
int memo[MAX];
int p[MAX];
inline int get_p(const int i)
{
	return i == p[i] ? i : p[i] = get_p(p[i]);
}
inline void unite(const int i, const int j)
{
	p[get_p(j)] = get_p(i);
}
enum color: char {white = 0, gray, black} vis[MAX];
int dfs_count, dfs_num[MAX], dfs_low[MAX];
vector<int> dfs_v;
inline void dfs(const int i)
{
	dfs_v.push_back(i);
	dfs_num[i] = dfs_low[i] = dfs_count++;
	vis[i] = gray;
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int k = to[j];
		if (!vis[k]) dfs(k);
		if (vis[k] == gray) dfs_low[i] = min(dfs_low[i], dfs_low[k]);
	}

	if (dfs_low[i] == dfs_num[i])
		for (int j = -1; j != i; )
		{
			j = dfs_v.back();
			dfs_v.pop_back();
			unite(i, j);
			vis[j] = black;
		}
}
vector<int> adj[MAX];	// component adjacency list!
int sz[MAX];
// return the number of nodes on the longest SCC path starting at SCC i
inline int dp(const int i)
{
	int & ret = memo[i];
	if (ret != -1) return ret;
	// base case
	ret = sz[i];
	for (int j = 0; j < adj[i].size(); ++j)
		ret = max(ret, sz[i] + dp(adj[i][j]));
	return ret;
}
inline void init(void)
{
	memset(head, -1, sizeof head);
	memset(memo, -1, sizeof memo);
	en = 0;
	for (int i = 0; i < MAX; ++i)
		adj[i].clear(), p[i] = i;
	memset(sz, 0, sizeof sz);
	memset(vis, 0, sizeof vis);
	dfs_count = 0;
}
inline int solve(void)
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
		if (i == p[i])
			ans = max(ans, dp(i));
	return ans;
}
inline void read(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 0, u, v; i < m; ++i)
	{
		scanf("%d%d", &u, &v);
		--u; --v;
		add_edge(u, v);
	}
}
inline void construct_component_graph(void)
{
	for (int i = 0, I, J; i < n; ++i)
	{
		I = get_p(i);
		++sz[I];
		for (int j = head[i]; ~j; j = nxt[j])
		{
			J = get_p(to[j]);
			// there is and edge from I to J
			if (I != J)
				adj[I].push_back(J);
		}
	}
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		for (int i = 0; i < n; ++i)
			if (!vis[i]) dfs(i);
		construct_component_graph();
		printf("%d\n", solve());
	}
	return 0;
}

