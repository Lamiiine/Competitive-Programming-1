#include <stdio.h>
#include <iostream>
#define MAX 200005
using namespace std;
typedef long long LL;
int n, k;
int a[MAX];
LL memo[MAX][2];
// your last choice was i, and it has a power of p
LL dp(int i, int p){
	if (p == 2) return 1;	// you return when you have obtained a power of 2, not 3
	if (memo[i][p] != -1) return memo[i][p];
	int toFind = a[i]*k;
	LL ans = 0;				// don't forget to initialzie
	for (int j = i+1; j < n; ++j)
	if (a[j] == toFind)
		ans += dp(j, p+1);	// here, you dp on all of the coming indeces, not just the coming one
	return memo[i][p] = ans;
}
int main(){
	// freopen("Input.txt", "r", stdin);	// don't forget to remove this
	memset(memo, 0xFF, sizeof memo);		// don't forget to memset
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	LL num = 0;
	for (int i = n-1; i >= 0; --i) num += dp(i, 0);
	cout << num;
	return 0;
}