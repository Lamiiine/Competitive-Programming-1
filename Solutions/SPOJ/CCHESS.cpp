#include <stdio.h>
#include <string.h>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>

#define MAX 10005
#define MAX2 100005
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int a, b, c, d;	// source, target
int dist[8][8];
vector<iii> adj[8][8];
int dij(){
	priority_queue<iii> q;
	dist[a][b] = 0;
	q.push(iii(0, ii(a, b)));
	while (!q.empty()){
		int dist_cur = -q.top().first;
		int x = q.top().second.first, y = q.top().second.second;
		q.pop();
		int u, v, temp_dist;
		if (dist[x][y] < dist_cur) continue;
		for (vector<iii>::iterator iter = adj[x][y].begin(); iter != adj[x][y].end(); ++iter)
		if (dist[u = (iter->second).first][v = (iter->second).second] > (temp_dist = dist_cur + iter->first))
		{
			dist[u][v] = temp_dist;
			q.push(iii(-temp_dist, ii(u, v)));
		}
	}
	return dist[c][d];
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int dx[] = { 2, 2, -2, -2, 1, -1, 1, -1 };
	int dy[] = { 1, -1, 1, -1, 2, 2, -2, -2 };
	int u, v;
	for (int i = 0; i < 8; ++i)
	for (int j = 0; j < 8; ++j)
	for (int k = 0; k < 8; ++k){
		u = i + dx[k];
		v = j + dy[k];
		if (u < 0 || u > 7 || v < 0 || v > 7) continue;
		adj[i][j].push_back(iii(i*u + j*v, ii(u, v)));
	}
	while (scanf("%d%d%d%d", &a, &b, &c, &d) != EOF){
		memset(dist, 0x3F, sizeof dist);
		printf("%d\n", dij());
	}
	return 0;
}