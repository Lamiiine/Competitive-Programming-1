#include<bits/stdc++.h>
#define MAX 100100
#define S 10
#define INF 1000000000
using namespace std;
typedef pair<int, int> ii;
int head[MAX], to[MAX * 2], nxt[MAX * 2], cost[MAX * 2], en;
vector<int> stores;
int memo[S][1 << S];
int dist[S + 1][MAX];
int n, m;
bool in_que[MAX];
// source number and corresponding distance array!
inline void dij(const int s, int * distance)
{
	memset(in_que, 0, sizeof in_que);
	distance[s] = 0;
	queue<int> q;
	q.push(s);
	in_que[s] = 1;
	while(!q.empty())
	{
		const int i = q.front();
		q.pop();
		in_que[i] = 0;
		for (int j = head[i]; ~j; j = nxt[j])
		{
			const int k = to[j], c = cost[j];
			if (distance[i] + c < distance[k])
			{
				distance[k] = distance[i] + c;
				if (!in_que[k])
					q.push(k), in_que[k] = 1;
			}
		}
	}
}
inline void init(void)
{
	en = 0;
	memset(head, -1, sizeof head);
	memset(dist, 0x3F, sizeof dist);
	memset(memo, -1, sizeof memo);
	stores.clear();
}
inline void add_edge(const int x, const int y, const int d)
{
	nxt[en] = head[x];
	head[x] = en;
	to[en] = y;
	cost[en] = d;
	++en;
}
inline void add_bi_edge(const int x, const int y, const int d)
{
	add_edge(x, y, d);
	add_edge(y, x, d);
}
inline void read(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 0, x, y, d; i < m; ++i)
		scanf("%d%d%d", &x, &y, &d), add_bi_edge(x, y, d);
	int t;
	scanf("%d", &t);
	for (int x; t--;)
		scanf("%d", &x), stores.push_back(x);
}
inline void set_dist(void)
{
	dij(0, dist[stores.size()]);
	for (int i = 0; i < stores.size(); ++i)
		dij(stores[i], dist[i]);
}
inline int dp(const int i, const int mask)
{
	// memory
	int & ret = memo[i][mask];
	if (ret != -1)
		return ret;
	// base
	if (mask == (1 << stores.size()) - 1)
		return ret = dist[i][0];
	ret = INF;
	for (int j = 0; j < stores.size(); ++j)
		if (!(mask & (1 << j)))
			ret = min(ret, dist[i][stores[j]] + dp(j, mask | (1 << j)));
	return ret;
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		set_dist();
		int ans = INF;

		for (int i = 0; i < stores.size(); ++i)
			ans = min(ans, dist[stores.size()][stores[i]] + dp(i, 1 << i));
		printf("%d\n", ans);
	}
	return 0;
}

