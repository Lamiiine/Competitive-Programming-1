#include<bits/stdc++.h>
#define MAX (1 << 10)
using namespace std;
int n, k, m;
double p[MAX];
double memo_1[MAX];
/*
 * the probability of 1 triple dying after j days
 */
double memo[MAX][MAX];
/*
 * the probability of i tribbles dying after j days
 */
inline double dp(const int i, const int j)
{
	// memory
	double & ret = memo[i][j];
	if (ret != -1.0)
	{
		return ret;
	}
	// base case
	if (i == 0)
	{
		return ret = 1.0;
	}
	if (j == 0)
	{
		return ret = 0.0;
	}
	// recursive case
	double & cur = memo_1[j - 1];
	if (cur == -1.0)
	{
		cur = 0.0;
		for (int k = 0; k < n; ++k)
		{
			cur += p[k] * dp(k, j - 1);
		}
	}
	return ret = pow(cur, i);
}
inline void init_memo(void)
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			memo[i][j] = -1.0;
		}
		memo_1[i] = -1.0;
	}
}
inline void read(void)
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", p + i);
	}
}
int main(void)
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		init_memo();
		read();
		printf("Case #%d: %.7lf\n", tc, dp(k, m));
	}

	return 0;
}

