#include<bits/stdc++.h>
#define MAX (1 << 9)
#define INF 1000000000
using namespace std;
bool can[MAX][MAX][4];
int dist[MAX][MAX][4];
int r, c;
typedef pair<int, int> ii;
typedef pair<ii, ii> iiii;
// north, east, west, south
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
inline void dij(void)
{
	dist[0][0][0] = 0;
	priority_queue<iiii> q;
	q.push(iiii(ii(0, 0), ii(0, 0)));
	while(!q.empty())
	{
		const iiii t = q.top(); q.pop();
		const int cur_x = t.second.first;
		const int cur_y = t.second.second;
		const int cur_dist = -t.first.first;
		const int cur_state = t.first.second;
		if (dist[cur_x][cur_y][cur_state] < cur_dist)
		{
			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			const int x = cur_x + dx[i];
			const int y = cur_y + dy[i];
			const int state = (cur_state + 1) & 3;
			if (can[cur_x][cur_y][(i - cur_state + 4) & 3]
					&& x >= 0 && x < r && y >= 0 && y < c
					&& dist[x][y][state] > cur_dist + 1)
			{
				q.push(iiii(
						ii(-(dist[x][y][state] = cur_dist + 1), state),
						ii(x, y)
						));
			}
		}
	}
}
inline void read(void)
{
	char t[10];
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (i != r - 1 || j != c - 1)
			{
				scanf("%s", t);
				for (char * c = t; *c; ++c)
				{
					switch(*c)
					{
						case 'N': can[i][j][0] = true; break;
						case 'E': can[i][j][1] = true; break;
						case 'S': can[i][j][2] = true; break;
						case 'W': can[i][j][3] = true; break;
					}
				}
			}
		}
	}
}
inline void init(void)
{
	memset(dist, 0x3F, sizeof dist);
	memset(can, 0, sizeof can);
}
int main(void)
{
	while(~scanf("%d%d", &r, &c))
	{
		init();
		read();
		dij();
		int ans = INF;
		for (int i = 0; i < 4; ++i)
		{
			ans = min(ans, dist[r - 1][c - 1][i]);
		}

		if (ans == INF)
		{
			printf("no path to exit");
		}
		else
		{
			printf("%d", ans);
		}

		printf("\n");
	}
	return 0;
}

