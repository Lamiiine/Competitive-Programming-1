#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, int> ii;
int n;		// number of items and people
ii o[1005];	// price and weight

int memo[1005][35];

int dp(int i, int w){	// starting at element i, having wight w
	if (memo[i][w] != -1) return memo[i][w];
	if (i >= n) return memo[i][w] = 0;
	if (o[i].second > w) return memo[i][w] = dp(i+1, w);
	return memo[i][w] = max(o[i].first + dp(i+1, w - o[i].second), dp(i+1, w));
}

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	long long sum;
	int g, w;
	scanf("%d", &TC);
	while (TC--){
		memset(memo, -1, sizeof memo);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d%d", &o[i].first, &o[i].second);
		scanf("%d", &g);
		sum = 0;
		while (g--){
			scanf("%d", &w);
			sum += dp(0, w);
		}
		printf("%d\n", sum);
	}
	return 0;
}