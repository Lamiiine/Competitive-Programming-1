#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>

using namespace std;
int counter;
char a[1010];	// a stores digits
int memo[1010][5010];
int dp(int i, int s){
	if (s < 0) return 0xFFFF;
	if (memo[i][s] != -1) return memo[i][s];
	if (i > counter) return memo[i][s] = (!s)?0:0xFFFF;
	if (!a[i]) return memo[i][s] = dp(i+1, s);
	if (counter - i <= 3){
		int x = 0, ten = 1;
		for (int j = counter-i; j >= 0; j--){
			x += a[i+j]*ten;
			ten *= 10;
		}
		if (s == x) return memo[i][s] = 0;
	}
	int ans = 0xFFFF;
	for (int j = 0; j <= min(3, counter - i); j++){
		int x = 0, ten = 1;
		for (int k = j; k >= 0; k--){
			x += a[i + k] * ten;
			ten *= 10;
		}
		ans = min(ans, dp(i+j+1, s-x));
	}
	return memo[i][s] = 1 + ans;
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	char c;
	counter = 0;
	scanf("%c", &c);
	while (c != '=') { a[counter++] = c - 48; scanf("%c", &c); }
	counter--;	// count is the last index
	int s;
	scanf("%d", &s);
	memset(memo, 0xFF, sizeof memo);
	printf("%d", dp(0, s));
	return 0;
}