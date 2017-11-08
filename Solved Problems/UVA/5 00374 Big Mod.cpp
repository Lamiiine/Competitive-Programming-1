#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll raise(ll x, ll p, ll MOD){	// return x^p
	ll ans = 1;
	for (; p; x = (x * x)%MOD, p >>= 1)
		if (p & 1LL) ans = (ans*x)%MOD;
	return ans;
}
int main(void){
	ll x, p, MOD;
	while(scanf("%lld%lld%lld", &x, &p, &MOD) != EOF)
		printf("%lld\n", raise(x, p, MOD));
	return 0;
}

