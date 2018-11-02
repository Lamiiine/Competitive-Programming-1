#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 105
#define MOD 1000000007
int k, d;
int memo[MAX][2];
int dp(int n, bool done){
	if (memo[n][done] != -1) return memo[n][done];
	if (!done && n < d) return memo[n][done] = 0;
	if (!n) return memo[n][done] = 1;
	int ans = 0;
	for (int i = 1; i <= min(k, n); ++i) ans = (ans + dp(n - i, i >= d || done))%MOD;
	return memo[n][done] = ans;
}
int main(){
	memset(memo, 0xFF, sizeof memo);
	int n;
	scanf("%d%d%d", &n, &k, &d);
	printf("%d", dp(n, 0));
	return 0;
}
