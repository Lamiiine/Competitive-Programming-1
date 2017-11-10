#include <bits/stdc++.h>
#define MAX 1024
#define OO 100000000
using namespace std;
int n, m, x, y;
char arr[MAX][MAX];
int count_black_in_col[MAX] = { 0 };
int memo[MAX][MAX][2];
inline int blackening_cost(const int c)
{
	return n - count_black_in_col[c];
}
inline int whitening_cost(const int c)
{
	return count_black_in_col[c];
}
inline int dp(const int c, const int w, const int black)
{
	int & ret = memo[c][w][black];
	if (~ret) return ret;
	// Base cases!
	if (c == m)
	{
		return ret = (w >= x ? 0 : OO);
	}
	ret = OO;
	// Blackening recursion!
	if ((black && w < y) || (!black && w >= x))
	ret = min(ret, blackening_cost(c) + dp(c + 1, 1 + (black ? w : 0), true));
	// Whitening recursion!
	if ((!black && w < y) || (black && w >= x))
	ret = min(ret, whitening_cost(c) + dp(c + 1, 1 + (!black ? w : 0), false));
	return ret;
}
inline void init()
{
	memset(memo, -1, sizeof memo);
}
inline void read()
{
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", arr[i]);
	}
}
inline void count_black_pixels()
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			count_black_in_col[j] += (arr[i][j] == '#');
		}
	}
}
int main()
{
	read();
	init();
	count_black_pixels();
	printf("%d", min(dp(0, 0, 0), dp(0, 0, 1)));
	return 0;
}
/*
6 5 1 2
##.#.
.###.
###..
#...#
.##.#
###..

2 5 1 1
#####
.....

 */

