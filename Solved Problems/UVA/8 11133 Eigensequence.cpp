#include<bits/stdc++.h>
#define MAX 46
using namespace std;
int memo[MAX][MAX];
inline bool valid(const int i, const int k)
{
	const int diff = k - i;
	for (int x = i + 1; x < k; ++x)
	{
		if (x % diff == 0)
		{
			return false;
		}
	}
	return k % diff == 0;
}
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j];
	if (ret != -1)
	{
		return ret;
	}
	if (i == j)
	{
		return ret = 1;
	}
	ret = 0;
	for (int k = i + 1; k <= j; ++k)
	{
		if (valid(i, k))
		{
			ret += dp(k, j);
		}
	}
	return ret;
}
int main(void)
{
	memset(memo, -1, sizeof memo);
	for (int x, y; scanf("%d%d", &x, &y), x || y; printf("%d %d %d\n", x, y, dp(x, y)));
	return 0;
}

