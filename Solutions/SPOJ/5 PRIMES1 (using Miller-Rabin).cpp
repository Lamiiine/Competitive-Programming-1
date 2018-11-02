#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
inline ll raise_mod(ll x, ll n, ll p) {
	// return x^n % p
	ll ans = 1LL;
	for (x = x % p; n; n >>= 1, x = (x * x) % p)
		if (n & 1LL)
			ans = (ans * x) % p;
	return ans;
}
// is 'a' a witness to the compositeness of 'n'?
inline bool witness(ll a, ll n) {
	/* - Unless you perform multiplication manually,
	 * x should be no larger that 2*10^9
	 * */
	ll u = n - 1;
	int t = 0;
	while (!(u & 1LL))
		++t, u >>= 1;
	ll x = raise_mod(a, u, n);
	if (x == 1LL)	// not a witness
		return false;
	for (int i = 0; i < t; ++i) {
		if (x == n - 1)
			return false;
		if (x == 1LL)
			return true;
		x = (x * x) % n;
	}
	return true;
	// if (x != 1LL) return true;
	// return false;
}
inline bool prime_force(ll x){
	for (ll p = 2; p*p <= x; ++p)
		if (x % p == 0) return false;
	return true;
}
inline bool miller_rabin(ll x, int s) {
	if (x <= 100) return prime_force(x);
	set<ll>S; S.insert(2LL);
	while(S.size() <= s)
		S.insert((ll) 3LL + rand() % (x - 3LL));
	for (set<ll>::iterator iter = S.begin(); iter != S.end(); ++iter)
		if (witness(*iter, x)) return false;
	return true;	// looks like a prime
}
ll reverse(ll x){
	ll ans = 0;
	while(x){
		ans = (ans * 10) + x % 10;
		x /= 10;
	}
	return ans;
}
int main(void) {
	srand(time(0));
	int TC; scanf("%d", &TC);
	while(TC--){
		ll n, m;
		scanf("%lld%lld", &n, &m);
		for (n = max(n, 2LL);n <= m; ++n)
			if (miller_rabin(n, 10))
				printf("%lld\n", n);
		printf("\n");
	}
	return 0;
}

