#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define OO 0x3F3F3F3F
#define MAX 102
using namespace std;

int adj[MAX][MAX];
int n, e, t, m;
int dist[MAX], vis[MAX] = { 0 }, vis_id;

inline void init(void)
{
	memset(adj, 0x3F, sizeof adj);
	memset(dist, 0x3F, sizeof dist);
	++vis_id;
}
inline void read(void)
{
	scanf("%d%d%d%d", &n, &e, &t, &m);
	for (int a, b, c, i = 0; i < m; ++i)
		scanf("%d%d%d", &a, &b, &c), adj[b][a] = min(adj[b][a], c);
}
inline void dij(int src)
{
	dist[src] = 0;
	for (int iter = 0; iter < n; ++iter)
	{
		// mark this node as processed
		vis[src] = vis_id;
		// relax
		for (int i = 1; i <= n; ++i)
			dist[i] = min(dist[i], dist[src] + adj[src][i]);
		// select the closest unrpocessed node
		int min_dist = OO;
		for (int i = 1; i <= n; ++i)
			// if not yet processed and has a smaller distance,
			// it's the one we are after
		if (vis[i] != vis_id && dist[i] < min_dist)
			min_dist = dist[src = i];
	}
}
inline int solve(void)
{
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		ans += (dist[i] <= t);
	return ans;
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	int TC; scanf("%d", &TC);
	while (TC--)
	{
		init();
		read();
		dij(e);
		printf("%d\n", solve());
		if (TC) printf("\n");
	}
	return 0;
}