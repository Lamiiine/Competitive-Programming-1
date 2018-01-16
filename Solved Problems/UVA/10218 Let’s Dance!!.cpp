#include<bits/stdc++.h>
using namespace std;
int m, w, c;
/*
 * knowing that you have given away i candies
 * j out of which were given to men
 * what is the probability that the number of candies
 * given to men is evens?
 */
long double memo[102][102];
inline long double dp(const int i, const int j)
{
	long double & ret = memo[i][j];
	// memory
	if (ret != -1.0)
	{
		return ret;
	}
	// base case!
	if (i == c)
	{
		return ret = (j & 1) ? 0.0 : 1.0;
	}
	return ret = (long double) ((long double) w / (w + m)) * dp(i + 1, j) + ((long double) m / (w + m)) * dp(i + 1, j + 1);
}

inline void init_memo(void)
{
	for (int i = 0; i < 102; ++i)
	{
		for (int j = 0; j < 102; ++j)
		{
			memo[i][j] = -1.0;
		}
	}
}
int main(void)
{
	while(scanf("%d%d%d", &m, &w, &c), m || w)
	{
		init_memo();
		printf("%.7llf\n", dp(0, 0));
	}
	return 0;
}

