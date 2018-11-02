#include<stdio.h>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<string.h>
#define MAX 105
using namespace std;
int dist[MAX][MAX][4];	// reaching position i, j, with direction d
char grid[MAX][MAX];
int w, h;
struct pos{
	int x, y;
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
pos s, t;
struct state{int x, y, t, d;};	// d for direction
bool operator < (const state & a, const state & b){
	return b.t < a.t;
}
void dij(){
	priority_queue<state> q;
	for (int i = 0; i < 4; ++i)
	dist[s.x][s.y][4] = 0, q.push(state{s.x, s.y, 0, i});	// you can reach that positon with zero reflections
	while(!q.empty()){
		state cur = q.top();
		q.pop();
		if (cur.x == t.x && cur.y == t.y) return;
		for (int i = 0; i < 4; ++i){
			int xx = cur.x + dx[i];
			int yy = cur.y + dy[i];
			if (xx < 0 || xx >= h || yy < 0 || yy >= w || grid[xx][yy] == '*') continue;
			int tt = cur.t + (i != cur.d);
			if (dist[xx][yy][i] > tt){
				dist[xx][yy][i] = tt;
				q.push(state{xx, yy, tt, i});
			}
		}
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	memset(dist, 0x3F, sizeof dist);
	scanf("%d%d", &w, &h);
	for (int i = 0; i < h; ++i) scanf("%s", grid[i]);
	bool found = 0;
	bool flag = 1;
	for (int i = 0; i < h && flag; ++i)
	for (int j = 0; j < w; ++j) if (grid[i][j] == 'C') if (found) {t = pos{i, j}; flag = 0; break;} else s = pos{i, j}, found = true;
	int ans = INT_MAX;
	int val[4];
	dij();
	memcpy(val, dist[t.x][t.y], 4*sizeof(int));
	for (int i = 0; i < 4; ++i) ans = min(ans, val[i]);
	printf("%d", ans);
	return 0;
}

