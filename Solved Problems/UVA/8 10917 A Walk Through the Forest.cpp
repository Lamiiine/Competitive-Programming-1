#include<bits/stdc++.h>
#define MAX 1024
#define office 1
#define house 2
using namespace std;
typedef pair<int, int> ii;
int head[MAX], to[MAX * MAX * 2], nxt[MAX * MAX * 2], cost[MAX * MAX * 2], en;
int dist[MAX];
int memo[MAX];
inline int dp(const int i)
{
	// memory
	int & ret = memo[i];
	if (ret != -1) return ret;
	// base case
	if (i == house) return ret = 1;
	// recursion
	ret = 0;
	for (int j = head[i]; ~j; j = nxt[j])
		if (dist[to[j]] < dist[i])
			ret += dp(to[j]);
	return ret;
}
inline void dij(void)
{
	priority_queue<ii> q;
	dist[house] = 0;
	q.push(ii(0, house));
	while(!q.empty())
	{
		const int i = q.top().second, cur_dist = -q.top().first;
		q.pop();
		if (dist[i] < cur_dist)
			continue;
		for (int j = head[i]; ~j; j = nxt[j])
			if (dist[to[j]] > cur_dist + cost[j])
				q.push(ii(-(dist[to[j]] = cur_dist + cost[j]), to[j]));
	}

}
inline void init(void)
{
	memset(memo, -1, sizeof memo);
	memset(dist, 0x3F, sizeof dist);
	memset(head, -1, sizeof head);
	en = 0;
}
int n, m;
inline void add_edge(const int i, const int j, const int k)
{
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	cost[en] = k;
	++en;
}
inline void add_bi_edge(const int i, const int j, const int k)
{
	add_edge(i, j, k);
	add_edge(j, i, k);
}
inline void read(void)
{
	scanf("%d", &m);
	for (int a, b, d, i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &d);
		add_bi_edge(a, b, d);
	}
}
int main(void)
{
	while(scanf("%d", &n), n)
	{
		init();
		read();
		dij();
		printf("%d\n", dp(office));
	}
	return 0;
}

