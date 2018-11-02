#include<bits/stdc++.h>
#define MAX (1 << 10)
#define INF (1 << 20)
using namespace std;
int head[MAX], to[MAX * 2], nxt[MAX * 2], en;
int n;

inline void add_edge(const int i, const int j)
{
	nxt[en] = head[i];
	head[i] = en;
	to[en] = j;
	++en;
}
int p[MAX], vis[MAX] = { 0 }, vis_id = 0;

int memo[MAX][2];
/* minimum edge cover starting at node i in the tree,
 * knowing that you t ? will take i : will not
 * */
inline int dp(const int i, const int t)
{
	int & ret = memo[i][t];
	if (ret != -1) return ret;
	if (!t)
	{
		// i is not taken
		ret = 0;
		for (int j = head[i]; ~j; j = nxt[j])
			if (to[j] != p[i])
				ret += dp(to[j], 1);	// you have to take k!
		return ret;
	}
	else
	{
		// i is taken
		ret = 0;
		for (int j = head[i]; ~j; j = nxt[j])
			if (to[j] != p[i])
				ret += min(dp(to[j], 1), dp(to[j], 0));
		return ret = (ret + 1);
	}
}
inline void init(void)
{
	memset(head, -1, sizeof head);
	en = 0;
	++vis_id;
	memset(memo, -1, sizeof memo);
}

inline void read(void)
{
	for (int i = 1, k, x; i <= n; ++i)
	{
		scanf("%d", &k);
		while(k--)
			scanf("%d", &x), add_edge(i, x);
	}
}
inline void p_dfs(const int i)
{
	for (int j = head[i]; ~j; j = nxt[j])
	{
		const int k = to[j];
		if (vis[k] != vis_id)
		{
			p[k] = i;
			vis[k] = vis_id;
			p_dfs(k);
		}
	}
}
int main(void)
{
	while(scanf("%d", &n), n)
	{
		init();
		read();
		p[1] = -1; vis[1] = vis_id; p_dfs(1);
		printf("%d\n", n == 1 ? 1 : min(dp(1, 0), dp(1, 1)));
	}
	return 0;
}
