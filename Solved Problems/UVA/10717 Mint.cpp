#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, t;
ll goal;
ll coin[55];
ll x, y;
inline ll lcm(const ll i, const ll j){
	return i * ((ll)j / __gcd(i, j));
}
inline void solve(void){
	x = 0LL; y = INT_MAX;
	for (int i = 0; i < n; ++i)
	for (int j = i + 1; j < n; ++j)
	for (int k = j + 1; k < n; ++k)
	for (int h = k + 1; h < n; ++h){
		ll v = lcm(coin[i], coin[j]);
		v = lcm(v, coin[k]);
		v = lcm(v, coin[h]);
		if (!(goal % v)){
			x = y = goal;
			return;
		}
		x = max(x, (ll)(goal/v)*v);
		y = min(y, (ll)(goal/v + 1)*v);
	}
}
inline void read_coin(void){
	for (int i = 0; i < n; ++i)
	scanf("%lld", coin + i);
}
int main() {
	while(scanf("%d%d", &n, &t), n || t){
		read_coin();
		for (int i = 0; i < t ;++i){
			scanf("%lld", &goal);
			solve();
			printf("%lld %lld\n", x, y);
		}
	}
	return 0;
}