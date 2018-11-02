#include<bits/stdc++.h>
#define MAX (1 << 5)
using namespace std;
int n, m;
double p, q;
double memo[MAX << 1][MAX << 1];
inline void init_memo(void)
{
	for (int i = 0; i < (MAX << 1); ++i)
	{
		for (int j = 0; j < (MAX << 1); ++j)
		{
			memo[i][j] = -1.0;
		}
	}
}

inline double dp(const int i, const int j)
{
	// memory
	double & ret = memo[i][j];
	if (ret != -1.0)
	{
		return ret;
	}

	// base case
	if (i == m)
	{
		return ret = (j >= n ? 1.0 : 0.0);
	}

	// recurse
	return ret = p * dp(i + 1, j + 1) + q * dp(i + 1, j);
}

int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d%lf", &n, &p);
		m = (n << 1) - 1;
		q = 1.0 - p;
		init_memo();
		printf("%.2lf\n", dp(0, 0));
	}

	return 0;
}

