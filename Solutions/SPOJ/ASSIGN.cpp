// This is a top-down DP solution
// Try to find a bottom-up solution
// Have you identified the state correctly?
#include <stdio.h>
#include <string.h>
#include <map>
#define MAX 20
using namespace std;
map<int, int> Map;
int n;	// number of students
int maxB;
int like[MAX][MAX];
char testCase;
pair<long long, char> memo[MAX][1048576];	// 2^20
long long dp(int i, int b){	// index, and business
	if (i == n) return 1;
	if (memo[i][b].second == testCase) return memo[i][b].first;
	long long sum = 0;
	int x, y = b;
	while (y < maxB){
		x = (y + 1)&~y;
		y |= x;
		if (like[Map[x]][i])
			sum += dp(i+1, b | x);
	}
	memo[i][b].second = testCase;
	return memo[i][b].first = sum;
}
int main(){
	testCase = 0;
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	for (int i = 0; i <= 20; i++) Map[1 << i] = i;
	memset(memo, 0xFF, sizeof memo);
	int TC;
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &n);
		maxB = (1 << n) - 1;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &like[i][j]);
		printf("%lld\n", dp(0, 0));
		testCase++;
	}
	return 0;
}