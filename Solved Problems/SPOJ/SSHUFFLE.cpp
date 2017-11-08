#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
char a[65], b[65], c[65];
int A, B, C;
long long memo[65][65][65];
long long dp(int i, int j, int k){	// starting at k in c, the last you used was i
	// printf("%d %d %d\n", i, j, k);
	if (memo[i][j][k] != -1) return memo[i][j][k];
	if (k == C) return memo[i][j][k] = 1;
	if (C - k > A - i + B - j) return memo[i][j][k] = 0;
	if (i == A && j == B) return memo[i][j][k] = 0;
	int countx = 0, county = 0;
	int indexx = i, indexy = j;
	int x[65];
	int y[65];
	while (indexx < A && a[indexx] != c[k]) indexx++;
	while (indexx < A){
		x[countx++] = ++indexx;
		while (indexx < A && a[indexx] != c[k]) indexx++;
	}
	while (indexy < B && b[indexy] != c[k]) indexy++;
	while (indexy < B){
		y[county++] = ++indexy;
		while (indexy < B && b[indexy] != c[k]) indexy++;
	}
	long long ans = 0;
	for (int z = 0; z < countx; z++) ans += dp(x[z], j, k+1);
	for (int z = 0; z < county; z++) ans += dp(i, y[z], k + 1);
	return memo[i][j][k] = ans;
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	int TC;
	scanf("%d\n", &TC);
	while (TC--){
		memset(memo, 0xFF, sizeof memo);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(c, 0, sizeof c);
		scanf("%s", a);
		scanf("%s", b);
		scanf("%s", c);
		A = B = C = 0;
		while (a[A]) A++;
		while (b[B]) B++;
		while (c[C]) C++;
		printf("%lld\n", dp(0, 0, 0));
	}
	return 0;
}