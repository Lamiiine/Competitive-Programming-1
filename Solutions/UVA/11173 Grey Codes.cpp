#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	int TC; scanf("%d", &TC);
	for(ll n, k; TC--; )
	{
		scanf("%lld%lld", &n, &k);
		// printf("%d\n", k ^ (k >> 1));
		// this can be the answer
		ll ans = 0LL;
		for (ll i = n - 1; i >= 0LL; --i)
		{
			const ll period = 1LL << (i + 2LL);
			const ll cur = (k % period) / (period >> 2);
			if (cur == 1LL || cur == 2LL)
				ans |= (1LL << i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}



