#include<stdio.h>
using namespace std;
typedef long long int ll;
ll n, k, mod;
ll a;
inline ll pow_mod(ll n, ll k, ll mod){
	ll ans = 1;
	for (n = n % mod; k; k >>= 1, n = (n*n) % mod)
		if (k & 1LL) ans = (ans * n) % mod;
	return ans;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	// freopen("Output.txt", "w", stdout);
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		// n ^ k
		scanf("%d%d%d", &n, &k, &mod);
		a = 0LL;
		{
			ll x;
			for (int i = 0; i < n; ++i)
				scanf("%lld", &x), a = (a + x) % mod;
		}
		printf("Case %d: %lld\n", tc, (k*a*pow_mod(n, k - 1, mod)) % mod);
	}
	return 0;
}