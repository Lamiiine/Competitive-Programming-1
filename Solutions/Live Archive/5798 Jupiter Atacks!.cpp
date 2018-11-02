#include<bits/stdc++.h>
#define MAX 100100
#define left(s) ((s) << 1)
#define right(s) (((s) << 1) + 1)
#define avg(a, b) (( (a) + (b) ) >> 1)
using namespace std;
typedef long long int ll;
ll st[MAX << 2];
ll B, P;
int L, N;
inline ll raise_mod(ll n){
	// return x^n % q
	ll ans = 1LL;
	for (ll x = B; n; n >>= 1, x = (x * x) % P)
		if (n & 1LL) ans = (ans * x) % P;
	return ans;
}
int update_index;
int update_value;
inline void update(int p, int l, int r){
	if (l > update_index || r < update_index) return;
	if (l == r){
		st[p] = (ll)update_value % P;
	}
	else {
		update(left(p), l, avg(l, r));
		update(right(p), avg(l, r) + 1, r);
		st[p] = (st[left(p)]*raise_mod(r - avg(l, r)) + st[right(p)]) % P;
	}
}
int i, j;
inline ll query(int p, int l, int r){
	if (l > j || r < i) return 0LL;
	if (l >= i && r <= j) return st[p];
	return (query(left(p), l, avg(l, r))*raise_mod(max(0, min(r, j) - avg(l, r))) + query(right(p), avg(l, r) + 1, r)) % P;
}
char command[5];
int main(void){
	while(scanf("%lld%lld%d%d", &B, &P, &L, &N), B || P || L || N){
		memset(st, 0, sizeof st);
		for(int x, y; N--;){
			scanf("%s%d%d", command, &x, &y);
			if (!strcmp(command, "E")){
				update_index = x;
				update_value = y;
				update(1, 1, L);
			}
			else {
				i = x;
				j = y;
				printf("%lld\n", query(1, 1, L));
			}
		}
		printf("-\n");
	}
	return 0;
}

