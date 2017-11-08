#include<bits/stdc++.h>
#define MAX 104
#define eps 1e-6
#define X real()
#define Y imag()
#define get_dist(a, b) (hypot((a).X - (b).X, (a).Y - (b).Y))
using namespace std;
typedef complex<int> point;

double mid;
int n;
int l, w;
double dist[MAX][MAX];
point arr[MAX];
int vis[MAX] = { 0 }, vis_id;
inline void bfs()
{
	queue<int> q;
	vis[n] = vis_id;
	q.push(n);
	while(!q.empty())
	{
		const int i = q.front(); q.pop();
		for (int j = 0; j <= n + 1; ++j)
			if (vis[j] != vis_id && dist[i][j] < mid)
				vis[j] = vis_id, q.push(j);
	}
}
inline void init()
{
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			dist[i][j] = dist[j][i] = get_dist(arr[i], arr[j]);
	for (int i = 0; i < n; ++i)
	{
		dist[i][n] = dist[n][i] = arr[i].Y;
		dist[i][n + 1] = dist[n + 1][i] = w - arr[i].Y;
	}
	dist[n][n + 1] = dist[n + 1][n] = w;
}
inline void read(void)
{
	scanf("%d%d", &l, &w);
	scanf("%d", &n);
	for (int i = 0, x, y; i < n; ++i)
	scanf("%d%d", &x, &y), arr[i] = point(x, y);
}
inline double solve()
{
	double lo = 0.0, hi = w;
	while(hi - lo > eps)
	{
		mid = (hi + lo) * 0.5;
		++vis_id; bfs();
		if (vis[n + 1] == vis_id)
			hi = mid;
		else lo = mid;
	}
	return lo;
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		read();
		init();
		printf("Maximum size in test case %d is %.4lf.\n", tc, solve());
	}
	return 0;
}

