#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int memo[12][103][103][2];
/*
 * having k mailboxes left, what is the minimum number
 * of crackers you need in order for you to eliminate
 * all the options in the range [i, j]
 */
inline int dp(const int k, const int i, const int j, int need_to_check_upper_bound)
{
	int & ret = memo[k][i][j][need_to_check_upper_bound];
	if (ret != -1)
	{
		return ret;
	}
	if (j < i)
	{
		return ret = 0;
	}
	if (i == j)
	{
		return ret = need_to_check_upper_bound ? i : 0;
	}
	if (!k)
	{
		return ret = INF;
	}
	ret = INF;
	for (int t = i; t <= j; ++t)
	{
		ret = min(ret, t + max(dp(k, t + 1, j, need_to_check_upper_bound), dp(k - 1, i, t, 0)));
	}
	return ret;
}
int main(void)
{
	memset(memo, 0xFF, sizeof memo);
	int TC; scanf("%d", &TC);
	for (int k, m; TC--;)
	{
		scanf("%d%d", &k, &m);
		printf("%d\n", dp(k, 1, m, 1));
	}
	return 0;
}

