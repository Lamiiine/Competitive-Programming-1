#include<bits/stdc++.h>
#define MAX 1000000LL
using namespace std;
typedef long long int ll;
vector<ll> primes;
inline void sieve(void)
{
	bitset<MAX + 10LL> bs;
	bs.set();
	for (ll i = 2LL; i <= MAX; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j <= MAX; j += i)
				bs[j] = 0;
		}
}
inline bool composite_prime(ll x)
{
	int counter = 0;
	for (ll i = 0, p = primes[0]; p * p <= x; p = primes[++i])
	{
		while(x % p == 0) ++counter, x /= p;
		if (counter > 2) return false;
	}
	if (x != 1) ++counter;
	return counter == 2;
}
int main(void)
{
	sieve();
	int n;
	for(int ans = 0; ~scanf("%d", &n); ans = 0)
	{
		for(int a; n--;)
			scanf("%d", &a), ans += composite_prime(a);
		printf("%d\n", ans);
	}
	return 0;
}

