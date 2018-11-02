#include<bits/stdc++.h>
#define MAX 102
using namespace std;
int arr[MAX], acc[MAX], n;
bool memo[MAX*500];
/*
 * memo[i] == true if and only if there exists a subset
 * summing up to i
 */
inline void solve(void)
{
	memset(memo, 0, sizeof memo);
	memo[0] = 1;
	for (int i = 0; i < n; ++i)
		// 1. you have to go in backward direction
		// 2. notice that I have minimized the range
		for (int j = acc[i]; j >= arr[i]; --j)
			memo[j] |= memo[j - arr[i]];
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		acc[0] = arr[0];
		for (int i = 1; i < n; ++i)
			acc[i] = acc[i - 1] + arr[i];
		int ans = INT_MAX;
		solve();
		for (int i = 0; i <= acc[n - 1]; ++i)
			if (memo[i])
				ans = min(ans, abs(i - (acc[n - 1] - i)));
		printf("%d\n", ans);
	}
}
/*
2
3
2 3 5
4
1 2 4 6
 */

