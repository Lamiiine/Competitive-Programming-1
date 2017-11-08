#include<bits/stdc++.h>
#define MAX 102
using namespace std;
int n, arr[MAX][MAX];
int ans;
inline void read(void)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", arr[i] + j), ans = max(ans, arr[i][j]);
}
inline void acc(void)
{
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < n; ++j)
			arr[i][j] += arr[i - 1][j];
}
inline void solve(void)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			int cur = 0;
			for (int k = 0; k < n; ++k)
			{
				cur = (arr[j][k] - (i ? arr[i - 1][k] : 0)) + max(cur, 0);
				ans = max(ans, cur);
			}
		}
	}
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.in", "r", stdin);
#endif
	while(~scanf("%d", &n))
	{
		ans = INT_MIN;
		read();
		acc();
		solve();
		printf("%d\n", ans);
	}
	return 0;
}

