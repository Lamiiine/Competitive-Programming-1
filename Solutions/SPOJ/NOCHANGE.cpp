#include <stdio.h>
#include <string.h>
#define MAX 100005

using namespace std;
int k[6]; int n;	// coins and number of coins
int memo[MAX];		// 1, 0, -1
bool dp(int x){
	if (x < 0) return false;
	if (x == 0) return true;
	if (memo[x] != char(0xFF)) return memo[x];
	int y;
	int m = n;
	while (m){
		y = x;
		for (int i = 0; i < m; i++) y -= k[i];
		if (dp(y)) return memo[x] = true;
		m--;
	}
	return memo[x] = false;
}

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	memset(memo, 0xFF, sizeof memo);	// initialize all to -1
	int x;
	scanf("%d%d", &x, &n);
	for (int i = 0; i < n; i++) scanf("%d", &k[i]);
	if (dp(x)) printf("YES");
	else printf("NO");
	return 0;
}