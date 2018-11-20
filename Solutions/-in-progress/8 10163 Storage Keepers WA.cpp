#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int arr[35];
int memo[35][105];
int n, m;
/*
 * starting and index i, what is the maximum safety level that you
 * can get if you have j keeps left?
 */
inline int dp(const int i, const int j)
{
	// memory
	int & ret = memo[i][j];
	if (ret != -1)
	{
		return ret;
	}
	// base case
	if (j == 0)
	{
		return ret = INF;
	}
	if (i == m)
	{
		return ret = 0;
	}
	// recurse
	ret = dp(i + 1, j);
	for (int k = 1; k <= j; ++k)
	{
		ret = max(ret, min(arr[i]/k, dp(i + 1, j - k)));
	}
	return ret;
}
int memo_path[35][105];
inline int path(const int i, const int j)
{
	int & ret = memo_path[i][j];
	if (ret != -1)
	{
		return ret;
	}
	if (j == 0)
	{
		return ret = 0;
	}
	const int cur = dp(i, j);
	if (!cur)
	{
		return ret = 0;
	}
	ret = INF;
	if (dp(i + 1, j) == cur)
	{
		ret = path(i + 1, j);
	}
	for (int k = 1; k <= j; ++k)
	{
		if (cur == min(arr[i]/k, dp(i + 1, j - k)))
		{
			ret = min(ret, arr[i] + path(i + 1, j - k));
		}
	}
	return ret;
}
int main(void)
{
	while(scanf("%d%d", &n, &m), n || m)
	{
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", arr + i);
		}
		memset(memo, -1, sizeof memo);
		memset(memo_path, -1, sizeof memo_path);
		printf("%d %d\n", dp(0, n), path(0, n));
	}
}

