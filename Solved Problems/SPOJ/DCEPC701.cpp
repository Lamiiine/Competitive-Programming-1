#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define MAX 205
using namespace std;
struct pos{int x, y;};
int tim[MAX][MAX];
pos s, t;
int n, m;
int dist[MAX][MAX];
struct state{
	int x, y, t;
};
const bool operator <(const state & a, const state & b){ return b.t < a.t;}
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void dij(){
	dist[s.x][s.y] = tim[s.x][s.y];
	priority_queue<state>q;
	q.push(state{s.x, s.y, 0});
	while(!q.empty()){
		state cur = q.top();
		q.pop();
		if (cur.x == t.x && cur.y == t.y) return;
		for (int i = 0; i < 4; ++i){
			int xx = cur.x + dx[i], yy = cur.y + dy[i];
			if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
			int tt = max(cur.t + 1, tim[xx][yy]);
			if (dist[xx][yy] > tt) q.push(state{xx, yy, dist[xx][yy] = tt});
		}
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	char temp[MAX];
	while(TC--){
		memset(dist, 0x3F, sizeof dist);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) scanf("%s", temp);
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) scanf("%d", &tim[i][j]);
		scanf("%d%d%d%d", &s.x, &s.y, &t.x, &t.y);
		dij();
		printf("%d\n", dist[t.x][t.y]);
	}
	return 0;
}

