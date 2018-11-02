#include<bits/stdc++.h>
#define MAX (1 << 11)
#define eps 1e-7
using namespace std;
double memo[MAX][MAX];
inline void init_memo(void)
{
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			memo[i][j] = -1.0;
}
// probability of getting a sum of j having i rolls left
inline double dp(const int i, const int j)
{
	// memorization
	double & ret = memo[i][j];
	if (ret != -1.0) return ret;
	// base case
	if (i == 0 || j == 0)
		return ret = (i == 0 && j == 0) ? 1.0 : 0.0;
	ret = 0.0;
	for (int k = 1; k <= min(6, j); ++k)
		ret += dp(i - 1, j - k);
	return ret /= 6.0;
}
int main(void)
{
	init_memo();
	int TC; scanf("%d", &TC);
	for(int n, k; TC--;)
	{
		scanf("%d%d", &n, &k);
		if (n >= MAX || k >= MAX)
			printf("0\n");
		else printf("%d\n", (int) (dp(n, k) * 100.0 + eps));
	}
	return 0;
}

