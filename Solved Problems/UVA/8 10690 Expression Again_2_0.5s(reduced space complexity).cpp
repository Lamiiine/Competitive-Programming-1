// same time complexity; smaller space complexity
// passed in 0.5 seconds
#include <bits/stdc++.h>
#define MAX 51
using namespace std;
bool memo[MAX][MAX*100];
int arr[MAX << 1];
int tot;
int n, m;
inline void read(void)
{
	tot = 0;
	for (int i = 0; i < (n + m); ++i)
	{
		scanf("%d", arr + i);
		tot += arr[i];
	}
}
/* memo[i][j] is true if and only if there exists a subset
of size i that sums up to j
Thus, this is a Knapsack-style solution
*/
inline void solve(void)
{
	memset(memo, 0, sizeof memo);
	memo[0][0] = 1;
	for (int i = 0; i < (n + m); ++i)
	{
		int cur = arr[i] + 50;
		// notice that I am adding 50 to every value to handle negative offsets
		for (int j = n; j >= 1; --j)
		{
			for (int k = cur; k < (5100); ++k)
			{
				if (memo[j - 1][k - cur])
				{
					/* if you have a subset of size j - 1 that sums up to x,
					and you found an element whose value is y
					then, you can get a subset of size j that sums up to x + y */
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
		for (int i = 0; i < 5100; ++i)
		{
			if (memo[n][i])
			{
				int cur = i - 50 * n;
				/* retrieve original value by
				removing the 50's you added initially */
				max_ans = max(max_ans, (tot - cur) * cur);
				min_ans = min(min_ans, (tot - cur) * cur);
			}
		}
		printf("%d %d\n", max_ans, min_ans);
	}
	return 0;
}
