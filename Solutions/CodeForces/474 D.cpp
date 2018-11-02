#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
#include <iostream>
#define MAX 100005
#define MOD 1000000007
using namespace std;
int k;
int memo[MAX];
int dp(int n){
	if (memo[n] != -1) return memo[n];
	return memo[n] = (dp(n-1) + dp(n-k)) % MOD;	// don't forget to MOD
}
int main() {
	int TC;
	memset(memo, 0xFF, sizeof memo);
	scanf("%d%d", &TC, &k);
	memo[0] = 0;	// I thought it won't be reached but it was down there
	for (int i = 1; i < k; ++i) memo[i] = 1;
	memo[k] = 2;
	for (int i = 0; i < MAX; ++i) dp(i);
	// you can MOD in accumulation arrays as well
	for (int i = 1; i < MAX; ++i) memo[i] = (memo[i] + memo[i-1])%MOD;	// memo[0] was reached here!
	int a, b;
	while(TC--){
		scanf("%d%d", &a, &b);
		printf("%d\n", (memo[b] - memo[a-1] + MOD)%MOD);	// MOD here as well
	}
	return 0;
}
