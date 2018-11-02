#include<bits/stdc++.h>
#define MAX_V 200
#define MAX_E 10000
using namespace std;
typedef pair<int, int> ii;
bool visited[MAX_V + 5];
int n, m;
char vis[MAX_V + 5];
int head[MAX_V + 5], nxt[(MAX_E << 1) + 5], to[(MAX_E << 1) + 5], en;
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
	memset(head, 0xFF, sizeof head);
	en = 0;
	memset(vis, 0, sizeof vis);
	memset(visited, 0, sizeof visited);
}
inline void read(void)
{
	scanf("%d%d", &n, &m);
	for (int f, t; m--; )
	{
		scanf("%d%d", &f, &t);
		add_bi_edge(f, t);
	}
}
inline bool dfs(const int i)
{
	const char my_color = vis[i];
	const char op_color = 3 - vis[i];
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int k = to[j];
		if (!vis[k])
		{
			vis[k] = op_color;
			if (!dfs(k))
			{
				return false;
			}
		}
		else if (vis[k] == my_color)
		{
			return false;
		}
	}
	return true;
}
ii count_dfs(const int i)
{
	visited[i] = true;
	int node_count = 1, red_count = (vis[i] == 1);
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int k = to[j];
		if (visited[k])
		{
			continue;
		}
		const ii tmp = count_dfs(k);
		node_count += tmp.first;
		red_count += tmp.second;
	}
	return ii(node_count, red_count);
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		bool flag = true;
		for (int i = 0; i < n; ++i)
		{
			if (!vis[i])
			{
				vis[i] = 1;
				if (!dfs(i))
				{
					flag = false;
					break;
				}
			}
		}
		if (!flag)
		{
			printf("-1\n");
			continue;
		}
		else {
			int ans = 0;
			for (int i = 0; i < n; ++i)
			{
				if (head[i] == -1)
				{
					++ans;
				}
				else
				{
					if (!visited[i]){
						const ii k = count_dfs(i);
						ans += min(k.second, k.first - k.second);
					}
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}