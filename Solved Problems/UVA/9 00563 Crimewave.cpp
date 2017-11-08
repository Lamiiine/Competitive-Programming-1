#include<bits/stdc++.h>
#define MAX 5050
#define S 5049
#define T 5048
#define idx(a, b) ((a) * m + (b))
#define in(i) (i)
#define out(i) (i + 2510)
#define MAX_E (MAX * 8)
using namespace std;
int n, m;	// number of rows and columns
int b;		// number of banks to be robbed

// graph representation
int head[MAX], to[MAX_E], from[MAX_E], nxt[MAX_E], cap[MAX_E], en;
inline void add_edge(const int f, const int t, const int c)
{
	to[en] = t;
	from[en] = f;
	cap[en] = c;
	nxt[en] = head[f];
	head[f] = en++;
}
inline void add_bi_edge(const int f, const int t, const int c)
{
	add_edge(f, t, c);
	add_edge(t, f, 0);
}

// maximum flow
typedef pair<int, int> ii;
int p[MAX], vis[MAX] = { 0 }, vis_id;
inline int bfs()
{
	++vis_id;
	queue<ii> q;
	q.push(ii(S, 100000000));
	vis[S] = vis_id;
	while(!q.empty())
	{
		const int i = q.front().first, f = q.front().second; q.pop();
		for (int j = head[i]; ~j; j = nxt[j])
			if (cap[j])
			{
				const int k = to[j];
				if (vis[k] != vis_id)
				{
					vis[k] = vis_id;
					p[k] = j;
					q.push(ii(k, min(f, cap[j])));
				}
				if (k == T)
				{
					// found a path
					const int flow = q.back().second;
					for (int v = T, j; v != S; v = from[p[v]])
					{
						j = p[v];
						cap[j] -= flow;
						cap[j ^ 1] += flow;
					}

					return flow;
				}
			}
	}

	return 0;
}
inline int max_flow()
{
	int ans = 0, x;
	while(x = bfs())
		ans += x;
	return ans;
}


// reading and initialization
inline void init()
{
	memset(head, -1, sizeof head); en = 0;
}
const int di[4] = {1, -1, 0, 0},
		dj[4] = {0, 0, 1, -1};
inline void read()
{
	scanf("%d%d%d", &n, &m, &b);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			const int node = idx(i, j);
			add_bi_edge(in(node), out(node), 1);
			for (int k = 0; k < 4; ++k)
			{
				const int x = i + di[k], y = j + dj[k];
				if (x >= 0 && x < n && y >= 0 && y < n)
				{
					add_bi_edge(out(node), in(idx(x, y)), 1);
				}
			}
		}

	// set edges from source!
	for (int i = 0, x, y; i < b; ++i)
	{
		scanf("%d%d", &x, &y); --x; --y;
		add_bi_edge(S, in(idx(x, y)), 1);
	}

	// set edges to destination
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
			{
				const int node = idx(i, j);
				add_bi_edge(out(node), T, 1);
			}
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		printf("%spossible\n", max_flow() == b ? "" : "not ");
	}
	return 0;
}
/*
2
6 6 10
4 1
3 2
4 2
5 2
3 4
4 4
5 4
3 6
4 6
5 6
5 5 5
3 2
2 3
3 3
4 3
3 4
 */

