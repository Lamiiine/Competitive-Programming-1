#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 1005
using namespace std;
char a[1005];
char b[1005];
char *A, *B;	// pointers to end of my strings
int Al, Bl;		// lengths of my strings
int memo[MAX][MAX];
int dp(int i, int j){	// starting at index i in a, j in b
	if (memo[i][j] != -1) return memo[i][j];
	if (j >= Bl && i < Al) return memo[i][j] = 1;
	if (i >= Al) return memo[i][j] = 10000;
	char *x = find(b + j, B, a[i]);
	if (x == B) return memo[i][j] = 1;
	return memo[i][j] = min(dp(i+1, j), 1 + dp(i + 1, x - b + 1));
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	scanf("%s", a);
	scanf("%s", b);
	Al = Bl = 0;
	while (a[Al]) Al++;
	A = a + Al;
	while (b[Bl]) Bl++;
	B = b + Bl;
	memset(memo, -1, sizeof memo);
	printf("%d", dp(0, 0));
	return 0;
}
