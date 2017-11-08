#include<bits/stdc++.h>
#define C (1 << 7)
#define MAX 210
#define S 209
#define T 208
#define v(i) (i)
#define u(i) (i + 102)
#define MAX_E MAX * MAX
using namespace std;

// graph representation
int head[MAX], from[MAX_E], to[MAX_E], nxt[MAX_E], cst[MAX_E], cap[MAX_E], en;
inline void add_edge(const int f, const int t, const int capacity, const int cost)
{
	to[en] = t;
	from[en] = f;
	cap[en] = capacity;
	cst[en] = cost;
	nxt[en] = head[f];
	head[f] = en++;
}
inline void add_bi_edge(const int f, const int t, const int capacity, const int cost)
{
	add_edge(f, t, capacity, cost);
	add_edge(t, f, 0, -cost);
}

int n;

// minimum cost maximum flow
int dist[MAX], flow[MAX], p[MAX], in_q[MAX] = { 0 }, in_q_id = 0;
int min_cost, max_flow;
inline int bellman()
{
	memset(dist, 0x3F, sizeof dist);
	memset(flow, 0, sizeof flow);
	queue<int> q;
	in_q[S] = ++in_q_id;
	dist[S] = 0;
	flow[S] = 100000000;
	q.push(S);
	p[S] = -1;
	for (int iter = 0; iter < (n << 1) + 2; ++iter)
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
						q.push(k);
						in_q[k] = in_q_id;
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
inline void min_cost_max_flow()
{
	while(bellman())
	{
		max_flow += flow[T];
		min_cost += flow[T] * dist[T];
	}
}

// initialization and reading
string line;
int eleg[C][C];
bool adj[C][C];
inline void init(void)
{
	memset(eleg, 0x3F, sizeof eleg);
	memset(adj, 0, sizeof adj);

	memset(head, -1, sizeof head); en = 0;
	min_cost = max_flow = 0;
}
inline void read(void)
{
	getline(cin, line);	// S
	for (int i = 0; i < line.length() - 1; ++i)
	{
		const char a = line[i], b = line[i + 1];
		adj[a][b] = true;	// you can go from a to b!
		eleg[a][b] = min(eleg[a][b], (i + 1) * (i + 1));
	}
	getline(cin, line);	// T
	n = line.length();
	for (int i = 0; i < n; ++i)
	{
		const char a = line[i];
		for (int j = i + 1; j < n; ++j)
		{
			const char b = line[j];
			if (adj[a][b])
			{
				add_bi_edge(u(i), v(j), 1, eleg[a][b]);
			}
		}
	}
}
inline void construct_graph()
{
	for (int i = 0; i < n; ++i)
	{
		add_bi_edge(S, u(i), 1, 0);
		add_bi_edge(v(i), T, 1, 0);
	}
}
int main(void)
{
	int TC; scanf("%d", &TC); getline(cin, line);
	while(TC--)
	{
		init();
		read();
		construct_graph();
		min_cost_max_flow();
		printf("%d %d\n", n - max_flow, min_cost);
	}
	return 0;
}

