#include<bits/stdc++.h>
#define MAX 128
using namespace std;
vector<int> adj[MAX];
int match[MAX];
inline void init(void)
{
	memset(match, -1, sizeof match);
	for (int i = 0; i < MAX; ++i)
	{
		adj[i].clear();
	}
}
int n, m;
inline void read(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 0, a, b; i < m; ++i)
	{
		scanf("%d%d", &a, &b);
		--a; --b;
		adj[a].push_back(b);
	}
}
int vis[MAX], vis_id;
inline int aug(const int i)
{
	if (vis[i] == vis_id)
		return 0;
	vis[i] = vis_id;
	for (int j = 0; j < adj[i].size(); ++j)
	{
		const int k = adj[i][j];
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
		printf("%d\n", n - max_match());
	}
	return 0;
}

