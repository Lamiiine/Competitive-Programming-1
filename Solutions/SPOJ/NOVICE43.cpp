#include <stdio.h>
#include <string.h>

using namespace std;

int memo[13][13][13];
// this function returns number of strings of length l, using numbers <= i, not exceeding n
int dp(int i, int n, int l){	// n is the maximum number I can use, i is the largest number I can use, l is the length
	if (memo[i][n][l] != -1) return memo[i][n][l];
	if (l == 1) return memo[i][n][l] = i;
	if (i == n) return memo[i][n][l] = i + dp(i, n, l-1);
	return memo[i][n][l] = (i-1)*dp(i, n, l-1) + dp(i+1, n, l-1);
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int n;
	int TC;
	memset(memo, 0xFF, sizeof memo);
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &n);
		printf("%d\n", dp(1, n, n));
	}
	return 0;
}