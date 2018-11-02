#include <iostream>
#include <string.h>
#define MAX 10000001
#define MOD 1000000007
using namespace std;
int Dp[4][MAX];
int main(){
	for (int i = 0; i < 4; ++i)
		Dp[i][0] = !i;
	int ans;
	for (int j = 1; j < MAX; ++j)
	for (int i = 0; i < 4; ++i)
	{
		ans = 0;
		for (int k = 1; k <= 3; ++k)
			ans = (ans + Dp[(i + k) % 4][j - 1]) % MOD;
		Dp[i][j] = ans;
	}

	int n;
	cin >> n;
	cout << Dp[0][n];
	return 0;
}