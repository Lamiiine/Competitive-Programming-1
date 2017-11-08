#include <bits/stdc++.h>
#define MAX 103
using namespace std;
int t[MAX], b[MAX];
int memo[MAX][MAX*MAX];
int n;
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j];
	if (ret != -1)
		return ret;
	if (i == n)
		return ret = 0;
	return ret = min(t[i] + dp(i + 1, j + b[i]), !j ? INT_MAX : (t[i] >> 1) + dp(i + 1, j + b[i] - 1));
}
inline void read(void)
{
	for (int i = 0; i < n; ++i)
	scanf("%d%d", t + i, b + i);
}
int main(void)
{
	while(scanf("%d", &n), n)
	{
		read();
		memset(memo, 0xFF, sizeof memo);
		printf("%d\n", dp(0, 0));
	}
	return 0;
}