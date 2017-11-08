#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector<ll>primes;
ll a, b, m;
inline void sieve(void)
{
	primes.reserve(MAX / log(MAX));
	bitset<MAX + 10> bs;
	bs.set();
	for (ll i = 2LL; i <= MAX; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j <= MAX; j += i)
			{
				bs[j] = 0;
			}
		}
}
inline ii solve(void)
{
	ll ans_area = 0, ans_p, ans_q;
	for (int i = 0; i < primes.size(); ++i)
	{
		ll p = primes[i];
		if (p * p > m)
		{
			break;
		}
		for (int j = i; j < primes.size(); ++j)
		{
			ll q = primes[j];
			ll area = p * q;
			if (area > m)
			{
				break;
			}
			else if (p * b >= a * q && area > ans_area)
			{
				ans_p = p;
				ans_q = q;
				ans_area = area;
			}
		}
	}
	return ii(ans_p, ans_q);
}
int main(void)
{
	sieve();
	while(scanf("%lld%lld%lld", &m, &a, &b), m || a || b)
	{
		ii ans = solve();
		printf("%lld %lld\n", ans.first, ans.second);
	}
	return 0;
}

