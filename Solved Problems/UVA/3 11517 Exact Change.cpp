// much much better solvable by BFS
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> ii;
int sum, ans;
int n;
int val[105];
int memo[105][20100];
/* return the minimum value > sum that could be obtained
 * from the set of coins starting at coin # i, knowing that you
 * have already accumulated a set summing up to j
 */
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j];
	if (ret != -1)
	{
		return ret;
	}
	// base case
	if (j >= sum)
	{
		return ret = j;
	}
	if (i == n)
	{
		return ret = INF;
	}
	// recurse
	return ret = min(dp(i + 1, j), dp(i + 1, j + val[i]));
}
int count_memo[105][20100];
inline int count_dp(const int i, const int j)
{
	int & ret = count_memo[i][j];
	if (ret != -1)
	{
		return ret;
	}
	if (j == ans)
	{
		return ret = 0;
	}
	if (i == n || j > ans)
	{
		return ret = INF;
	}

	return ret = min(count_dp(i + 1, j), 1 + count_dp(i + 1, j + val[i]));
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d%d", &sum, &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", val + i);
		}
		memset(memo, -1, sizeof memo);
		memset(count_memo, -1, sizeof count_memo);
		ans = dp(0, 0);
		printf("%d %d\n", ans, count_dp(0, 0));
	}
	return 0;
}

