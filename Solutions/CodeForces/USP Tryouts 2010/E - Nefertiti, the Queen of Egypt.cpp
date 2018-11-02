#include<bits/stdc++.h>
#define MAX_K 6
#define MOD 1000000007LL
using namespace std;
typedef long long int ll;
int k, n;
ll memo[205][1 << 14];
ll dp(const int i, const int mask)
{
	ll & ret = memo[i][mask];
	if (ret != -1LL) return ret;
	if (i == n) return ret = 1LL;	// base case!
	if (!(mask & 1))
		return ret = dp(i + 1, mask >> 1);
	ret = 0LL;
	for (int t = -k + 1; t <= k; ++t)
	{
		if ((t + i) >= 0 && (t + i) < n && !(mask & (1 << (t + k))))
		{
			// you can use this value!
			ret = (ret + dp(i + 1, (mask | (1 << (t + k))) >> 1)) % MOD;
		}
	}

	return ret;
}
int main(void)
{
	cin >> k;
	for (n = 1; n <= 200; ++n)
	{
		memset(memo, -1, (1 << 14) * (n + 3) * sizeof (ll));
		cout << dp(0, (1 << k) - 1) << '\n';
	}
	return 0;
}

