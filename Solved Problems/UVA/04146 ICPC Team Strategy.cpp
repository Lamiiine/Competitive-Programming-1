#include<bits/stdc++.h>
using namespace std;
int n;
int contestant_time[3][15];
int memo[1 << 12][3][300]; // 900 * 4000
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", contestant_time[i] + j);
}
inline int dp(const int i, const int j, const int k)
{
	int & ret = memo[i][j][k];
	if (ret != -1) return ret;
	ret = 0;
	// for all problems p
	for (int p = 0; p < n; ++p)
		// if problem p has not yet been solved
		if (!(i & (1 << p)))
			// for all contestants
			for (int c = 0; c < 3; ++c)
				// if not last, and can do it on time
				if (c != j && contestant_time[c][p] <= k)
					ret = max(ret, 1 + dp(i | (1 << p), c, k - contestant_time[c][p]));
	return ret;
}
inline void init(void)
{
	memset(memo, 0xFF, sizeof memo);
	memset(memo[(1 << n) - 1], 0, sizeof memo[0]);
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		init();
		printf("%d\n", max(dp(0, 0, 280), max(dp(0, 1, 280), dp(0, 2, 280))));
	}
	return 0;
}
/*
2
3
100 100 80
190 120 90
120 150 100
4
50 20 300 300
200 100 30 250
140 120 100 100
*/

