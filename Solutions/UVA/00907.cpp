#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<limits.h>
#define N 605
#define M 305
using namespace std;
int memo[N][M];
int dist[N];
int n, m;
inline int dp(int i, int j){	// starting at point i, what is the minimum maximum daily walking distance if you still have j days left
	if (memo[i][j] != -1) return memo[i][j];
	int ans = INT_MAX;
	int temp = 0;
	for (int k = i; k < n && temp < ans; ++k){
		temp += dist[k];
		// YOU WROTE 'i + 1' INSTEAD OF 'k + 1'
		ans = min(ans, max(temp, dp(k + 1, j - 1)));
	}
	return memo[i][j] = ans;
}
void init(void){
	memset(memo, 0xFF, sizeof memo);
	for (int i = 0; i < M; ++i)
		memo[n][i] = 0;
	int temp = 0;
	for (int i = n-1; i >= 0; --i){
		temp += dist[i];
		memo[i][1] = temp;
	}
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d%d", &n, &m) != EOF){
		++n; ++m;
		for (int i = 0; i < n; ++i)
			scanf("%d", dist + i);
		init();
		printf("%d\n", dp(0, m));
	}
	return 0;
}

