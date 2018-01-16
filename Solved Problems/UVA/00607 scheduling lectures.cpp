#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<algorithm>
#define MAX 1005
#define INF 0x3FFFFFF
using namespace std;
int n, l, c;
int cost[MAX];
int memo[MAX][MAX];
int di(int i){	// remaining time in lecture
	if (!i) return 0;
	if (i >= 1 && i <= 10) return -c;
	return (i - 10)*(i - 10);
}
int dp(int i, int j){	// starting at topic i, with j lectures left, what is the minimum DI level
	if (memo[i][j] != -1) return memo[i][j];
	// if (i == n) return 0;	// no more topics to cover, thus no more lectures
	// if (!j) return memo[i][j] = INF;	// you still have topics, but no lectures left
	int temp = l, k = i, ans = INF;
	while (k < n && cost[k] <= temp){
		temp -= cost[k++];	// remaining time in this lecture is temp
		ans = min(ans, di(temp) + dp(k, j-1));
	}
	return memo[i][j] = ans;
}
int solve(){
	int i = 0, ans = 0;
	while (i < n){
		++ans;
		int temp = l;
		while (i < n && cost[i] <= temp)
			temp -= cost[i++];
	}
	return ans;	// minimum number of lectures
}
void init(void){
	memset(memo, 0xFF, sizeof memo);
	for (int j = 0; j < MAX; ++j)
		memo[n][j] = 0, memo[j][0] = INF;
	memo[n][0] = 0;
}
int main(void){
	bool first = true;
	int tc = 0;
	while (scanf("%d", &n), n){
		if (!first) printf("\n");
		first = false;
		scanf("%d%d", &l, &c);
		for (int i = 0; i < n; ++i)
			scanf("%d", cost + i);
		int ans;
		printf("Case %d:\nMinimum number of lectures: %d\n", ++tc, ans = solve());
		init();
		printf("Total dissatisfaction index: %d\n", dp(0, ans));
	}
	return 0;
}