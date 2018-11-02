#include <stdio.h>

using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	// brute-force solution
	int TC, n, m, K;
	int area[101][101];
	long cost[101][101];
	long s, p;
	long current, A;	// current cost and current area
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; tc++){
		scanf("%d%d%d", &n, &m, &K);
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &area[i][j]);
		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			long &x = cost[i][j] = area[i][j];
			if (i) x += cost[i-1][j];
			if (j) x += cost[i][j - 1];
			if (i && j) x -= cost[i - 1][j - 1];
		}
		p = s = 0;	// cost and area
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)	// all possible starting points
		for (int k = i; k < n; k++) for (int l = j; l < m; l++){
			current = cost[k][l];
			if (i) current -= cost[i-1][l];
			if (j) current -= cost[k][j-1];
			if (i && j) current += cost[i-1][j-1];
			A = (k - i + 1)*(l - j + 1);
			if ((A == s && current < p)||(current <= K && A > s)) s = A, p = current;
		}
		printf("Case #%d: %d %d\n", tc, s, p);
	}
	return 0;
}