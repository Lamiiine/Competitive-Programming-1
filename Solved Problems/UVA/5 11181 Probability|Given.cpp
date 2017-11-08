#include<bits/stdc++.h>
#define MAX 23
using namespace std;
int n, r;
double memo[MAX][MAX][MAX];
double p[MAX];
/*
 * memo[i][j][k] = the probability of having exactly j friends buy
 * something starting at i and onward excluding k
 */
inline double dp(const int i, const int j, const int k)
{
	// memory
	double & ret = memo[i][j][k];
	if (ret != -1.0)
	{
		return ret;
	}
	// base case
	if (i == n)
	{
		return ret = (j == 0) ? 1.0 : 0.0;
	}

	if (i == k)
	{
		return ret = dp(i + 1, j, k);
	}

	return ret = (1.0 - p[i]) * dp(i + 1, j, k) + (j == 0 ? 0.0 : p[i] * dp(i + 1, j - 1, k));
}
inline void init_memo(void)
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			for (int k = 0; k < MAX; ++k)
			{
				memo[i][j][k] = -1.0;
			}
		}
	}
}
inline void read(void)
{
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", p + i);
	}
}
int main(void)
{
	for(int tc = 1; scanf("%d%d", &n, &r), n || r; ++tc)
	{
		init_memo();
		read();
		printf("Case %d:\n", tc);
		if (r == 0)
		{
			for (int i = 0; i < n; ++i)
			{
				printf("0.000000\n");
			}
			continue;
		}
		for (int i = 0; i < n; ++i)
		{
			printf("%lf\n", p[i] * dp(0, r - 1, i) / dp(0, r, 22));
		}
	}

	return 0;
}

