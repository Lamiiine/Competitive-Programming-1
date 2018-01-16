#include<bits/stdc++.h>
#define MAX 10100
#define MAX_E 100100
using namespace std;
int s, t;
int head[MAX], nxt[MAX_E * 2], to[MAX_E * 2], cap[MAX_E * 2], en;
inline void add_edge(const int a, const int b)
{
	nxt[en] = head[a];
	head[a] = en;
	to[en] = b;
	cap[en] = 1;
	++en;
}
inline void add_bi_edge(const int a, const int b)
{
	add_edge(a, b);
	add_edge(b, a);
}
int vis[MAX] = { 0 }, vis_id = 0;
int n, m;
inline void init(void)
{
	memset(head, -1, sizeof head);
	en = 0;
}
inline int dfs(const int i)
{
	if (vis[i] == vis_id) return 0;
	vis[i] = vis_id;
	if (i == t) return 1;
	for (int j = head[i]; ~j; j = nxt[j])
	{
		if (cap[j] >= 1 && dfs(to[j]))
		{
			cap[j] -= 1;
			cap[j ^ 1] += 1;
			return 1;
		}
	}
	return 0;
}
inline void read(void)
{
	for (int i = 0, a, b; i < m; ++i)
	{
		scanf("%d%d", &a, &b);
		add_bi_edge(a, b);
	}

	scanf("%d%d", &s, &t);
}

int main(void)
{
	for(int tc = 1; scanf("%d%d", &n, &m), n || m; ++tc)
	{
		init();
		read();
		bool flag = true;
		for (int j = 0; j < 2; ++j)
		{
			++vis_id;
			if (!dfs(s)) flag = false;
		}
		printf("Case %d: %s\n", tc, flag ? "YES" : "NO");
	}
	return 0;
}

