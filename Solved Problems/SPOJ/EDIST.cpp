#include <stdio.h>
#include <algorithm>

#define Max 2005

using namespace std;
int A, B;	// length of my strings
char a[Max];
char b[Max];
int memo[Max][Max];
int dp(int i, int j){
	if (memo[i][j] != -1) return memo[i][j];
	if (i == A) return memo[i][j] = B - j;
	if (j == B) return memo[i][j] = A - i;
	if (a[i] == b[j]) return memo[i][j] = min(dp(i+1, j+1), min(1 + dp(i+1, j), 1 + dp(i, j+1)));
	return memo[i][j] = 1 + min(dp(i+1, j), min(dp(i, j+1), dp(i+1, j+1)));
	// if (!a[i] && !b[i]) return memo[i][j] = 0;
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	scanf("%d\n", &TC);
	while (TC--){
		scanf("%s", a);
		scanf("%s", b);
		A = B = 0;
		while (a[A]) A++;
		while (b[B]) B++;
		for (int i = 0; i <= A; i++)
		for (int j = 0; j <= B; j++)
			memo[i][j] = -1;
		printf("%d\n", dp(0, 0));
	}
	return 0;
}