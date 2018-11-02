#include <bits/stdc++.h>
#define MAX 300005
using namespace std;
int head[MAX], nxt[MAX * 2], to[MAX * 2], en;
int vis[MAX], vis_id;
int dist[MAX];
int p[MAX], ans[MAX];

inline int parent(const int i)
{
	return (p[i] == i) ? i : (p[i] = parent(p[i]));
}

inline void unite(const int i, const int j)
{
	const int I = parent(i), J = parent(j);
	if (I != J)
	{
		p[J] = I;
		ans[I] = max(
				max(ans[I], ans[J]),
				(ans[I] >> 1) + (ans[I] & 1) + (ans[J] >> 1) + (ans[J] & 1) + 1);
	}
}
int n, m, q;


inline void add_edge(const int i, const int j)
{
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	++en;
}
inline void add_bi_edge(const int i, const int j)
{
	add_edge(i, j);
	add_edge(j, i);
}
inline int bfs(const int s)
{
	++vis_id;
	queue<int> q;
	q.push(s); dist[s] = 0; vis[s] = vis_id;
	int last = s;
	while(!q.empty())
	{
		const int i = q.front(); q.pop(); last = i;
		unite(i, s);
		const int cur_dist = dist[i] + 1;
		for (int j = head[i]; ~j; j = nxt[j])
		{
			const int k = to[j];
			if (vis[k] != vis_id)
			{
				q.push(k);
				vis[k] = vis_id;
				dist[k] = cur_dist;
			}
		}
	}
	return last;
}
inline void read()
{
	scanf("%d%d%d", &n, &m, &q);
	for(int a, b; m--; )
	{
		scanf("%d%d", &a, &b);
		add_bi_edge(a, b);
	}
}
inline void init()
{
	memset(head, -1, sizeof head);
	for (int i = 0; i < MAX; ++i)
	{
		p[i] = i;
	}
}
inline void preprocess()
{
	for (int i = 1; i <= n; ++i)
	{
		if (vis[i] == 0)
		{
			const int last = bfs(bfs(i));
			ans[parent(i)] = dist[last];
		}
	}
}
inline void solve()
{
	for(int t, x, y; q--; )
	{
		scanf("%d%d", &t, &x);
		if (t == 1)
		{
			cout << ans[parent(x)] << endl;
		}
		else
		{
			scanf("%d", &y);
			unite(x, y);
		}
	}
}
int main()
{
	init();
	read();
	preprocess();
	solve();
	return 0;
}

