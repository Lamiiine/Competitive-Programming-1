#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char a[10], b[10];
int memo[12][7];
const int dp(const int i, const int j){	// last character you used was i, and trying to find length j
	if (memo[i][j] != -1) return memo[i][j];
	int ans = 0;
	for (int k = 0; k < 10; ++k) {if(abs(k-i) <= 1) continue; ans += dp(k, j-1);}
	return memo[i][j] = ans;
}
char c[11];
void init(){
	memset(memo, 0xFF, sizeof memo);
	for (int i = 0; i < 12; ++i) memo[i][0] = 1;
}
// YOU ASSUMED YOU CAN USE EACH CHARACTER ONLY ONCE, BUT THIS IS NOT THE CASE!
int A, B;
const int num(int i, int j){	// 'i' is the last index you used
	if (j == A) {// c[A] = 0; printf("%s\n", c);
		return (strncmp(c, a, A) > 0 && strncmp(c, b, B) < 0);
	}
	int ans = 0;
	for (int k = 0; k < 10; ++k){if (abs(k-i) <= 1) continue; c[j] = k + 'A'; ans += num(k, j + 1);}
	return ans;
}
const int num1(int i, int j){	// number of strings of length equal to that of A that are lexicographicaaly greater than A
	// You can use characters starting with index i and you still need to fill j characters
	if (j == A) {// c[A] = 0; printf("%s\n", c);
		return strncmp(c, a, A) > 0;
	}
	int ans = 0;
	for (int k = 0; k < 10; ++k) {if (abs(k-i) <= 1) continue; c[j] = k + 'A'; ans += num1(k, j+1);}
	return ans;
}
const int num2(int i, int j){
	if (j == B) {// c[B] = 0; printf("%s\n", c);
		return strncmp(c, b, B) < 0;
	}
	int ans = 0;
	for (int k = 0; k < 10; ++k) {if (abs(k-i) <= 1) continue; c[j] = k + 'A'; ans += num2(k, j+1);}
	return ans;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	init();
	while(scanf("%s%s", a, b) != EOF){
		int ans;
		A = strlen(a), B = strlen(b);
		if (A == B) ans = num(100, 0);
		else {
			ans = num1(100, 0) + num2(100, 0);
			for (int i = A+1; i < B; ++i) ans += dp(11, i);
		}
		printf("%d\n", ans);
	}
	return 0;
}

