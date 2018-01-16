#include <bits/stdc++.h>
#define MAX 25
using namespace std;
typedef long long int ll;
ll memo[MAX][MAX][2];
/* number of ways of ordering i people
j of them are shorter than you
knowing that the next person has to be taller iff k == true
*/
inline ll dp(const int i, const int j, const int k)
{
	// printf("%d %d %d\n", i, j, k);
	ll & ret = memo[i][j][k];
	if (ret != -1LL)
	{
		return ret;
	}
	if (i == 0)
	{
		return ret = 1;
	}
	ret = 0;
	if (k)	// next person should be taller
	{
		// 1 -> i
		// j + 1 -> i are valid next persons
		for (int t = j + 1; t <= i; ++t)
		{
			ret += dp(i - 1, t - 1, false);
		}
	}
	else
	{
		for (int t = 1; t <= j; ++t)
		{
			ret += dp(i - 1, t - 1, true);
		}
	}
	return ret;
}
int main(void)
{
	memset(memo, 0xFF, sizeof memo);
	for (int n, m; ~scanf("%d%d", &n, &m);)
	{
		ll ans = 0;
		if (m == 1)
		{
			if (n <= 2)
			{
				ans = 1;
			}
			else
			{
				ans = 0;
				int next = 2;
				while(next <= n && ans == 0)
				{
					ans = dp(n - 2, next - 2, false);
					++next;
				}
			}
		}
		else
		{
			ans = dp(n - 1, m - 1, false);
		}
		printf("%lld\n", ans);
	}
}