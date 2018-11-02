#include<stdio.h>
#include<string.h>
#include<string>
#define MAX 52
using namespace std;
typedef pair<int, int> ii;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
char s[MAX][MAX];
int r, c;
int t, d;
bool vis[MAX][MAX][1202][4];
void init(void){
	memset(vis, 0, sizeof vis);
}
void dfs(int i, int j, int time, int dir){
	vis[i][j][time][dir] = true;
	++time; dir ^= 1;
	if (time > d) return;
	for (int k = 0; k < 4; ++k){
		int x = i + dx[k], y = j + dy[k];
		if (k == dir || x < 0 || x >= r || y < 0 || y >= c || s[x][y] == '#' || s[x][y] == 'U' || vis[x][y][time][k]) continue;
		dfs(x, y, time, k);
	}
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		init();
		printf("Scenario #%d:\n", tc);
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; ++i)
			scanf("%s", s[i]);
		scanf("%d%d", &t, &d);
		d = t + d - 1;	// final time
		ii source, destination;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
			if (s[i][j] == 'U')
				source = ii(i, j);
			else if (s[i][j] == 'X')
				destination = ii(i, j);
		dfs(source.first, source.second, 0, 10);
		bool flag = true;
		for (int i = t; i <= d && flag; ++i)
			for (int j = 0; j < 4 && flag; ++j)
				if (vis[destination.first][destination.second][i][j])
					flag = false, printf("%d\n", i);
		if (flag) printf("Impossible\n");
		printf("\n");
	}
}

