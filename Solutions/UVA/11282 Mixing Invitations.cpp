#include<bits/stdc++.h>
#define MAX 22
using namespace std;
typedef long long int ll;
ll memo[MAX][MAX][MAX];
ll fact[MAX];
/* count the number of ways of matching
 * knowing that you have n invitations and n envelopes
 * only the first k invitations have corresponding envelopes
 * knowing that out of those n envelopes, only the first k have corresponding invitations
 * such that there are less than m invitations matched correctly
 * */
inline ll dp(const int n, const int k, const int m)
{
	// memorization
	ll & ret = memo[n][k][m];
	if (ret != -1LL)
	{
		return ret;
	}
	// base case
	if (!n)
	{
		// no more invitations
		return ret = 1LL;
	}
	if (!k)
	{
		// every permutation works
		return ret = fact[n];
	}
	// match it wrongly
	ret = 0LL;
	if (k > 1)
	{
		ret = (k - 1) * dp(n - 1, k - 2, m);
	}
	ret += (n - k) * dp(n - 1, k - 1, m);
	if (!m)
	{
		// can only match it wrongly
		return ret;
	}
	// match it correctly
	return ret += dp(n - 1, k - 1, m - 1);
}
inline void init_fac()
{
	fact[0] = 1LL;
	for (ll i = 1; i < MAX; ++i)
	{
		fact[i] = i * fact[i - 1];
	}
}
inline void test(void)
{
	for (int n = 0; n <= 20; ++n)
		for (int m = 0; m <= n; ++m)
		{
			printf("%d %d %lld\n", n, m, dp(n, n, m));
		}
}
int main(void)
{
	memset(memo, -1, sizeof memo);
	init_fac();
	for (int n, m; ~scanf("%d%d", &n, &m);)
	{
		printf("%lld\n", dp(n, n, m));
	}
	return 0;
}

