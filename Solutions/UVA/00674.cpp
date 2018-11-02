#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int coin[4] = { 50, 25, 10, 5};	// the fifth coin is 1
int memo[4][7490];
int change(int i, int v){	// starting at coin i, with value v
	if (i == 4 || v == 0) return 1;
	if (memo[i][v] != -1) return memo[i][v];
	if (coin[i] > v) return memo[i][v] = change(i+1, v);
	return memo[i][v] = change(i, v-coin[i]) + change(i + 1, v);
	// the number of ways of representing v - coin[i] using coin i, added to the number of ways of representing v ignoring coin[i]
}

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int v;
	memset(memo, 0xFF, sizeof memo);
	while (scanf("%d", &v) != EOF)
		printf("%d\n", change(0, v));
	return 0;
}