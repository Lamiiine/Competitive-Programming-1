#include<stdio.h>
#include<string.h>
#define MAX 82
using namespace std;
int memo[MAX];
int n;
int dp(int i){
	int & ans = memo[i];
	if (ans != -1) return ans;
	return ans =  dp(i + 2) + dp(i + 3);
}
void init(void){
	memset(memo, 0xFF, sizeof memo);
	memo[n + 1] = 0;
	memo[n] = 1;
	memo[n-1] = 1;
	if (n >= 2) memo[n-2] = 1;
	if (n >= 3) memo[n-3] = 2;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d", &n) != EOF)
		init(), printf("%d\n", dp(1) + dp(2));
	return 0;
}

