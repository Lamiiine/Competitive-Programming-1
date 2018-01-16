#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll power[27];
ll memo[27][160];
/* memo[i][j] = number of ways of obtaining a value >= j
 * if you have i dice left */
inline void init(void){
	power[0] = 1LL;
	for (int i = 1; i <= 26; ++i)
		power[i] = 6LL * power[i - 1];
}
inline ll dp(int i, int j){
	// don't let i go below 1
	if (j <= 0) return power[i];
	ll & ret = memo[i][j];
	if (ret != -1LL) return ret;
	if (i == 1) return ret = max(0, 6 - j + 1);	// only one dice left
	ll ans = 0LL;
	for (int v = 1; v <= 6; ++v)
		ans += dp(i - 1, j - v);
	return ret = ans;
}
inline void normalize(ll & i, ll & j){
	const ll g = __gcd(i, j);
	i /= g; j /= g;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	int n, m;
	while(scanf("%d%d", &n, &m), n | m){
		memset(memo, 0xFF, sizeof memo);
		memo[0][0] = 1LL;
		ll a = dp(n, m), b = power[n];
		normalize(a, b);
		if (b != 1LL)
		printf("%lld/%lld\n", a, b);
		else printf("%lld\n", a);
	}
	return 0;
}

