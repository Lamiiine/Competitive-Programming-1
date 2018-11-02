#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef pair<int, int> ii;
int n, m, s, l;
int head[MAX], nxt[MAX * 2], to[MAX * 2], cost[MAX * 2], en = 0;
int dist[MAX];
bool vis[MAX];
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
inline void init()
{
	memset(head, -1, sizeof head);
	memset(dist, 0x3F, sizeof dist);
}
inline void read()
{
	cin >> n >> m >> s;
	for (int i = 0, u, v, w; i < m; ++i)
	{
		cin >> u >> v >> w;
		add_bi_edge(u, v, w);
	}
	cin >> l;
}
inline void dij()
{
	priority_queue<ii> q;
	dist[s] = 0;
	q.push(ii(0, s));
	while (!q.empty())
	{
		const int cur_dist = -q.top().first, v = q.top().second;
		q.pop();
		if (dist[v] < cur_dist)
		{
			continue;
		}
		for (int j = head[v]; ~j; j = nxt[j])
		{
			const int t = to[j], cst = cost[j];
			if (dist[t] > cst + cur_dist)
			{
				q.push(ii(-(dist[t] = cst + cur_dist), t));
			}
		}
	}
}
inline int solve()
{
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		const int cur_dist = dist[i];
		if (cur_dist == l)
		{
			++ans;
		}
		for (int j = head[i]; ~j; j = nxt[j])
		{
			if (j & 1) continue;	// We wish to consider every edge only once!!
			const int t = to[j], cst = cost[j];
			const int nxt_dist = dist[t];
			// Is there a point on edge j that is l away from s?
			// In other words, is there an x satisfying the following:
			// min(cur_dist + x, nxt_dist + cst - x) == l && x != 0 && x != cst ??
			// The answer is, solve for x!!
			set<int> u;
			int distance_from_v[2] = { l - cur_dist, cst - (l - nxt_dist)};
			for (int x : distance_from_v)
			{
				if (x > 0 && x < cst && min(cur_dist + x, nxt_dist + cst - x) == l)
					u.insert(x);
			}
			ans += u.size();
		}
	}
	return ans;
}

int main()
{
	init();
	read();
	dij();
	printf("%d", solve());
	return 0;
}
/*
4 6 1
1 2 1
1 3 3
2 3 1
2 4 1
3 4 1
1 4 2
2

5 6 3
3 1 1
3 2 1
3 4 1
3 5 1
1 2 6
4 5 8
4
 */

