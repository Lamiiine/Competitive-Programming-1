#include<bits/stdc++.h>
#define MAX 35
using namespace std;
typedef long long int ll;
int d, g;
ll memo[MAX * 2][MAX][MAX][2][2];
/* number of ways of making a schedule knowing that you have
 * worked for i days, j of which were assigned to project 0
 *
 * you last worked for k days on project t
 * you started with project start
 */
inline ll dp(const int i, const int j, const int k, const int t, const int start)
{
	ll & ret = memo[i][j][k][t][start];
	if (ret != -1LL)
	{
		return ret;
	}
	if (i > (d << 1) || j > d || i - j > d)
	{
		return ret = 0;
	}
	if (k > g)
	{
		// the other project has to be empty!
		if ((t && j < d) || (!t && (i - j) < d))
		{
			return ret = 0;
		}
	}
	if (i == (d << 1))
	{
		// no more days
		return ret = (j == d && t != start);
	}
	if (j == d)
	{
		// have to assign all the remaining days to project 1
		return ret = (start == 0);
	}
	if (i - j == d)
	{
		return ret = (start == 1);
	}
	if (k == g)
	{
		// have to switch project
		if (t)
		{
			// assign it to project 0
			return ret = dp(i + 1, j + 1, 1, 0, start);
		}
		else
		{
			// assign it to project 1
			return ret = dp(i + 1, j, 1, 1, start);
		}
	}
	// assign it to 1 or 2
	if (t)
	{
		return ret = dp(i + 1, j + 1, 1, 0, start) + dp(i + 1, j, k + 1, 1, start);
	}
	else
	{
		return ret = dp(i + 1, j + 1, k + 1, 0, start) + dp(i + 1, j, 1, 1, start);
	}
}
int main(void)
{
	for(int tc = 1; scanf("%d%d", &d, &g), d != -1 && g != -1; ++tc)
	{
		memset(memo, -1, sizeof memo);
		printf("Case %d: %lld\n", tc, dp(1, 1, 1, 0, 0) + dp(1, 0, 1, 1, 1));
	}
	return 0;
}

