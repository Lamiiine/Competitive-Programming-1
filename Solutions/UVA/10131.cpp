// In this file, I have 3 accepted functions for getting the path
// For some reason, I had to use dp() in all of them
// None of them worked with memo[][]

#include <stdio.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

typedef pair<int, int> ii;
int n;
pair<ii, int> e[1000];
int memo[1005][1005];
int k;
int dp(int i, int j){	// your last choice was i
	if (memo[i][j] != -1) return memo[i][j];
	while (e[j].first.second >= e[i].first.second || e[j].first.first == e[i].first.first && j < n) j++;
	if (j == n) return 0;
	return memo[i][j] = max(dp(i, j+1), 1 + dp(j, j+1));
}
void print3(int i, int j, int val){	// my last choice was i
	if (j >= n) return;
	if (dp(i, j + 1) == val)
		print3(i, j+1, val);
	else if (dp(j, j+1) == val -1){
		printf("%d\n", e[j].second);
		print3(j, j+1, val - 1);
	}
}
void print2(){
	int i = 0;
	while (k--){
		for (int j = i + 1; j < n; j++)
		if (dp(i, j) - 1 == dp(j, j + 1)) { printf("%d\n", e[i = j].second); break; }
	}
}
void print(int i, int val){	// my last choice was i
	if (val <= 0 || i >= n) return;
	for (int k = i+1; k < n; k++)
	if (dp(i, k+1) < val) {
		printf("%d\n", e[k].second);
		print(k, val-1);
		return;
	}
	print(i + 1, val);
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	memset(memo, 0xFF, sizeof memo);
	n = 1;
	e[0].first = ii(INT_MIN, INT_MAX);
	while (scanf("%d%d", &e[n].first.first, &e[n].first.second) != EOF) e[n].second = n++;
	memset(memo[n], 0x00, sizeof memo[n]);
	for (int i = 0; i <= n; i++) memo[i][n] = 0;
	sort(e, e + n);	// weights are increasing
	// Now, we need to find longest decreasing subsequence of IQ's
	printf("%d\n", k = dp(0, 1));
	print(0, k);
	// print2();
	// print3(0, 1, k);
	return 0;
}