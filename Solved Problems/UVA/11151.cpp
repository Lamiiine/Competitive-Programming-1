#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <algorithm>
#include <iostream>
#include <string>

#define Max	1005

using namespace std;

string s;
int memo[Max][Max];
int dp(int i, int j){
	if (memo[i][j] != -1) return memo[i][j];
	if (i == j) return memo[i][j] = 1;
	if (j - i == 1) return memo[i][j] = 1 + (s[i] == s[j]);
	if (s[i] == s[j]) return memo[i][j] = 2 + dp(i + 1, j - 1);
	return memo[i][j] = max(dp(i + 1, j), dp(i, j - 1));
}

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	char d;
	scanf("%d%c", &TC, &d);
	while (TC--){
		getline(cin, s);
		int end = s.length();
		for (int i = 0; i < end; i++)
		for (int j = i; j < end; j++)
			memo[i][j] = -1;
		end--;
		printf("%d\n", dp(0, end));
	}
	return 0;
}