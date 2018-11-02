#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
vll primes;
inline void sieve(void){
	const ll upper_bound = 1 << 18;
	primes.reserve(upper_bound/log(upper_bound));
	bitset<upper_bound> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2LL; i <= upper_bound; ++i)
		if (bs[i]){
			primes.push_back(i);
			for (ll j = i * i; j <= upper_bound; j += i)
				 bs[j] = 0;
		}
}
inline ll num_div(ll x){
	ll ans = 1LL;
	for (ll i = 0, p = 2; p * p <= x; p = primes[++i])
		if (x % p == 0){
			int counter = 1;
			x /= p;
			while(x % p == 0) x /= p, ++counter;
			ans *= (counter + 1);
		}
	if (x != 1LL) ans <<= 1;
	return ans;
}
int main(void){
	sieve();
	for (ll x; scanf("%lld", &x), x; printf("%s\n", num_div(x) & 1 ? "yes" : "no"));
	return 0;
}

