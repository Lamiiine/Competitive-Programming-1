#include<bits/stdc++.h>
#define MAX 32
#define offset 3000
using namespace std;
int n;
/*
 * memo[cur][i][j] = true if and only if there exists a path from top
 * till box [cur][i] that sums up to j
 * notice that we are using rolling. Therefore, the first dimention is 2, not 60!
 */
bool memo[2][MAX][offset * 2 + 100];
int board[MAX << 1][MAX];
inline void read(void)
{
	for (int i = 0; i < (n << 1) - 1; ++i)
	{
		const int num = n - abs(i - (n - 1));
		for (int j = 0; j < num; ++j)
		{
			scanf("%d", board[i] + j);
		}
	}
}
inline int solve(void)
{
	memset(memo[0], 0, sizeof memo[0]);
	memo[0][0][offset + board[0][0]] = true;
	memo[0][0][offset - board[0][0]] = true;
	int prev = 0, cur = 1;
	for (int i = 1; i < (n << 1) - 1; ++i)
	{
		memset(memo[cur], 0, sizeof memo[cur]);
		const int num = n - abs(i - (n - 1));
		for (int j = 0; j < num; ++j)
		{
			const int value = board[i][j];
			for (int k = 0; k < (offset << 1) + 10; ++k)
			{
				if (i >= n)
				{
					if (memo[prev][j][k] || memo[prev][j + 1][k])
					{
						memo[cur][j][k + value] = true;
						memo[cur][j][k - value] = true;
					}
				}
				else
				{
					if (memo[prev][j][k] || (j && memo[prev][j - 1][k]))
					{
						memo[cur][j][k + value] = true;
						memo[cur][j][k - value] = true;
					}
				}
			}
		}
		swap(cur, prev);
	}
	return prev;
}
int main(void)
{
	while(scanf("%d", &n), n)
	{
		read();
		const int c = solve();
		int ans = 1000000000;
		for (int i = 0; i < (MAX * 200); ++i)
		{
			if (memo[c][0][i])
			{
				ans = min(ans, abs(i - offset));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
