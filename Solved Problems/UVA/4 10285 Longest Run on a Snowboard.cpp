#include<stdio.h>
#include<vector>
#include<string.h>
#include<string>
#include<iostream>
#define MAX 105
using namespace std;
typedef pair<int, int>ii;
int r, c;
int a[MAX][MAX];
bool vis[MAX][MAX];
int dist[MAX][MAX];
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
vector<ii>ans;
inline void dfs(int i, int j){
	int cur_h = a[i][j];
	for (int k = 0; k < 4; ++k){
		int x = i + dx[k], y = j + dy[k];
		if (x < 0 || x >= r || y < 0 || y >= c || a[x][y] >= cur_h ||vis[x][y]) continue;
			dfs(x, y);
	}
	ans.push_back(ii(i, j));
}
void init(void){
	memset(vis, 0, sizeof vis);
	ans.clear();
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			dist[i][j] = 1;
}
// dijkstra
typedef pair<int, ii> iii;
int main(void){
	// freopen("Input.txt", "r", stdin);
	string name;
	int TC;
	scanf("%d", &TC);
	while(TC--){
		init();
		cin >> name;
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				scanf("%d", &a[i][j]);
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (!vis[i][j]) dfs(i, j);
		for (int i = ans.size() - 1; i >= 0; --i)
		{
			ii cur = ans[i];
			int cur_h = a[cur.first][cur.second];
			int cur_d = dist[cur.first][cur.second] + 1;
			for (int k = 0; k < 4; ++k){
				int x = cur.first + dx[k];
				int y = cur.second + dy[k];
				if (x < 0 || x >= r || y < 0 || y >= c || a[x][y] >= cur_h) continue;
				dist[x][y] = max(dist[x][y], cur_d);
			}
		}
		int ans = 0;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				ans = max(ans, dist[i][j]);
		printf("%s: %d\n", name.c_str(), ans);
	}
	return 0;
}

