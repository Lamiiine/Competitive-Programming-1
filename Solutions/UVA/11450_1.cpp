#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int m, c;	// money, number of garment classes;
int mod[20][21];	// models[garment i]	mod[i][0] is the number of models
int dp[201][21];
int Dp(int M, int C){	// I don't know how I wrote this!!!!!!
	if (dp[M][C] != -1) return dp[M][C];
	if (C == c) return dp[M][C] = m - M;
	int ans = -1;
	for (int i = 1; i <= mod[C][0]; i++)
	if (M >= mod[C][i]) ans = max(Dp(M - mod[C][i], C + 1), ans);
	if (ans == -1) return dp[M][C] = -2;	// -2 for no solution
	else return dp[M][C] = ans;
}
// This print function is very nice
void print(){
	int money = m;
	for (int i = 0; i < c; i++){
		for (int j = 1; j <= mod[i][0]; j++)
		if (mod[i][j] <= money && dp[money - mod[i][j]][ i + 1] == dp[money][i]){
			printf("%d%c", mod[i][j], "-\n"[i == c-1]);
			money -= mod[i][j];
			break;
		}
	}
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	while (TC--){
		scanf("%d%d", &m, &c);
		memset(dp, 0xFF, sizeof dp);
		for (int i = 0; i < c; i++)
		{
			scanf("%d", &mod[i][0]);
			for (int j = 1; j <= mod[i][0]; j++)
				scanf("%d", &mod[i][j]);
		}
		int money = Dp(m, 0);
		if (money != -2) { printf("%d\n", money); /*print();*/ }
		else printf("no solution\n");
	}
	return 0;
}