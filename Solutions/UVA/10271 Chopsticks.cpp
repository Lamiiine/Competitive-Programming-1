#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int k, n;
int arr[5010];
int memo[1010][5010];
/*
 * minimum cost of allocating sticks to i persons starting at chopstick # j
 */
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j];
	if (ret != -1)
	{
		return ret;
	}
	return ret = min(dp(i, j + 1), (arr[j + 1] - arr[j])*(arr[j + 1] - arr[j]) + dp(i - 1, j + 2));
}
inline void read(void)
{
	scanf("%d%d", &k, &n);
	k += 8;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
	}
}
inline void init_memo(void)
{
	memset(memo, -1, sizeof memo);
	memset(memo[0], 0, sizeof memo[0]);
	for (int i = 1; i <= k; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (n - j < 3*i)
			{
				memo[i][j] = INF;
			}
		}
	}
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		init_memo();
		printf("%d\n", dp(k, 0));
	}
	return 0;
}

