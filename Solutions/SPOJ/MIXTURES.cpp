// My first bottom-up DP solution!!!!!!!!!!!!!!!!!!!!!!!!
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
#define MAX 0xFFFFFFF

using namespace std;

int main(){
	int g = 0;
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int memo[100][100][100];
	int x[105];
	int n;
	while (scanf("%d", &n) != EOF){
		for (int i = 0; i < n; i++) scanf("%d", &x[i]);
		// initialize all at MAX
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		for (int y = 0; y < 100; y++) memo[i][j][y] = MAX;
		// base case is length-1 intervals
		for (int i = 0; i < n; i++)
		{
			for (int y = 0; y < x[i]; y++)
				memo[i][i][y] = MAX;
			memo[i][i][x[i]] = 0;
			for (int y = x[i] + 1; y < 100; y++)
				memo[i][i][y] = MAX;
		}
		int a, b;
		// fill the rest of the intervals using the previous intervals
		for (int j = 1; j < n; j++)		// length
		for (int i = 0; i < n - j; i++)	// starting point
		{
			for (int k = i; k < i + j; k++)
			for (int y = 0; y < 100; y++)
			{
				if ((a = memo[i][k][y]) != MAX) 
				for (int z = 0; z < 100; z++)
					if ((b = memo[k + 1][i + j][z]) != MAX)
						memo[i][i + j][(y + z) % 100] = min(memo[i][i + j][(y + z) % 100], a + b + y*z);
			}
		}
		int ans = MAX;
		for (int y = 0; y < 100; y++)
			ans = min(ans, memo[0][n - 1][y]);
		printf("%d\n", ans);
	}
	return 0;
}
