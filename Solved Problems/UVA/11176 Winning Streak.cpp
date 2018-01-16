// top-down DP solution
#include<bits/stdc++.h>
#define MAX 501
using namespace std;
int n;
double p, q;
double memo[MAX][MAX][MAX];
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
		// this is the expected value
		return (double) j;
	}
	return ret = p * dp(i + 1, max(j, k + 1), k + 1) + q * dp(i + 1, j, 0);
}
inline void init(void)
{
	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			for (int k = 0; k <= n; ++k)
			{
				memo[i][j][k] = -1.0;
			}
		}
	}
}
int main(void)
{
	while(scanf("%d%lf", &n, &p), n)
	{
		init();
		q = 1.0 - p;
		printf("%lf\n", dp(0, 0, 0));
	}
	return 0;
}

