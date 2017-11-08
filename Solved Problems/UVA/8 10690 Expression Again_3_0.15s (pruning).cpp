// same as the second knapsack solution, but added some pruning
// passed in 0.15 seconds
#include <bits/stdc++.h>
#define MAX 51
using namespace std;
bool memo[MAX][MAX*100];
int arr[MAX << 1];
int acc[MAX << 1];
int n, m;
inline void read(void)
{
	for (int i = 0; i < (n + m); ++i)
	{
		scanf("%d", arr + i);
	}
	acc[0] = arr[0] + 50;
	for (int i = 1; i < n + m; ++i)
		acc[i] = acc[i - 1] + arr[i] + 50;
}
inline void solve(void)
{
	memset(memo, 0, sizeof memo);
	memo[0][0] = 1;
	for (int i = 0; i < (n + m); ++i)
	{
		int cur = arr[i] + 50;
		// smaller range
		for (int j = min(n, i + 1); j >= 1; --j)
		{
			// smaller range
			for (int k = cur; k <= acc[i]; ++k)
			{
				if (memo[j - 1][k - cur])
				{
					memo[j][k] = 1;
				}
			}
		}
	}
}
int main() {
	while(~scanf("%d%d", &n, &m))
	{
		read();
		solve();
		int max_ans = INT_MIN, min_ans = INT_MAX;
		int tot = acc[n + m - 1] - 50 * (n + m);
		for (int i = 0; i < 5100; ++i)
		{
			if (memo[n][i])
			{
				int cur = i - 50 * n;
				max_ans = max(max_ans, (tot - cur) * cur);
				min_ans = min(min_ans, (tot - cur) * cur);
			}
		}
		printf("%d %d\n", max_ans, min_ans);
	}
	return 0;
}
