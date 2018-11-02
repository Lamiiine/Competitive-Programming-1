#include<bits/stdc++.h>
#define N 8
using namespace std;
int dist[N][N][N][N];
int dx[N] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[N] = {1, -1, 1, -1, 2, -2, 2, -2};
inline void add_edges(void){
	for (int i = 0, x, y; i < N; ++i)
		for (int j = 0; j < N; ++j)
			for (int k = 0; k < N; ++k)
			{
				x = i + dx[k];
				y = j + dy[k];
				if (x >= 0 && x < N && y >= 0 && y < N)
					dist[i][j][x][y] = 1;
			}
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			dist[i][j][i][j] = 0;
}
inline void init(void){
	memset(dist, 0x3F, sizeof dist);
	add_edges();
	for (int k0 = 0; k0 < N; ++k0)
		for (int k1 = 0; k1 < N; ++k1)
			for (int i0 = 0; i0 < N; ++i0)
				for (int i1 = 0; i1 < N; ++i1)
					for (int j0 = 0; j0 < N; ++j0)
						for (int j1 = 0; j1 < N; ++j1)
							dist[i0][i1][j0][j1] = min(dist[i0][i1][j0][j1], dist[i0][i1][k0][k1] + dist[k0][k1][j0][j1]);
}
char a[5], b[5];
int main(void){
	init();
	for(int x, y, i, j; ~scanf("%s%s", a, b);printf("To get from %s to %s takes %d knight moves.\n", a, b, dist[x][y][i][j]))
		x = a[0] - 'a', y = a[1] - '1', i = b[0] - 'a', j = b[1] - '1';
	return 0;
}

