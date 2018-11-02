#include <stdio.h>
#include <string.h>
#include <algorithm>
#define N 100
using namespace std;
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC, d, n, x, y, size, Max;
	int kill[N][N];

	scanf("%d", &TC);
	while (TC--){
		memset(kill, 0, sizeof kill);
		scanf("%d%d", &d, &n);
		while (n--){
			scanf("%d %d %d", &x, &y, &size);
			for (int i = max(x - d, 0); i <= min(x + d, N-1); i++)
			for (int j = max(y - d, 0); j <= min(y + d, N-1); j++)
				kill[i][j] += size;
		}
		x = 0; y = 0; Max = kill[0][0];
		for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		if (kill[i][j] > Max){
			x = i; y = j; Max = kill[x][y];
		}
		printf("%d %d %d\n", x, y, Max);
	}
	return 0;
}