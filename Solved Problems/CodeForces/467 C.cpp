#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAX 5005
using namespace std;
typedef long long LL;
int n, m;
LL memo[MAX][MAX];
LL sum[MAX];
LL dp(int i, int d){	// maximum-sum d subsequences starting at index i
	if (memo[i][d] != -1) return memo[i][d];
	if (!d) return memo[i][d] = 0;
	if (n - i < m*d) return memo[i][d] = LLONG_MIN / 4;
	return memo[i][d] = max(sum[i + m] - sum[i] + dp(i+m, d-1), dp(i+1, d));
}
int main(){
	// freopen("Input.txt", "r", stdin);
	memset(memo, 0xFF, sizeof memo);
	int k;
	scanf("%d%d%d", &n, &m, &k);
	sum[0] = 0;
	for (int i = 1; i <= n; ++i)
		scanf("%d", &sum[i]);
	// accumulation arrays must be implemented on the original sequence
	// therefore, if you read into sum[], store the summations into sum[], or at least copy it first
	for (int i = 2; i <= n; ++i)
		sum[i] += sum[i - 1];
	cout << dp(0, k);
	return 0;
}