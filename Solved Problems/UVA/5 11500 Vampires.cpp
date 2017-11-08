#include<bits/stdc++.h>
using namespace std;
double memo[7][11][22][22][1001];
/*
 * probability that vampire #1 wins!
 */
inline double dp(const int at, const int d, const int e1, const int e2, const int depth)
{
	// base case
	if (e1 <= 0)
	{
		return 0.0;
	}

	if (e2 <= 0)
	{
		return 1.0;
	}
	// memory
	double & ret = memo[at][d][e1][e2][depth];
	if (ret != -1.0)
	{
		return ret;
	}
	if (depth >= 1000)
	{
		return ret = 0.0;
	}
	// recurse
	return ret = (double) ((double)at / 6.0) * dp(at, d, e1 + d, e2 - d, depth + 1) + ((double)((double)6.0 - at) / 6.0) * dp(at, d, e1 - d, e2 + d, depth + 1);
}
inline void init_memo(void)
{
	for (int i = 0; i < 7; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			for (int k = 0; k < 22; ++k)
			{
				for (int t = 0; t < 22; ++t)
				{
					for (int d = 0; d < 1001; ++d)
					{
						memo[i][j][k][t][d] = -1.0;
					}
				}
			}
		}
	}
}
int main(void)
{
	init_memo();
	for (int e1, e2, at, d; scanf("%d%d%d%d", &e1, &e2, &at, &d), e1 || e2 || at || d;
			printf("%.1lf\n", 100.0 * dp(at, d, e1, e2, 0)));
	return 0;
}

