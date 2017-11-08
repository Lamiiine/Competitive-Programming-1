// The idea is that you simply visit all the permutations
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <queue>
#define MAX 21
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
char c[MAX][MAX];	// my map
int count;		// number of dirt object
int dirx[11], diry[11];	// coordinates of dirt (robot has index 10)
int w, h;		// width and height of map
int dist[11][MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int per[10];
void dij(int i){	// compute the distance starting at locations in index i
	int x = dirx[i];
	int y = diry[i];
	priority_queue<iii> q;
	q.push(iii(0, ii(x, y)));
	while(!q.empty()){
		int cur_dist = -q.top().first;
		x = q.top().second.first;
		y = q.top().second.second;
		q.pop();
		if (dist[i][x][y] < cur_dist) continue;
		for (int j = 0; j < 4; ++j){
			int temp_x = x + dx[j], temp_y = y + dy[j];
			// don't forget to continue
			if (temp_x < 0 || temp_x >= h || temp_y < 0 || temp_y >= w) continue;
			if (c[temp_x][temp_y] == 'x') continue;
			if (dist[i][temp_x][temp_y] > cur_dist + 1)
				q.push(iii(-(dist[i][temp_x][temp_y] = cur_dist + 1), ii(temp_x, temp_y)));
		}
	}
}
int solve(){
	int x, y;
	x = dirx[per[0]];
	y = diry[per[0]];
	int ans = dist[10][x][y];
	for (int i = 0; i < ::count - 1; ++i){
		x = dirx[per[i+1]];
		y = diry[per[i+1]];
		ans += dist[per[i]][x][y];
	}
	return ans;
}
int main(){
	while(scanf("%d%d", &w, &h), h || w){
		memset(dist, 0xF, sizeof dist);
		::count = 0;
		char d;
		scanf("%c", &d);
		for (int i = 0; i < h; ++i){
			for (int j = 0; j < w; ++j){
				scanf("%c", &c[i][j]);
				switch(d = c[i][j]){
					case '.': break;
					case 'x': break;	// It's a small x
					case '*': {dirx[::count] = i; diry[::count] = j; ::count++; break;}
					case 'o': {dirx[10] = i; diry[10] = j; break;}	// It's a small o
				}
			}
			scanf("%c", &d);
		}
		dij(10);
		for (int i = 0; i < ::count; ++i) dij(i);
		for (int i = 0; i < 10; ++i) per[i] = i;
		int ans = solve();
		while(next_permutation(per, per + ::count))
			ans = min(ans, solve());
		if (ans < 100000) printf("%d\n", ans);
		else printf("-1\n");
	}
	return 0;
}
