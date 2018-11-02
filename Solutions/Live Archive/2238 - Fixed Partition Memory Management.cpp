#include<bits/stdc++.h>
#define MAX_P 55
#define MAX_R 12
#define MAX_V 600
#define MAX_E 30000
#define S (MAX_V - 1)
#define T (MAX_V - 2)
#define OO 1000000000
#define program(i) (i)
#define region(i, j) (MAX_P + (i) * MAX_P + (j))
using namespace std;
typedef pair<int, int> ii;

vector<ii> region_allocation[MAX_R];
int program_region_cost[MAX_P][MAX_R];
int m;	// number of memory regions
int n;	// number of programs

int reg_size[MAX_R];
int head[MAX_V], to[MAX_E * 2], from[MAX_E * 2], nxt[MAX_E * 2], cap[MAX_E * 2], cost[MAX_E * 2], en = 0;
inline void add_edge(const int f, const int t, const int cp, const int cs)
{
	nxt[en] = head[f];
	from[en] = f;
	to[en] = t;
	cost[en] = cs;
	cap[en] = cp;
	head[f] = en;
	++en;
}
inline void add_bi_edge(const int f, const int t, const int cp, const int cs)
{
	add_edge(f, t, cp, cs);
	add_edge(t, f, 0, -cs);
}
inline void init()
{
	en = 0;
	memset(head, -1, sizeof head);
	for (int i = 0; i < MAX_R; ++i)
	{
		region_allocation[i].clear();
	}
}
inline int get_cost(const vector<ii> & space_time, const int sz)
{
	for (int i = 0; i < space_time.size() - 1; ++i)
	{
		if (sz >= space_time[i].first && sz < space_time[i + 1].first)
		{
			return space_time[i].second;
		}
	}
	return space_time.back().second;
}
inline void read()
{
	// read regions data
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", reg_size + i);
	}

	// for each memory region
	for (int i = 0; i < m; ++i)
	{
		// for each order
		for (int j = 0; j < n; ++j)
		{
			add_bi_edge(region(i, j), T, 1, 0);
		}
	}

	// read programs data
	for (int i = 0; i < n; ++i)
	{
		add_bi_edge(S, program(i), 1, 0);
		int k;
		scanf("%d", &k);
		vector<ii> temp;
		for (int s, t; k--; )
		{
			scanf("%d%d", &s, &t);
			temp.push_back(ii(s, t));
		}

		// for each region
		for (int j = 0; j < m; ++j)
		{
			if (temp[0].first > reg_size[j])
				continue;
			program_region_cost[i][j] = get_cost(temp, reg_size[j]);
			// for each order
			for (int k = 0; k < n; ++k)
			{
				add_bi_edge(program(i), region(j, k), 1, program_region_cost[i][j] * (k + 1));
			}
		}
	}
}
int dist[MAX_V], flow[MAX_V], p[MAX_V], in_q[MAX_V] = { 0 }, in_q_id = 0;
inline int bellman()
{
	for (int i = 0; i < MAX_V; ++i)
		dist[i] = OO;
	memset(flow, 0, sizeof flow);
	queue<int> q;
	in_q[S] = ++in_q_id;
	dist[S] = 0;
	flow[S] = OO;
	q.push(S);
	p[S] = -1;
	for (int iter = 0; iter < n * (m + 1) + 2; ++iter)
	{
		int sz = q.size();
		while(sz--)
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
inline int min_cost_max_flow()
{
	int cst = 0;
	while(bellman())
	{
		cst += dist[T] * flow[T];
	}

	return cst;
}

int region[MAX_P], start_time[MAX_P];
inline void compute()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = head[i]; ; j = nxt[j])
		{
			if (cap[j] == 0)
			{
				int x = to[j] - MAX_P;
				region_allocation[region[i] = x / MAX_P].push_back(ii(x % MAX_P, i));
				break;
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		sort(region_allocation[i].begin(), region_allocation[i].end());
		reverse(region_allocation[i].begin(), region_allocation[i].end());
		for (int tot = 0, j = 0; j < region_allocation[i].size(); ++j)
		{
			start_time[region_allocation[i][j].second] = tot;
			tot += program_region_cost[region_allocation[i][j].second][i];
		}
	}
}
int main()
{
	for (int tc = 1; scanf("%d%d", &m, &n), m || n; ++tc)
	{
		init();
		read();
		min_cost_max_flow();
		compute();
		int tot = 0;
		for (int i = 0; i < n; ++i)
			tot += start_time[i] + program_region_cost[i][region[i]];
		printf("Case %d\n", tc);
		printf("Average turnaround time = %.2lf\n", (double) tot / (double) n);
		for (int i = 0; i < n; ++i)
		{
			printf("Program %d runs in region %d from %d to %d\n", i + 1, region[i] + 1, start_time[i], start_time[i] + program_region_cost[i][region[i]]);
		}
		printf("\n");
	}

	return 0;
}

