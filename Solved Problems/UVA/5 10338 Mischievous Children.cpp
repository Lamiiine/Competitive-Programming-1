#include<bits/stdc++.h>
using namespace std;
char s[1 << 5];
int counter[1 << 5];
typedef long long int ll;
ll fact[1 << 5];
inline void init(void){
	fact[0] = 1;
	for (int i = 1; i < 32; ++i)
		fact[i] = i * fact[i-1];
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		memset(counter, 0, sizeof counter);
		scanf("%s", s);
		int n;
		for (n = 0; s[n]; ++n)
			++counter[s[n] - 'A'];
		ll ans = fact[n];
		for (int i =0; i < 26; ++i)
			ans /= fact[counter[i]];
		printf("Data set %d: %lld\n", tc, ans);
	}
	return 0;
}

