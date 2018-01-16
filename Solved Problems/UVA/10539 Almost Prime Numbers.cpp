#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>primes;
inline void sieve(void){
	bitset<1000100> bs;
	bs.set();
	for (ll i = 2; i < 1000000LL; ++i)
		if (bs[i]){
			primes.push_back(i);
			for (ll j = i*i; j < 1000000LL; j += i)
				bs[j] = 0;
		}
}
int main(void){
	sieve();
	int TC; scanf("%d", &TC);
	for(ll a, b; TC--;){
		scanf("%lld%lld", &a, &b);
		ll answer = 0LL;
		for (ll i = 0, p = 2; p*p <= b; p = primes[++i])
		{
			ll x = p*p;
			while(x < a) x *= p;
			while(x <= b){
				++answer;
				x *= p;
			}
		}
		printf("%lld\n", answer);
	}
	return 0;
}

