#include<bits/stdc++.h>
#define MAX 2550
using namespace std;
typedef pair<int, int> ii;
int n;
int head[MAX], nxt[MAX * 2], to[MAX * 2], en;
bool valid[MAX * 2];
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
inline void init(void)
{
	memset(head, -1, sizeof head);
	en = 0;
}
int p[MAX], dist[MAX], vis[MAX] = { 0 }, vis_id = 0;
// return index of node that is farthest from s!
inline int bfs(const int s)
{
	int last = s;
	queue<int> q;
	q.push(s);
	dist[s] = 0;
	p[s] = -1;
	vis[s] = ++vis_id;
	while(!q.empty())
	{
		const int i = q.front();
		const int cur_dist = dist[i] + 1;
		q.pop();
		last = i;
		for (int j = head[i]; ~j; j = nxt[j])
			if (valid[j])
			{
				const int k = to[j];
				if (vis[k] != vis_id)
				{
					vis[k] = vis_id;
					dist[k] = cur_dist;
					q.push(k);
					p[k] = i;
				}
			}
	}
	return last;
}
inline int get_end(int s)
{
	s = bfs(s);
	return bfs(s);
}
inline int climb(int s, int steps)
{
	while(steps-- > 0)
		s = p[s];
	return s;
}
inline void read(void)
{
	scanf("%d", &n);
	for (int a, b, i = 1; i < n; ++i)
		scanf("%d%d", &a, &b), add_bi_edge(a, b);
}
int main(void)
{
	memset(valid, 1, sizeof valid);
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		int ans = INT_MAX;
		ii ans_remove = ii(0, 0);
		ii ans_add = ii(0, 0);
		for (int i = 0; i < en; i += 2)
		{
			valid[i] = valid[i + 1] = false;
			int e1 = get_end(to[i]);
			int e2 = get_end(to[i + 1]);
			int d1 = dist[e1];
			int d2 = dist[e2];
			int cur = max(max(d1, d2), 1 + (d1 + 1) / 2 + (d2 + 1) / 2);
			if (cur < ans)
			{
				ans_remove = ii(to[i], to[i + 1]);
				ans_add = ii(climb(e1, d1 >> 1), climb(e2, d2 >> 1));
				ans = cur;
			}
			valid[i] = valid[i + 1] = true;
		}
	 	printf("%d\n%d %d\n%d %d\n", ans, ans_remove.first, ans_remove.second, ans_add.first, ans_add.second);
	}
	return 0;
}

