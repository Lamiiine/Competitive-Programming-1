#include<bits/stdc++.h>
#define MAX 105
#define request(i) ((i))
#define served_request(i) ((i) + MAX)
#define headquarters (MAX * 2)
#define S (headquarters + 1)
#define T (S + 1)
#define MAX_V (T + 1)
#define MAX_E 25000
#define OO 10000
using namespace std;
// my data
int n, k;
// 0. graph representation
int head[MAX_V], nxt[MAX_E], to[MAX_E], from[MAX_E], cap[MAX_E], cost[MAX_E], en;
inline void graph_init()
{
	memset(head, -1, sizeof head);
	en = 0;
}
inline void add_edge(const int f, const int t, const int cp, const int cst) {
	from[en] = f;
	to[en] = t;
	cap[en] = cp;
	cost[en] = cst;
	nxt[en] = head[f];
	head[f] = en;
	++en;
}
inline void add_bi_edge(const int f, const int t, const int cp, const int cst) {
	add_edge(f, t, cp, cst);
	add_edge(t, f, 0, -cst);
}

// 1. minimum-cost maximum flow
int flow[MAX_V], dist[MAX_V], p[MAX_V], in_q[MAX_V] = { 0 }, in_q_id = 0;
int bellman() {
	// return current flow
	memset(dist, 0x3F, sizeof dist);
	memset(flow, 0, sizeof flow);
	queue<int> q;
	in_q[S] = ++in_q_id;
	dist[S] = 0;
	flow[S] = OO;
	q.push(S);
	p[S] = -1;
	for (int iter = 0; iter < n * 2 + 3; ++iter)
	{
		int sz = q.size();
		while (sz--)
		{
			const int i = q.front();
			q.pop();
			in_q[i] = 0;
			for (int j = head[i]; ~j; j = nxt[j])
			{
				const int k = to[j];
				if (cap[j] && dist[k] > dist[i] + cost[j])
				{
					dist[k] = dist[i] + cost[j];
					p[k] = j;
					flow[k] = min(flow[i], cap[j]);
					if (in_q[k] != in_q_id)
					{
						in_q[k] = in_q_id;
						q.push(k);
					}
				}
			}
		}
	}
	if (q.empty())
	{
		if (flow[T])
		{
			for (int i = T; i != S; i = from[p[i]])
			{
				const int j = p[i];
				cap[j] -= flow[T];
				cap[j ^ 1] += flow[T];
			}
		}
		return flow[T];
	}
	return 0;
}
int min_cost, max_flow;
inline void min_cost_max_flow() {
	min_cost = max_flow = 0;
	while (bellman())
	{
		max_flow += flow[T];
		min_cost += dist[T] * flow[T];
	}
}

int grid[MAX][MAX];
int main()
{
	while (~scanf("%d%d", &n, &k))
	{
		// headquarters is #0, and request locations are numbered 1 through n
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				scanf("%d", grid[i] + j);
				grid[j][i] = grid[i][j];
			}
		}

		graph_init();
		// from source to request
		for (int i = 0; i < n; ++i)
		{
			add_bi_edge(S, request(i), 1, 0);
		}
		// from request to headquarters
		for (int i = 0; i < n; ++i)
		{
			add_bi_edge(request(i), headquarters, 1, grid[0][i + 1]);
		}
		// from request to request
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				add_bi_edge(request(i), served_request(j), 1, grid[i + 1][j + 1]);
			}
		}
		// from headquarters to destination
		add_bi_edge(headquarters, T, k, 0);
		// from served request to destination
		for (int i = 0; i < n; ++i)
		{
			add_bi_edge(served_request(i), T, 1, 0);
		}
		min_cost_max_flow();
		printf("%d\n", min_cost);
	}
	return 0;
}
/*
3 2
40 30 40
50 10
50
3 2
10 10 10
20 21
21
 */

