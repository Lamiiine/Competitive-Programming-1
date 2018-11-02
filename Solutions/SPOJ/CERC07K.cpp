// THERE ARE MULTIPLE DESTINATIONS. YOU ARE SUPPOSED TO FIND CLOSEST ONE.
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string>
#include<string.h>
#define MAX 102
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
char a[MAX][MAX];
int dist[MAX][MAX][16];
bool t[MAX][MAX];
int r, c;
// distance, privileges, abscissa, ordinate
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool dij(ii s){
	dist[s.first][s.second][0] = 0;
	priority_queue<iiii>q;
	q.push(iiii(ii(0, 0), ii(s.first, s.second)));
	while (!q.empty()){
		iiii temp = q.top();
		q.pop();
		int x = temp.second.first, y = temp.second.second, cur_dist = -(temp.first.first), pri = temp.first.second;
		// BETTER TO RETURN FROM 'dij' RIGHT AFTER YOU REACH YOUR DESTINATION, TO SAVE TIME
		if (t[x][y]){
			printf("Escape possible in %d steps.\n", cur_dist);
			return true;
		}
		if (dist[x][y][pri] < cur_dist) continue;
		for (int i = 0; i < 4; ++i){
			int u = x + dx[i];
			int v = y + dy[i];
			// if it's out of borders, skip
			if (u < 0 || u >= r || v < 0 || v >= c) continue;
			char cur = a[u][v];
			bool flag = true;
			// if it's a wall, skip
			if (cur == '#') continue;
			// if it's free, record distance to it
			if (cur == '.')
			{
				int temp_dist = cur_dist + 1;
				if (dist[u][v][pri] > temp_dist)
					q.push(iiii(ii(-(dist[u][v][pri] = temp_dist), pri), ii(u, v)));
				continue;
			}
			// if it's a key, collect it
			if (cur >= 1 && cur <= 4){
				int temp_dist = cur_dist + 1;
				int temp_pri = pri | (1 << cur - 1);
				if (dist[u][v][temp_pri] > temp_dist)
					q.push(iiii(ii(-(dist[u][v][temp_pri] = temp_dist), temp_pri), ii(u, v)));
				continue;
			}
			// if it's a door, see if you can open it
			for (int j = 1; j <= 4; ++j)
			if (cur == (j * 10) && !(pri & (1 << j - 1))) {
				flag = false;
				break;
			}
			if (flag){
				int temp_dist = cur_dist + 1;
				if (dist[u][v][pri] > temp_dist)
					q.push(iiii(ii(-(dist[u][v][pri] = temp_dist), pri), ii(u, v)));
			}
		}
	}
	return false;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	char line[MAX];
	while (scanf("%d%d", &r, &c), r || c){
		int INF;
		memset(&INF, 0x3F, sizeof INF);
		memset(dist, 0x3F, sizeof dist);
		memset(t, 0, sizeof t);
		for (int i = 0; i < r; ++i){
			scanf("%s", line);
			strcpy(a[i], line);
		}
		ii s;
		// for (int i = 0; i < r; ++i) printf("%s\n", a[i]);
		for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			switch (a[i][j]){
			case '*': s = ii(i, j);  break;
			case 'r': a[i][j] = 1; break;
			case 'g': a[i][j] = 2; break;
			case 'b': a[i][j] = 3; break;
			case 'y': a[i][j] = 4; break;
			case 'R': a[i][j] = 10;  break;
			case 'G': a[i][j] = 20; break;
			case 'B': a[i][j] = 30; break;
			case 'Y': a[i][j] = 40; break;
			case 'X': t[i][j] = true; break;
		}
		if (!dij(s)) printf("The poor student is trapped!\n");;
	}
	return 0;
}