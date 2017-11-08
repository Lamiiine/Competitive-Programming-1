#include<bits/stdc++.h>
#define MAX 64
using namespace std;
int n;
int memo[MAX][MAX];
bool vis[MAX][MAX];
void solve(void) {
	int i = 0, j = n >> 1;
	for (int v = 1; v <= n * n; ++v)
	{
		memo[i][j] = v;
		vis[i][j] = 1;
		const int x = (i - 1 + n) % n;
		const int y = (j + 1) % n;
		if (!vis[x][y])
		{
			i = x;
			j = y;
		}
		else
		{
			i = (i + 1) % n;
		}
	}
}
int main(void)
{
	scanf("%d", &n);
	solve();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			printf("%d%c", memo[i][j], j == n - 1 ? '\n' : ' ');
	return 0;
}

