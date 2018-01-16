#include<bits/stdc++.h>
#define MAX 105
using namespace std;
int n, m;
int adj[MAX][MAX];
enum color : char {white = 0, gray, black} vis[MAX];
inline void read()
{
	for (int i, j, k = 0; k < m; ++k)
		scanf("%d%d", &i, &j), adj[i][j] = true;
}
int p[MAX];
inline int get_p(const int i)
{
	return p[i] == i ? i : p[i] = get_p(p[i]);
}
inline void unite(const int i, const int j)
{
	p[get_p(j)] = get_p(i);
}
int dfs_num[MAX], dfs_low[MAX], dfs_count;
vector<int> dfs_v;
inline void dfs(const int i)
{
	dfs_v.push_back(i);
	dfs_num[i] = dfs_low[i] = dfs_count++;
	vis[i] = gray;
	for (int j = 1; j <= n; ++j)
		if (adj[i][j])
		{
			if (!vis[j]) dfs(j);
			if (vis[j] == gray) dfs_low[i] = min(dfs_low[i], dfs_low[j]);
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
bool ex[MAX][MAX];	// explicit reductions
bool im[MAX][MAX];	// implicit reductions
int sz[MAX];
inline void init(void)
{
	memset(adj, 0, sizeof adj);
	memset(vis, 0, sizeof vis);
	memset(ex, 0, sizeof ex);
	memset(im, 0, sizeof im);
	memset(sz, 0, sizeof sz);
	dfs_count = 0;
	for (int i = 0; i < MAX; ++i)
		p[i] = i;
}
inline void construct_comp(void)
{
	for (int i = 1; i <= n; ++i)
		++sz[get_p(i)];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (adj[i][j])
			{
				const int I = get_p(i), J = get_p(j);
				if (I != J)
					ex[I][J] = true;
			}
}
inline void floyd_warshall(void)
{
	memcpy(im, ex, sizeof im);
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
					im[i][j] |= (im[i][k] & im[k][j]);
}
inline void reduce(void)
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (ex[i][j])
				for (int k = 1; k <= n; ++k)
					if (im[j][k])
						ex[i][k] = false;
}
int main(void)
{
	for(int tc = 1; scanf("%d%d", &n, &m), n || m; ++tc)
	{
		// initialize global variables
		init();
		// read input
		read();
		// split components into disjoint sets!
		for (int i = 1; i <= n; ++i)
			if (!vis[i]) dfs(i);
		// store all explicit edges in ex[][]
		construct_comp();
		// store explicit as well as implicit edges in im[][]
		floyd_warshall();
		// reduce the number of explicit edges (twice)!
		reduce();
		reduce();
		int ans = 0;
		// every non-singleton component must have a cycle
		for (int i = 1; i <= n; ++i)
			if (sz[i] != 1)
				ans += sz[i];
		// store the remaining explicit edges, which have no implicit edges
		for (int i = 1; i <= n; ++i)
				for (int j = 1; j <= n; ++j)
						ans += ex[i][j];
		printf("Case %d: %d\n", tc, ans);
	}
	return 0;
}

