#include<bits/stdc++.h>
#define MAX 4040
#define MOD 1000000007
using namespace std;
int memo[MAX];
int a, b, c;
inline int dp(const int i){
	if (i < 0) return -1000000000;
	int & ret = memo[i];
	if (ret != -1) return ret;
	return ret = 1 + max(max(dp(i - a), dp(i - b)), dp(i - c));
}
int main(void){
	memset(memo, 0xFF, sizeof memo);
	memo[0] = 0;
	int n;
	scanf("%d%d%d%d", &n, &a, &b, &c);
	printf("%d\n", dp(n));
}

