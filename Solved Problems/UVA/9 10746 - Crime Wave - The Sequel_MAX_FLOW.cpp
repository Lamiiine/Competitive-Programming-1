#include<bits/stdc++.h>
#define MAX 50
#define S 49
#define T 48
#define v(a) (a)
#define u(a) (a + 22)
#define MAX_E (MAX * MAX * 2)
#define inf 1e9
#define eps 1e-9
using namespace std;

// graph representation
int head[MAX], to[MAX_E], from[MAX_E], nxt[MAX_E], cap[MAX_E], en; double cst[MAX_E];
inline void add_edge(const int f, const int t, const int capacity, const double cost)
{
	to[en] = t;
	from[en] = f;
	cst[en] = cost;
	cap[en] = capacity;
	nxt[en] = head[f];
	head[f] = en++;
}
inline void add_bi_edge(const int f, const int t, const int capacity, const double cost)
{
	add_edge(f, t, capacity, cost);
	add_edge(t, f, 0, -cost);
}

// min cost max flow
int n, m;
double dist[MAX];
int flow[MAX], p[MAX], in_q[MAX] = { 0 }, in_q_id = 0;
int bellman()
{
	for (int i = 0; i < MAX; ++i)
		dist[i] = inf;
	memset(flow, 0, sizeof flow);
	queue<int> q;
	in_q[S] = ++in_q_id;
	dist[S] = 0.0;
	flow[S] = 1000000;
	q.push(S);
	p[S] = -1;
	for (int iter = 0; iter < (n + m + 2); ++iter)
	{
		int sz = q.size();
		while(sz--)
		{
			const int i = q.front(); q.pop();
			in_q[i] = 0;
			for (int j = head[i]; ~j; j = nxt[j])
			{
				const int k = to[j];
				if (cap[j] && dist[k] > dist[i] + cst[j])
				{
					dist[k] = dist[i] + cst[j];
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
inline double min_cost_max_flow()
{
	// return minimum cost
	double cst = 0.0;
	int max_flow = 0;
	while(bellman())
	{
		cst += dist[T] * flow[T];
		max_flow += flow[T];
	}
	return cst;
}
// reading and initialization
inline void init()
{
	memset(head, -1, sizeof head);
	en = 0;
}
inline void read(void)
{
	/* u is the set of banks
	 * v is the set of cruisers
	 * */
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			double cost; scanf("%lf", &cost);
			add_bi_edge(u(i), v(j), 1, cost);
		}
}
inline void construct_graph(void)
{
	for (int i = 0; i < n; ++i)
		add_bi_edge(S, u(i), 1, 0.0);
	for (int j = 0; j < m; ++j)
		add_bi_edge(v(j), T, 1, 0.0);
}

// main function
int main(void)
{
	while(scanf("%d%d", &n, &m), n || m)
	{
		init();
		read();
		construct_graph();
		printf("%.2lf\n", min_cost_max_flow() / n + eps);
	}
	return 0;
}
/*
3 4
10.0 23.0 30.0 40.0
5.0 20.0 10.0 60.0
18.0 20.0 20.0 30.0
0 0
 */

