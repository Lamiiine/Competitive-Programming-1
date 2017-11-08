#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#define MAX 27
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
char m[MAX][MAX];
int w, h;
int dist[MAX][MAX];
int Dx, Dy, Sx, Sy;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int dij(){
	dist[Sx][Sy] = 0;
	priority_queue<iii> q;
	q.push(iii(0, ii(Sx, Sy)));
	while(!q.empty()){
		int dist_cur = -q.top().first;
		int x = q.top().second.first;
		int y = q.top().second.second;
		q.pop();
		if (dist[x][y] < dist_cur) continue;
		if (m[x][y] == 'D') return dist[x][y];
		for (int i = 0; i < 4; ++i){
			int temp_x = x + dx[i];
			int temp_y = y + dy[i];
			if (temp_x < 0 || temp_x >= h ||temp_y < 0 || temp_y >= w) continue;
			if (m[temp_x][temp_y] == 'X') continue;
			if (dist[temp_x][temp_y] > dist_cur + m[temp_x][temp_y])	// it's temp_x and temp_y, not x and y
				q.push(iii(-(dist[temp_x][temp_y] = dist_cur + (m[temp_x][temp_y]*(m[temp_x][temp_y] <= 9))), ii(temp_x, temp_y)));
				// avoid hitting your destination
		}
	}
}
int main(){
	while(scanf("%d%d", &w, &h), w || h){
		memset(dist, 0x3F, sizeof dist);
		char d;
		scanf("%c", &d);
		for (int i = 0; i < h; ++i){
			for (int j = 0; j < w; ++j){
				scanf("%c", &m[i][j]);
				if (isdigit(d = m[i][j])) m[i][j] -= '0';
				if (d == 'S') Sx = i, Sy = j;
				if (d == 'D') Dx = i, Dy = j;
			}
			scanf("%c", &d);
		}
		printf("%d\n", dij());
	}
	return 0;
}
