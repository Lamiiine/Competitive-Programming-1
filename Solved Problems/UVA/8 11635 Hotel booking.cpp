#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
int n, m, h;
int c[103];
int head[10010], to[200100], nxt[200100], cost[200100], en;
int distance[103][10010];
bool in_que[10010];
inline void spfa(const int source_index)
{
	int * dist = ::distance[source_index];
	const int s = c[source_index];

	memset(dist, 0x3F, sizeof ::distance[source_index]);
	memset(in_que, 0, sizeof in_que);
	dist[s] = 0;
	in_que[s] = 1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		const int i = q.front();
		const int cur_dist = dist[i];
		q.pop();
		in_que[i] = 0;
		for (int j = head[i]; ~j; j = nxt[j])
		{
			const int k = to[j], c = cost[j];
			if (dist[k] > cur_dist + c)
			{
				dist[k] = cur_dist + c;
				if (!in_que[k])
				{
					q.push(k);
					in_que[k] = 1;
				}
			}
		}
	}
}
inline void add_edge(const int x, const int y, const int t)
{
	nxt[en] = head[x];
	head[x] = en;
	to[en] = y;
	cost[en] = t;
	++en;
}
inline void add_bi_edge(const int x, const int y, const int t)
{
	add_edge(x, y, t);
	add_edge(y, x, t);
}
inline void read(void)
{
	scanf("%d", &h);
	c[0] = 1;
	for (int x, i = 1; i <= h; ++i)
	{
		scanf("%d", &x);
		c[i] = x;
	}
	sort(c, c + h + 1);
	scanf("%d", &m);
	for (int x, y, t, i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &x, &y, &t);
		add_bi_edge(x, y, t);
	}
}
inline void init(void)
{
	memset(head, -1, sizeof head);
	en = 0;
}
int d[103][103];
const int INF = 1000000000;
inline void floyd_warshall(void)
{
	c[++h] = n;
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j <= h; ++j)
		{
			d[i][j] = ::distance[i][c[j]] <= 600 ? 1 : INF;
		}
	}

	for (int k = 0; k <= h; ++k)
	{
		for (int i = 0; i <= h; ++i)
		{
			for (int j = 0; j <= h; ++j)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}
int main(void)
{
	while(scanf("%d", &n), n)
	{
		init();
		read();
		for (int i = 0; i <= h; ++i)
		{
			spfa(i);
		}
		floyd_warshall();

		printf("%d\n", d[0][h] == INF ? -1 : d[0][h] - 1);
	}
	return 0;
}

