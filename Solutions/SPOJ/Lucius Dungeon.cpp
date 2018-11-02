#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#define MAX 105
using namespace std;
typedef pair<int, int> ii;
typedef pair<long, ii> lii;
int tc;
int m, n;
int a, b;
int x[MAX][MAX];
long dist[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
// char vis[MAX];
long dij(){
	dist[0][0] = x[0][0];
	priority_queue<lii> q;
	q.push(lii(-x[0][0], ii(0, 0)));
	while (!q.empty()){
		long dist_cur = -q.top().first;
		int s = q.top().second.first, t = q.top().second.second;
		q.pop();
		if (dist[s][t] < dist_cur) continue;
		for (int i = 0; i < 4; ++i){
			int temp_x = s + dx[i], temp_y = t + dy[i];
			if (temp_x >= n || temp_y >= m || temp_x < 0 || temp_y < 0) continue;
			if (dist[temp_x][temp_y] > dist_cur + x[temp_x][temp_y])
				q.push(lii(-(dist[temp_x][temp_y] = dist_cur + x[temp_x][temp_y]), ii(temp_x, temp_y)));
		}
	}
	return dist[a][b];
}
int main(){
	int TC;
	scanf("%d", &TC);
	long Time;
	for (tc = 0; tc < TC; ++tc){
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", &x[i][j]);
		scanf("%d%d%d", &a, &b, &Time);
		a--; b--;
		memset(dist, 0x7F, sizeof dist);
		long distance = dij();
		if (distance > Time) printf("NO\n");
		else printf("YES\n%ld\n", Time - distance);
	}
	return 0;
}