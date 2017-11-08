#include <bits/stdc++.h>
#define MAX 105
#define MOD 1000007
using namespace std;
int n;
int memo[MAX][MAX];
char board[MAX][MAX];
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j];
	if (ret != -1)
	{
		return ret;
	}
	if (board[i][j] == 'B')
	{
		return ret = 0;
	}
	if (i == 0)
	{
		return ret = 1;
	}
	ret = 0;
	if (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] != 'B')
	{
		ret = dp(i - 1, j - 1);
	}
	else if (i - 2 >= 0 && j - 2 >= 0 && board[i - 2][j - 2] != 'B')
	{
		ret = dp(i - 2, j - 2);
	}
	
	if (i - 1 >= 0 && j + 1 < n && board[i - 1][j + 1] != 'B')
	{
		ret = (ret + dp(i - 1, j + 1)) % MOD;
	}
	else if (i - 2 >= 0 && j + 2 < n && board[i - 2][j + 2] != 'B')
	{
		ret = (ret + dp(i - 2, j + 2)) % MOD;
	}
	return ret;
}
inline void init(void)
{
	memset(memo, -1, sizeof memo);
}
int main(void)
{
	int TC;
	scanf("%d", &TC);
	for(int tc = 1; tc <= TC; ++tc)
	{
		memset(memo, -1, sizeof memo);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s", board[i]);
		}
		bool flag = false;
		for (int i = 0; i < n && !flag; ++i)
		for (int j = 0; j < n && !flag; ++j)
		{
			if (board[i][j] == 'W' && !flag)
			{
				printf("Case %d: %d\n", tc, dp(i, j));
				flag = true;
			}
		}
	}
}