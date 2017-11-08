#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char s[1000];
ll parse(void){
	ll n = strlen(s);
	ll ans = 0LL;
	for (ll i = 0; i < n; ++i)
		ans += (ll)(s[i] - '0')*((1LL << (n - i)) - 1LL);
	return ans;
}
int main(void){
	while(scanf("%s", s), strcmp(s, "0"))
		printf("%lld\n", parse());
	return 0;
}

