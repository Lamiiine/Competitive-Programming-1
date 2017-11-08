#include<bits/stdc++.h>
#define MAX 1024
#define INF 1000000000
using namespace std;
int r, c, b, s;
int memo[102][MAX];
char arr[MAX][MAX];
int cost[MAX];	// cost[i] = cost of building a bride at column i
enum color:char {unvisited = 0, north, south} vis[MAX][MAX];
const int di[4] = {0, 0, 1, -1},
		dj[4] = {1, -1, 0, 0};
inline void dfs(const int i, const int j, const color cur)
{
	vis[i][j] = cur;
	for (int k = 0, I, J; k < 4; ++k)
	{
		I = i + di[k], J = j + dj[k];
		if (I >= 0 && I < r && J >= 0 && J < c && arr[I][J] == '#' && vis[I][J] == unvisited)
			dfs(I, J, cur);
	}
}
/*
 * minimum cost of building i bridges starting at column j
 */
inline int dp(const int i, const int j)
{
	// memorization
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	// base case
	if (i == 0)
		return ret = 0;
	if (j >= c)
		return ret = INF;
	// recursion
	return ret = min(dp(i, j + 1), cost[j] + dp(i - 1, j + s + 1));
}
inline void set_cost(void)
{
	for (int i = 0; i < c; ++i)
	{
		int low_n = 0, high_s = r - 1;
		for (int j = 0; j < r; ++j)
			if (vis[j][i] == north)
				low_n = max(low_n, j);
			else if (vis[j][i] == south)
				high_s = min(high_s, j);
		cost[i] = high_s - low_n  - 1;
	}
}
inline void init(void)
{
	memset(vis, 0, sizeof vis);
	memset(memo, -1, sizeof memo);
}
int main(void)
{
	while(~scanf("%d%d%d%d", &r, &c, &b, &s))
	{
		init();
		for (int i = 0; i < r; ++i)
			scanf("%s", arr[i]);
		dfs(0, 0, north);
		dfs(r - 1, 0, south);
		set_cost();
		printf("%d\n", dp(b, 0));
	}
	return 0;
}

