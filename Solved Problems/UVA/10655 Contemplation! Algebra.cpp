#include<bits/stdc++.h>
#define NUM 2
using namespace std;
typedef long long int ll;
ll p, q, n;
ll base[NUM][NUM];
ll ans[NUM][NUM];
ll temp[NUM][NUM];
inline void mul(ll x[][NUM], const ll y[][NUM], const ll z[][NUM]){
	// you need to use a temporary storage, in case x == y || x == z
	memset(temp, 0, sizeof temp);
	for (int i = 0; i < NUM; ++i)
		for (int j = 0; j < NUM; ++j)
		{
			ll & v = temp[i][j];
			for (int k = 0; k < NUM; ++k)
				v = (v + y[i][k]*z[k][j]);
		}
	memcpy(x, temp, sizeof temp);
}
inline void raise(ll power){
	// initialize answer with identity matrix
	memset(ans, 0, sizeof ans);
	for (int i = 0; i < NUM; ++i)
		ans[i][i] = 1LL;
	// compute base^p
	for (;power; power >>= 1LL, mul(base, base, base))
		if (power & 1LL) mul(ans, ans, base);
}
inline void init_base(void){
	base[0][0] = 0LL;
	base[0][1] = 1LL;
	base[1][0] = -q;	// ab
	base[1][1] = p;	// a + b
}
int main(void){
	while(true){
		scanf("%lld%lld", &p, &q);
		if ((!p & !q) & (scanf("%lld", &n) == EOF)) break;
		init_base();
		raise(n);
		printf("%lld\n", 2LL*ans[0][0] + p*ans[0][1]);
	}
	return 0;
}

