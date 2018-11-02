#include<bits/stdc++.h>
#define MAX 5005
#define INF 1000000001LL
using namespace std;
typedef pair<int, int> ii;
typedef long long int ll;
ll memo[MAX][MAX];
vector<ii> adj[MAX];
int n, m, t;
/*
 * minimum time required to travel through j cities starting at i
 */
inline ll dp(const int i, const int j)
{
	// memorization
	ll & ret = memo[i][j];
	if (ret != -1LL) return ret;
	// base case
	if (i == n || j == 1)
		return ret = (i == n & j == 1) ? 0LL : INF;

	// recursion
	ret = INF;
	for (int k = 0; k < adj[i].size(); ++k)
		ret = min(ret, adj[i][k].second + dp(adj[i][k].first, j - 1));
	return ret;
}
// visit k cities starting at i!
inline void path(const int i, const int j)
{
	printf("%d", i);
	if (i == n && j == 1)
	{
		printf("\n");
		return;
	}
	printf(" ");
	const int ans = dp(i, j);
	for (int k = 0; k < adj[i].size(); ++k)
		if (adj[i][k].second + dp(adj[i][k].first, j - 1) == ans)
		{
			path(adj[i][k].first, j - 1);
			return;
		}
}
int main(void)
{
	memset(memo, -1, sizeof memo);
	scanf("%d%d%d", &n, &m, &t);
	for (int a, b, c, i = 0; i < m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		adj[a].push_back(ii(b, c));
	}
	int ans = 0;
	for (int i = 2; i <= n; ++i)
		if ((ll) dp(1, i) <= t)
			ans = max(ans, i);
	printf("%d\n", ans);
	path(1, ans);
	return 0;
}

