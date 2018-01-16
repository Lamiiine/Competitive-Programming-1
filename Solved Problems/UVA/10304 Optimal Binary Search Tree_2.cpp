#include<bits/stdc++.h>
#define MAX (1 << 8)
using namespace std;
const int INF = 1e9;
/*
 * memo[i][j] stores the minimum cost to form a tree
 * covering elements numbered from i to j inclusive
 */
int memo[MAX][MAX];
int f[MAX];     // frequency of element #i
int acc_f[MAX]; // accumulative frequency
int n;
inline int range_sum(const int i, const int j)
{
	if (i > j)
	{
		return 0;
	}
	return acc_f[j] - (i ? acc_f[i - 1] : 0);
}
inline void solve(void)
{
	// empty intervals
	for (int i = 0; i < n; ++i)
	{
		memo[i + 1][i] = 0;
	}
	// length-1 intervals
	for (int i = 0; i < n; ++i)
	{
		memo[i][i] = 0;
	}
	// length-2 intervals
	for (int i = 0; i < n; ++i)
	{
		memo[i][i + 1] = min(f[i], f[i + 1]);
	}
	// loop over lengths
	for (int len = 3; len <= n; ++len)
	{
		// loop over starting point
		for (int i = 0; i <= n - len; ++i)
		{
			const int my_range = range_sum(i, i + len - 1);
			int & cur = memo[i][i + len - 1];
			cur = INF;
			// loop over candidate roots
			for (int k = i; k < i + len; ++k)
			{
				cur = min(cur, memo[i][k - 1] + memo[k + 1][i + len - 1] + my_range - f[k]);
			}
		}
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
		solve();
		printf("%d\n", memo[0][n-1]);
	}
}

