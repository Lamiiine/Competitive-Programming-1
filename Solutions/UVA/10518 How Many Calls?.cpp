#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, b;
ll base[3][3];
ll ans[3][3];
ll temp[3][3];
inline void mul(ll x[][3], const ll y[][3], const ll z[][3]){
	memset(temp, 0, sizeof temp);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			ll & v = temp[i][j];
			for (int k = 0; k < 3; ++k)
				v = (v + y[i][k]*z[k][j]) % b;
		}
	memcpy(x, temp, sizeof temp);
}
inline void raise(ll p){
	for (;p; p >>= 1LL, mul(base, base, base))
		if (p & 1LL) mul(ans, ans, base);
}
inline void init(void){
	// initialzie base
	memset(base, 0, sizeof base);
	base[0][1] = 1LL;
	base[1][0] = base[1][1] = base[1][2] = 1LL;
	base[2][2] = 1LL;
	// initialize answer
	memset(ans, 0, sizeof ans);
	for (int i = 0; i < 3; ++i)
		ans[i][i] = 1LL;
}
int main(void){
	for(int tc = 1; scanf("%lld%lld", &n, &b), n || b; ++tc){
		init();
		raise(n);
		ll ret = (ans[0][0] + ans[0][1] + ans[0][2]) % b;
		printf("Case %d: %lld %lld %lld\n", tc, n, b, ret);
	}
	return 0;
}

