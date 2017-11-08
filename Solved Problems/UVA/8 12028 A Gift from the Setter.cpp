#include<bits/stdc++.h>
#define MAX 100100
#define MOD 1000007LL
using namespace std;
typedef long long int ll;
ll K, C;
int n;
ll a[MAX];
inline void generate(void)
{
	a[0] %= MOD;
	for (int i = 1; i < n; ++i)
	{
		a[i] = (K * a[i - 1] + C) % MOD;
	}
}
inline ll solve(void)
{
	ll ans = 0;
	sort(a, a + n);
	ll prev_sum = a[0];
	for (int i = 1; i < n; ++i)
	{
		ans += a[i] * i - prev_sum;
		prev_sum += a[i];
	}
	return ans;
}
int main(void)
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		scanf("%lld%lld%d%lld", &K, &C, &n, a);
		generate();
		printf("Case %d: %lld\n", tc, solve());
	}
	return 0;
}
/*
2
1 1 2 1
10 10 10 5
 */

