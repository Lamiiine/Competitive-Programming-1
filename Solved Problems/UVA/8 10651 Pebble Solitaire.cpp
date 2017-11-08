#include<bits/stdc++.h>
#define lsone(i) ((i) & (-i))
using namespace std;
inline int count_ones(int i){
	int ans = 0;
	while(i) ++ans, i -= lsone(i);
	return ans;
}
int memo[1 << 12];
inline void init_memo(void){
	memset(memo, 0xFF, sizeof memo);
}
char s[20];
inline int read(void){
	int k = 0;
	scanf("%s", s);
	for (int i = 0; i < 12; ++i)
		if (s[i] == 'o') k |= (1 << i);
	return k;
}
inline int dp(const int k){
	int & ret = memo[k];
	if (ret != -1) return ret;
	int ans = count_ones(k);
	for (int i = 0; i < 10; ++i){
		int x = (k & (7 << i)) >> i;
		if (x == 3)
			ans = min(ans, dp((k & (~(7 << i))) | (1 << (i + 2))));
		if (x == 6)
			ans = min(ans, dp((k & (~(7 << i))) | (1 << i)));
	}
	// ans = min(ans, dp())
	return ret = ans;
}
int main(void){
	init_memo();
	int TC; scanf("%d", &TC);
	while(TC--)
		printf("%d\n", dp(read()));
}

