#include<stdio.h>
#include<string.h>
#define MAX 84
using namespace std;
char s[MAX][MAX];
bool vis[MAX][MAX];
bool exp[MAX][MAX];
int Exp;
int n;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
void dfs(int i, int j){
	char t = s[i][j];
	vis[i][j] = true;
	for (int k = 0; k < 4; ++k){
		int x = i + dx[k], y = j + dy[k];
		if (x < 0 || x >= n || y < 0 || y >= n || vis[x][y]) continue;
		if (s[x][y] == t)
			dfs(x, y);
		else if (s[x][y] == 'U')
			exp[x][y] += Exp;
	}
}
void init(void){
	memset(vis, 0, sizeof vis);
	memset(exp, 0, sizeof exp);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d", &n), n){
		if (n == 1){
			// stupid special case
			scanf("%s", s[0]);
			switch (s[0][0]){
			case 'W':printf("White has a winning path.\n"); break;
			case 'B':printf("Black has a winning path.\n"); break;
			case 'U':printf("There is no winning path.\n"); break;
			}
			continue;
		}
		bool w_win = 0, b_win = 0, w_one = 0, b_one = 0;
		for (int i = 0; i < n; ++i)
			scanf("%s", s[i]);
		// Move from left on whites
		init();
		Exp = 1;
		for (int i = 0; i < n; ++i)
		if (!vis[i][0] && s[i][0] == 'W') dfs(i, 0);
		for (int i = 0; i < n && !w_win; ++i)
		if (vis[i][n - 1])w_win = true;	// white could move from left to right
		else if (exp[i][n - 1]) w_one = true;	// it explored, flag true

		if (w_win){
			printf("White has a winning path.\n");
			continue;
		}
		Exp = 100;
		// Move from right on whites
		for (int i = 0; i < n; ++i)
		if (!vis[i][n - 1] && s[i][n - 1] == 'W') dfs(i, n - 1);
		for (int i = 0; i < n && !w_one; ++i)
		if (exp[i][0] >= 100)w_one = true;
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		if (s[i][j] == 'U' && exp[i][j] >= 100 && (exp[i][j] % 100) != 0)w_one = true;

		// Move from up to down
		init();
		Exp = 1;
		for (int i = 0; i < n; ++i)
		if (!vis[0][i] && s[0][i] == 'B') dfs(0, i);
		for (int i = 0; i < n && !b_win; ++i)
		if (vis[n - 1][i]) b_win = true;
		else if (exp[n - 1][i]) b_one = true;
		if (b_win){
			printf("Black has a winning path.\n");
			continue;
		}
		if (w_one){
			printf("White can win in one move.\n");
			continue;
		}
		// Move from down to up
		Exp = 100;
		for (int i = 0; i < n; ++i)
		if (!vis[n - 1][i] && s[n - 1][i] == 'B') dfs(n - 1, i);
		for (int i = 0; i < n && !b_one; ++i)
			if (exp[0][i] >= 100) b_one = true;
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		if (s[i][j] == 'U' && exp[i][j] >= 100 && (exp[i][j] % 100 != 0))b_one = true;
		if (b_one){
			printf("Black can win in one move.\n");
			continue;
		}
		printf("There is no winning path.\n");
	}
	return 0;
}