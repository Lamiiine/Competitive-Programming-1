#include <bits/stdc++.h>
#define MAX 1002
#define MOD 1000000007
using namespace std;
int n, a[MAX];
int memo[MAX][MAX * 10 * 2];
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j + MAX * 10];
	if (ret != -1) return ret;
	ret = (j == 0);
	if (i < n)
	{
		ret = (ret + dp(i + 1, j - a[i])) % MOD;
		ret = (ret + dp(i + 1, j + a[i])) % MOD;
	}
	return ret;
}
inline void init()
{
	memset(memo, -1, sizeof memo);
}
inline void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
}
int main()
{
	read();
	init();
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ans + dp(i, 0) - 1) % MOD;
	printf("%d", ans);
	return 0;
}
/*
4
1 1 1 1
 */

