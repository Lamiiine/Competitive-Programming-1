#include<bits/stdc++.h>
#define MAX 32
#define N 26
using namespace std;
typedef pair<int, int> ii;

int n, m;
int dist[MAX];
bool adj[MAX][MAX];
bool vis[MAX];
inline void bfs(const int s)
{
	queue<int> q;
	q.push(s);
	vis[s] = true;
	dist[s] = 0;
	while(!q.empty())
	{
		const int i = q.front();
		q.pop();
		for (int k = 0; k < n; ++k)
			if (adj[i][k] && !vis[k])
			{
				vis[k] = true;
				q.push(k);
				dist[k] = dist[i] + 1;
			}
	}
}
inline void init(void)
{
	memset(adj, 0, sizeof adj);
}
inline void read(void)
{
	scanf("%d%d", &n, &m);
	for (int a, b, i = 0; i < m; ++i)
		scanf("%d%d", &a, &b), adj[a][b] = adj[b][a] = true;
}
inline int get_diam(const int s)
{
	memset(vis, 0, sizeof vis);
	bfs(s);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, dist[i]);
	return ans;
}
int main(void)
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		init();
		read();
		int ans = INT_MAX;
		for (int i = 0; i < n; ++i)
		{
			ans = min(ans, 2 * get_diam(i));
		}
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (adj[i][j])
				{
					adj[i][j] = adj[j][i] = false;
					adj[i][N] = adj[N][i] = true;
					adj[j][N] = adj[N][j] = true;
					ans = min(ans, (get_diam(N) - 1) * 2 + 1);
					adj[i][j] = adj[j][i] = true;
					adj[i][N] = adj[N][i] = false;
					adj[j][N] = adj[N][j] = false;
				}
		printf("Case #%d:\n%d\n\n", tc, ans);
	}
	return 0;
}

