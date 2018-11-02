#include<string.h>
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<string>
#include<limits.h>
#include<limits>
#define MAX 102
using namespace std;
typedef pair<int, int> ii;
int n;
int a[MAX][MAX];
bool vis[MAX][MAX];
bool read[MAX][MAX];
ii start[MAX];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
void dfs(int i, int j){
	int val = a[i][j];
	int s, r;
	for (int k = 0; k < 4; ++k){
		s = i + dx[k];
		r = j + dy[k];
		if (s < 0 || r < 0 || s >= n || r >= n) continue;
		if (a[s][r] != val || vis[s][r]) continue;
		vis[s][r] = true;
		dfs(s, r);
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d", &n), n){
		// printf("%d\n", n);
		memset(vis, 0, sizeof vis);
		memset(read, 0, sizeof read);
		for (int i = 0; i < n - 1; ++i){
			int x, y;
			for (int j = 0; j < n; ++j){
				scanf("%d%d", &x, &y);
				--x; --y;
				read[x][y] = true;
				a[x][y] = i;
			}
			start[i] = ii(x, y);
			cin.ignore(100000, '\n');
		}
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		if (!read[i][j]) start[a[i][j] = n - 1] = ii(i, j);

		for (int i = 0; i < n; ++i)
		{
			ii temp = start[i];
			vis[temp.first][temp.second] = true;
			dfs(temp.first, temp.second);
		}
		bool flag = true;
		for (int i = 0; i < n && flag; ++i)
		for (int j = 0; j < n; ++j) if (!vis[i][j]){
			printf("wrong\n");
			flag = false;
			break;
		}
		if (flag)printf("good\n");
	}
	return 0;
}