// bottom-up DP solution
#include<bits/stdc++.h>
#define MAX 502
using namespace std;
int n;
double p, q;
double memo[MAX][MAX][MAX];
int main(void)
{
	while(scanf("%d%lf", &n, &p), n)
	{
		q = 1.0 - p;
		for (int j = 0; j <= n; ++j)
		{
			for (int k = 0; k <= n; ++k)
			{
				memo[n][j][k] = (double) max(j, k);
			}
		}
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = 0; j <= i + 1; ++j)
			{
				for (int k = 0; k <= j; ++k)
				{
					memo[i][j][k] = p * memo[i + 1][max(j, k + 1)][k + 1] + q * memo[i + 1][j][0];
				}
			}
		}
		printf("%lf\n", memo[0][0][0]);
	}
	return 0;
}

