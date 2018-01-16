#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n, m;
/* memo[i][j][k] is the number of beautiful numbers
 * with a prefix consisting of i digits, where the last
 * of those digits is j, knowing that those digits use
 * the digits turned on in k
*/
int memo[102][10][1 << 10];
int ok;
inline int dp(const int index, const int prev, const int mask)
{
	int & ret = memo[index][prev][mask];
	if (ret != -1)
	{
		return ret;
	}
	if (index == m)
	{
		// exceeded number of digits
		return ret = (mask == ok) ? 1 : 0;
	}
	ret = (mask == ok);
	if (prev != 0)
	{
		ret = (ret + dp(index + 1, prev - 1, mask | (1 << (prev - 1)))) % MOD;
	}
	if (prev != n - 1)
	{
		ret = (ret + dp(index + 1, prev + 1, mask | (1 << (prev + 1))))  % MOD;
	}
	return ret;
}
inline void init_memo(void)
{
	memset(memo, -1, sizeof memo);
	ok = (1 << n) - 1;
}
int main() {
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d%d", &n, &m);
		if (m < n)
		{
			printf("0\n");
			continue;
		}
		init_memo();
		int ans = 0;
		for (int i = 1; i < n; ++i)
		{
			ans = (ans + dp(1, i, 1 << i)) % MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}
