#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>primes;
inline void sieve(void)
{
	const ll upper_bound = 50000;
	bitset<upper_bound + 10LL> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= upper_bound; ++i)
	if (bs[i])
	{
		primes.push_back(i);
		for (ll j = i * i; j <= upper_bound; j += i)
			bs[j] = 0;
	}
}
inline ll jo(const ll x, const int i)
{
	return (x == 1LL) ? 0LL : (jo(x - 1, i + 1) + primes[i]) % x;
}
int main() {
	sieve();
	for (ll x; scanf("%lld", &x), x; )
	{
		printf("%lld\n", jo(x, 0) + 1LL);
	}
	return 0;
}