#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
vi primes;
inline void sieve(void){
	primes.reserve(MAX/log(MAX));
	bitset<MAX + 10>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= MAX; ++i)
		if (bs[i]){
			primes.push_back(i);
			if ((ll) i*i <= MAX)
				for (int j = i*i; j <= MAX; j += i)
					bs[j] = 0;
		}
}
ll ans;
inline void factorize(ll x, vi & v){
	ans = -1LL;
	for (int i = 0, p = primes[0]; (ll)p*p <= x; p = primes[++i])
		if (x % p == 0){
			v.push_back(p);
			x /= p;
			while(x % p == 0) x /= p;
		}
	if (x != 1LL) ans = x;
}
inline ll solve(ll x){
	vi v;
	factorize(x, v);
	int num = v.size() + (ans != -1LL);
	if (num < 2) return -1LL;
	return max(ans, (ll)v.back());
}
int main(void){
	sieve();
	for (ll x; scanf("%lld", &x), x; printf("%lld\n", solve(abs(x))));
	return 0;
}

