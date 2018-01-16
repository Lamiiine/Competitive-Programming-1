#include <bits/stdc++.h>
#define MAX_N 152
#define MAX_Q 1005
#define MAX_E 3005
#define OO 1000000000
using namespace std;
int dist[2][MAX_N][MAX_N];
int edge[2][MAX_N][MAX_N];
int from[MAX_E], to[MAX_E], cst[MAX_E];
int n, m, q;
inline void init_dist()
{
	for (int i = 0; i < MAX_N; ++i)
	{
		for (int j = 0; j < MAX_N; ++j)
			dist[0][i][j] = dist[1][i][j] = OO, edge[0][i][j] = edge[1][i][j] = -1;
		dist[0][i][i] = dist[1][i][i] = 0;
	}
}
struct query
{
	int a, b, c, idx;
	inline bool operator < (const query & other) const
	{
		return c < other.c;
	}
} queries[MAX_Q];
int ans[MAX_Q];
int main()
{
	int TC; scanf("%d", &TC);
	while (TC--)
	{
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 0, x, y, z; i < m; ++i)
		{
			scanf("%d%d%d", &x, &y, &z);
			from[i] = x;
			to[i] = y;
			cst[i] = z;
		}
		for (int i = 0, a, b, c; i < q; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			queries[i] = query{a, b, c, i};
		}
		sort(queries, queries + q);
		init_dist();
		int cur = 0, prev = 1, last_q = 0;
		for (int i = 1; i < n; ++i)
		{
			// memcpy(dist[cur], dist[prev], sizeof dist[0]);
			for (int j = 0; j < m; ++j)
			{
				const int f = from[j], t = to[j], c = cst[j];
				for (int u = 1; u <= n; ++u)
				{
					if (dist[prev][u][t] > dist[prev][u][f] + c && c > edge[prev][u][f])
					{
						dist[cur][u][t] = dist[prev][u][f] + c;
						edge[cur][u][t] = c;
					}
				}
				// dist[cur][f][t] = min(dist[prev][f][t], dist[prev][f][t] + c);
			}
			while(queries[last_q].c == i)
			{
				ans[queries[last_q].idx] = dist[cur][queries[last_q].a][queries[last_q].b];
				++last_q;
			}
			swap(cur, prev);
		}
		while(last_q < q)
		{
			ans[queries[last_q].idx] = dist[prev][queries[last_q].a][queries[last_q].b];
			++last_q;
		}
		for (int i = 0; i < q; ++i)
			printf("%d\n", ans[i] == OO ? -1 : ans[i]);
	}
	return 0;
}
/*
1
8 9 3
1 2 1
2 3 2
3 4 3
4 5 12
5 8 7
1 6 8
6 4 9
1 7 5
7 4 4
1 4 2
1 4 3
1 4 1
 */

