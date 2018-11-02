#include<bits/stdc++.h>
#define MAX 15
#define lsone(s) ((s) & (-s))
using namespace std;
typedef long long int ll;
inline int count_ones(int mask)
{
	int ans = 0;
	while(mask)
	{
		++ans;
		mask -= lsone(mask);
	}
	return ans;
}
int match[MAX][MAX];
int n;
ll memo[1 << MAX][2][2];
inline ll dp(const int mask, const int fail_flag, const int sup_flag)
{
	// memory
	ll & ret = memo[mask][fail_flag][sup_flag];
	if (ret != -1LL)
	{
		return ret;
	}

	// base case
	const int i = count_ones(mask);
	if (i == n)
	{
		return ret = (sup_flag || !fail_flag) ? 1LL : 0LL;
	}

	// recursion
	ret = 0;
	for (int j = 0; j < n; ++j)
	{
		if (!(mask & (1 << j)))
		{
			// free dress!
			ret += dp(mask | (1 << j), fail_flag || !match[i][j], sup_flag || (match[i][j] == 2));
		}
	}

	return ret;
}
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", match[i] + j);
		}
	}
}
inline void init_memo(void)
{
	memset(memo, -1, sizeof memo);
}
int main(void)
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		read();
		init_memo();
		printf("Case %d: %lld\n", tc, dp(0, 0, 0));
	}
	return 0;
}

