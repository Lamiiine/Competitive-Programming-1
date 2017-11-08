#include <stdio.h>
#include <string.h>
using namespace std;

int coin[10] = { 2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2};

long long memo[10][6005];
long long dp(int i, int s){
	if (s < 0) return 0;
	if (i == 10) return 1;
	if (memo[i][s] != -1) return memo[i][s];
	return memo[i][s] = dp(i, s - coin[i]) + dp(i+1, s);
}
int main(){
	double n;
	memset(memo, 0xFF, sizeof memo);
	while (scanf("%lf", &n), n != 0.0) printf("%6.2lf%17lld\n", n, dp(0, int(n*20.0 + 1e-5)));
	return 0;
}