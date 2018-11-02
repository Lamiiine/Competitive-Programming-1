#include <bits/stdc++.h>
#define MAX 20000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
vector<int> primes;
inline void sieve()
{
	bitset<MAX> bs; bs.set(); bs[0] = bs[1] = 0;
	for (int i = 2; i < MAX; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			for (int j = i * i; j < MAX; j += i)
				bs[j] = 0;
		}
}
inline vector<ii> factorize(int x)
{
	vector<ii> ans;
	for (int i = 0, p = primes[0]; p * p <= x; p = primes[++i])
	{
		int power = 0;
		while (x % p == 0) ++power, x /= p;
		if (power)
			ans.push_back(ii(p, power));
	}
	if (x != 1) ans.push_back(ii(x, 1));
	return ans;
}
ll power(ll p, ll n){
	ll ans = 0;
	ll temp = p;
	while(temp <= n)
		ans += n/temp, temp *= p;
	return ans;
}
inline ll solve(ll m, ll n)
{
	auto factors = factorize(m);
	ll ans = INT_MAX;
	for (const auto & factor : factors)
		ans = min(ans, power(factor.first, n) / factor.second);
	return ans == INT_MAX ? 0 : ans;
}
int main()
{
	sieve();
	int TC; scanf("%d", &TC);
	for (int m, n, tc = 1; tc <= TC; ++tc)
	{
		scanf("%d%d", &m, &n);
		const ll ans = solve(m, n);
		printf("Case %d:\n", tc);
		if (ans) printf("%lld", ans);
		else printf("Impossible to divide");
		printf("\n");
	}
	return 0;
}
/*
2
2 10
2 100
 */

