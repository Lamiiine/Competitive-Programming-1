#include <bits/stdc++.h>
using namespace std;

const int inf = int(2e9) + 5;

int memo[1005][1005];
int cumul[1005][1005];
int grid[1005][1005];
int n, m;
int subrange_sum(int sr, int er, int sc, int ec){
	int sub_rect = cumul[er][ec];
	if(sr > 0) sub_rect -= cumul[sr - 1][ec];
	if(sc > 0) sub_rect -= cumul[er][sc - 1];
	if(sr > 0 && sc > 0) sub_rect += cumul[sr - 1][sc - 1];
	return sub_rect;
}
int dp(int r, int c){
	int& ret = memo[r][c];
	if(ret != inf){
		return ret;
	}
	ret = 0;
	if(r > 0){
		int srs = subrange_sum(r - 1, r - 1, c, m - 1);
		if(srs >= 0)
			ret = max(ret, srs + dp(r - 1, c));
	}
	if(c > 0){
		int srs = subrange_sum(r, n - 1,c-1, c-1);
		if(srs >= 0)
			ret = max(ret, srs + dp(r, c - 1));
	}
	return ret;
}

void build_cumul(){
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < m; j ++){
			if(i > 0) cumul[i][j] += cumul[i - 1][j];
			if(j > 0) cumul[i][j] += cumul[i][j - 1];
			if(i > 0 && j > 0) cumul[i][j] -= cumul[i - 1][j - 1];
		}
	}
}
void read(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i ++){
		for (int j = 0; j < m; j ++){
			memo[i][j] = inf;
			scanf("%d", &grid[i][j]);
			cumul[i][j] = grid[i][j];
		}
	}
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		read();
		build_cumul();
		printf("%d\n", grid[n - 1][m - 1] + dp(n - 1, m - 1));
	}
}

