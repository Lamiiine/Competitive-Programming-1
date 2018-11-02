#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll cube(ll k){
	return k*(k*k);
}
ll m;
ll ans;
bool can (ll n){
	// count the number of sequences if you have capacity n
	ans = 0LL;
	for (ll k = 2LL;; ++k){
		ll t = cube(k);
		ll i = n/t;
		if (!i) break;
		ans += i;
	}
	return ans >= m;
}
int main(void){
	cin >> m;
	ll lo = 0, hi = (1LL << 63LL) - 1LL;
	while(lo != hi){
		// minimize n
		ll mid = min((lo + hi)/2LL, hi - 1);
		if (can(mid))
			hi = mid;
		else lo = mid + 1;
	}
	can(lo);
	if (ans == m) cout << lo;
	else cout << -1;
	return 0;
}

