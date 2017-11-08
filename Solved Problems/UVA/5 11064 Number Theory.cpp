#include<bits/stdc++.h>
#define MAX (1 << 16)
using namespace std;
typedef long long int ll;
vector<ll> primes;
inline void sieve(void)
{
	bitset<MAX + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= MAX; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j <= MAX; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}
inline ll solve(ll x)
{
	ll euler_phi = x;
	ll num_div = 1LL;
	for (ll i = 0, p = 2LL; p * p <= x; p = primes[++i])
	{
		ll counter = 0LL;
		while(x % p == 0) x /= p, ++counter;
		if (counter)
		{
			euler_phi -= euler_phi / p;
			num_div *= (counter + 1LL);
		}
	}

	if (x != 1)
	{
		euler_phi -= euler_phi / x;
		num_div <<= 1LL;
	}

	return euler_phi + num_div;
}
int main(void)
{
	sieve();
	for (ll x; ~scanf("%lld", &x); )
	{
		printf("%lld\n", x + 1LL - solve(x));
	}
	return 0;
}

