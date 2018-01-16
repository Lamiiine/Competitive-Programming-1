#include<bits/stdc++.h>
#define MAX 1000010
using namespace std;
typedef long long int ll;
ll memo[MAX];
ll sum(ll n){
	return (n*(n + 1)) >> 1;
}
ll solve_odd(ll n){
	return 2LL * sum(n >> 1LL) + ((n >> 1LL) + 1LL);
}
ll solve_even(ll n){
	return 2LL * sum(n >> 1LL);
}
inline ll solve(ll n){
	if (n & 1LL) return solve_odd(n);
	return solve_even(n);
}
inline void init(void){
	memo[3] = 0;
	for (ll i = 4; i < MAX; ++i)
		memo[i] = memo[i - 1] + solve(i - 3);
}
int main(void){
	init();
	for (int n; scanf("%d", &n), n >= 3; printf("%lld\n", memo[n]));
	return 0;
}

