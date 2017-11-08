#include<bits/stdc++.h>
#define MAX (1 << 8)
using namespace std;
const int INF = 1e9;
int memo[MAX][MAX];
int f[MAX];
int acc_f[MAX];
int n;
inline int range_sum(const int i, const int j)
{
	if (i > j)
	{
		return 0;
	}
	return acc_f[j] - (i ? acc_f[i - 1] : 0);
}
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j];
	if (ret != -1)
	{
		return ret;
	}
	ret = INF;
	const int my_range = range_sum(i, j);
	// pick a root!
	for (int k = i; k <= j; ++k)
	{
		ret = min(ret, dp(i, k - 1) + dp(k + 1, j) + my_range - f[k]);
	}
	return ret;
}
inline void init_memo(void)
{
	memset(memo, 0xFF, sizeof memo);
	for (int i = 0; i < n; ++i)
	{
		memo[i][i] = memo[i + 1][i] = 0;
		memo[i][i + 1] = min(f[i], f[i + 1]);
	}
}
inline void init_acc(void)
{
	acc_f[0] = f[0];
	for (int i = 1; i < n; ++i)
	{
		acc_f[i] = acc_f[i - 1] + f[i];
	}
}
inline void read(void)
{
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", f + i);
	}
}
int main(void)
{
	while(~scanf("%d", &n))
	{
		read();
		init_acc();
		init_memo();
		printf("%d\n", dp(0, n - 1));
	}
}

