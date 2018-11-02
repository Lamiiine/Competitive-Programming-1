#include<bits/stdc++.h>
#define MAX 512
using namespace std;
int match[MAX];

typedef pair<int, int> ii;
int t[MAX];
ii s[MAX];
ii e[MAX];
int n;
int head[MAX], to[MAX * MAX], nxt[MAX * MAX], en;
inline void init(void)
{
	memset(head, -1, sizeof head);
	memset(match, -1, sizeof match);
	en = 0;
}
inline void add_edge(const int i, const int j)
{
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	++en;
}
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 0, a, b; i < n; ++i)
	{
		scanf("%d:%d", &a, &b);
		t[i] = a * 60 + b;
		scanf("%d%d", &a, &b);
		s[i] = ii(a, b);
		scanf("%d%d", &a, &b);
		e[i] = ii(a, b);
	}
}
inline int dist(const ii & x, const ii & y)
{
	return abs(x.first - y.first) + abs(x.second - y.second);
}
inline void build_adj(void)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (t[i] + dist(s[i], e[i]) + dist(e[i], s[j]) < t[j])
			{
				add_edge(i, j);
			}
		}
	}
}
int vis[MAX], vis_id;
inline int aug(const int i)
{
	if (vis[i] == vis_id)
		return 0;
	vis[i] = vis_id;
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int k = to[j];
		if (match[k] == -1 || aug(match[k]))
		{
			match[k] = i;
			return 1;
		}
	}
	return 0;
}
inline int max_match(void)
{
	int ans = 0;
	++vis_id;
	for (int i = 0; i < n; ++i, ++vis_id)
		ans += aug(i);
	return ans;
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		build_adj();
		printf("%d\n", n - max_match());
	}

	return 0;
}

