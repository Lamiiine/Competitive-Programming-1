#include<bits/stdc++.h>
#define MAX 1000000
#define CONF 50
#define MAX_ITER 100000
#define abs_val(a) (((a)>0)?(a):-(a))
using namespace std;
typedef long long int ll;

inline ll raise_mod(ll x, ll n, ll p) {
	/* return x^n % p
	 * Unless you perform multiplication manually,
	 * x should be no larger than sqrt(LLONG_MAX) ~ 2*10^9+
	*/
	ll ans = 1LL;
	for (x = x % p; n; n >>= 1, x = (x * x) % p)
		if (n & 1LL)
			ans = (ans * x) % p;
	return ans;
}
inline bool witness(ll a, ll n) {
	/* Is 'a' a witness to the compositeness of 'n'??
	 * Unless you perform multiplication manually,
	 * x should be no larger than sqrt(LLONG_MAX) ~ 2*10^9+
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

vector<ll> primes;
ll mulmod(ll a, ll b, ll c) { // returns (a * b) % c, and minimize overflow
	ll x = 0, y = a % c;
	while (b > 0)
	{
		if (b % 2 == 1)
			x = (x + y) % c;
		y = (y * 2) % c;
		b /= 2;
	}
	return x % c;
}
ll gcd(ll a, ll b) {
	return !b ? a : gcd(b, a % b);
}

ll pollard_rho(ll n)
{
	int i = 0, k = 2;
	ll x = 7, y = 7; // random seed = , other values possible
	// for (int iter = 0; iter < MAX_ITER; ++iter)
	for (int iter = 0; iter < MAX; ++iter)
	{
		i++;
		x = (mulmod(x, x, n) + n - 1) % n; // generating function
		ll d = gcd(abs_val(y - x), n); // the key insight
		if (d != 1 && d != n)
			return d; // found one non-trivial factor
		if (i == k)
			y = x, k *= 2;
	}

	return n;
}
inline void sieve(void) {
	primes.reserve(MAX / log(MAX));
	bitset<MAX + 10> bs;
	bs.set();
	for (ll i = 2; i <= MAX; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			for (ll j = i * i; j <= MAX; j += i)
				bs[j] = 0;
		}
}

multiset<ll> s;
inline ll prime_factorize(ll x) {
	ll p;
	for (int i = 0; i < primes.size(); ++i)
	{
		p = primes[i];
		while (x % p == 0)
		{
			x /= p;
			s.insert(p);
		}
		if (p * p > x)
		{
			// done
			if (x != 1LL)
				s.insert(x);
			return 1LL;
		}
	}

	return x;
}

inline void factorize(ll x)
{
	x = prime_factorize(x);
	if (x != 1LL)
	{
		if (miller_rabin(x, CONF))
		{
			s.insert(x);
		}
		else
		{
			ll y = pollard_rho(x);
			s.insert(y);
			if (y != x)
			s.insert(x / y);
		}
	}
}
inline void init() {
	s.clear();
}
int main(void) {
#ifdef ONLINE_JUDGE
	freopen("hope.in", "r", stdin);
#endif
	// printf("%lld\n", 1000000009LL * 1000000009LL);
	sieve();
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		init();
		int n;
		scanf("%d", &n);
		while (n--)
		{
			ll x;
			// scanf("%I64d", &x);
			scanf("%lld", &x);
			factorize(x);
		}

		int ans = 1;
		for (ll x : s) {
			ans = max(ans, (int) s.count(x));
		}

		printf("%d\n", ans);
	}
	return 0;
}
/*
2
4
2 4 8 16
3
2 7 11

1
1
1000000018000000081
 */

