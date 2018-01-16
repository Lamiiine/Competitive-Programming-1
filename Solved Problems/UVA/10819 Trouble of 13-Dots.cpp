#include<bits/stdc++.h>
#define T 2000
using namespace std;
int m, n;
int memo[102][10220][2];
int p[102], v[102];	// price and value of each item!
/*
 * maximum value you can get starting at index i, knowing that
 * you have $j left, if you (k) ? exempted from exceeding 2000
 */
inline int dp(const int i, const int j, const int k)
{
	// memorization
	int & ret = memo[i][j][k];
	if (ret != -1) return ret;
	// base case
	if (i == n)
	{
		if (!k)	// you have got the 200-dollar grant
			return (m + 200 - j > T) ? 0 : -100000000;
		else	// you have not taken any grant!
			return 0;
	}
	// recursion
	return ret =
			(j < p[i])
			? dp(i + 1, j, k)
			: max(dp(i + 1, j, k), v[i] + dp(i + 1, j - p[i], k));
}
inline void read(void)
{
	for (int i = 0; i < n; ++i)
		scanf("%d%d", p + i, v + i);
}
int main(void)
{
	while(~scanf("%d%d", &m, &n))
	{
		memset(memo, -1, sizeof memo);
		read();
		printf("%d\n", max(dp(0, m, 1), dp(0, m + 200, 0)));
	}
	return 0;
}

