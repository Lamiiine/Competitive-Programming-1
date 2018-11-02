#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 105
#define MOD 100000000
using namespace std;
int k1, k2;
int memo[MAX][MAX][2];
int dp(int x, int y, bool done){	// (done == ture) = choose from y first
	if (memo[x][y][done] != -1) return memo[x][y][done];
	if (!y){
		if (done) return memo[x][y][done] = 0;
		return memo[x][y][done] = (x <= k1)?1:0;
	}
	if (!x){
		if (!done) return memo[x][y][done] = 0;
		return memo[x][y][done] = (y <= k2)?1:0;
	}
	int ans = 0;
	if (done){
		for (int i = 1; i <= min(k2, y); ++i)
			ans = (ans + dp(x, y - i, !done)) % MOD;	// don't forget to MOD
	}
	else{
		for (int i = 1; i <= min(k1, x); ++i)
			ans = (ans + dp(x - i, y, !done)) % MOD;
	}
	return memo[x][y][done] = ans;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	memset(memo, 0xFF, sizeof memo);
	int n, m;
	scanf("%d%d%d%d", &n, &m, &k1, &k2);
	for (int i = 0; i < 2; ++i) memo[0][0][i] = 0;
	
	for (int i = 1; i <= k1; ++i) memo[i][0][0] = 1;
	for (int i = 1; i <= k2; ++i) memo[0][i][1] = 1;
	for (int i = k1 + 1; i <= n; ++i) memo[i][0][0] = memo[i][0][1] = 0;

	for (int i = k2 + 1; i <= m; ++i) memo[0][i][0] = memo[0][i][1] = 0;

	for (int i = 0; i <= n; ++i) memo[i][0][1] = 0;
	for (int i = 0; i <= m; ++i) memo[0][i][0] = 0;

	printf("%d", (dp(n, m, 0) + dp(n, m, 1)) % MOD);	// don't forget to MOD!
	return 0;
}