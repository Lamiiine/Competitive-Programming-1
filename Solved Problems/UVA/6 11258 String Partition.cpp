#include<bits/stdc++.h>
#define MAX 205
using namespace std;
typedef long long int ll;
int len;
char s[MAX];
ll memo[MAX];
ll dp(int i){
	ll & ret = memo[i];
	if (ret != -1LL) return ret;
	ll ans = 0LL;
	for (ll p = 0; i < len; ++i)
	{
		p = (10LL * p) + s[i];
		if ((ll) p > INT_MAX) break;
		ans = max(ans, p + dp(i + 1));
	}
	return ret = ans;
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	len = strlen(s);
	memo[len] = memo[len + 1] = 0LL;
	for (int i = 0; i < len; ++i)
		s[i] -= '0';
}
inline void read(void){
	scanf("%s", s);
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		read();
		init();
		printf("%lld\n", dp(0));
	}
	return 0;
}

