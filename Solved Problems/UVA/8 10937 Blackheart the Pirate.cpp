#include<bits/stdc++.h>
#define MAX 52
#define N 10
#define OO 1000000
using namespace std;
typedef pair<int, int> ii;
int dist[10 + 1][MAX][MAX];
char s[MAX][MAX];
int h, w;
const int di[4] = {1, -1, 0, 0},
		dj[4] = {0, 0, 1, -1};
const int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1},
		dy[8] = {0, -1, 1, 1, -1, 0 -1, 1};
inline bool read(void)
{
	scanf("%d%d", &h, &w);
	if (h == 0 && w == 0)
		return false;
	for (int i = 0 ; i < h; ++i)
		scanf("%s", s[i]);
	return true;
}
inline void find_invalid(void)
{
	vector<ii> invalid;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (s[i][j] == '*')
				invalid.push_back(ii(i, j));
	for (int i = 0; i < invalid.size(); ++i)
	{
		const ii & cur = invalid[i];
		for (int j = 0; j < 8; ++j)
		{
			const int x = cur.first + dx[j];
			const int y = cur.second + dy[j];
			if (x >= 0 && x < h && y >= 0 && y < w)
				s[x][y] = '*';
		}
	}
}
inline bool valid_step(const char c)
{
	return c == '!' || c == '.' || c == '@';
}
vector<ii> treasures;
inline void find_treasures(void)
{
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (s[i][j] == '!')
				treasures.push_back(ii(i, j));
}
int memo[N][1 << N];


ii start;
inline int dp(const int i, const int mask)
{
	// memory
	int & ret = memo[i][mask];
	if (ret != -1) return ret;
	// base case
	if (mask == (1 << treasures.size()) - 1)
		return ret = dist[treasures.size()][treasures[i].first][treasures[i].second];
	// recursion
	ret = OO;
	for (int j = 0; j < treasures.size(); ++j)
		if (!(mask & (1 << j)))
			ret = min(ret, dist[j][treasures[i].first][treasures[i].second] + dp(j, mask | (1 << j)));
	return ret;
}
inline void init(void)
{
	for (int i = 0; i < N + 1; ++i)
		for (int j = 0; j < MAX; ++j)
			for (int k = 0; k < MAX; ++k)
					dist[i][j][k] = OO;
	memset(memo, -1, sizeof memo);
	treasures.clear();
}
inline void find_start(void)
{
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (s[i][j] == '@')
			{
				start = ii(i, j);
				return;
			}
}
int vis[MAX][MAX];
inline void bfs(const int i, const ii & s)
{
	memset(vis, 0, sizeof vis);
	dist[i][s.first][s.second] = 0;
	vis[s.first][s.second] = 1;
	queue<ii> q;
	q.push(s);
	while(!q.empty())
	{
		const ii v = q.front(); q.pop();
		const int cur_dist = dist[i][v.first][v.second];
		for (int j = 0; j < 4; ++j)
		{
			const int x = v.first + di[j], y = v.second + dj[j];
			if (x >= 0 && x < h && y >= 0 && y < w && valid_step(::s[x][y])
			&& !vis[x][y])
			{
				vis[x][y] = 1;
				dist[i][x][y] = cur_dist + 1;
				q.push(ii(x, y));
			}
		}
	}
}
inline void set_dist(void)
{
	for (int i = 0; i < treasures.size(); ++i)
		bfs(i, treasures[i]);
	bfs(treasures.size(), start);
}
int main(void)
{
	while(read())
	{
		init();
		find_start();
		find_treasures();
		find_invalid();
		set_dist();
		int ans = OO;
		for (int i = 0; i < treasures.size(); ++i)
			ans = min(ans, dist[treasures.size()][treasures[i].first][treasures[i].second] + dp(i, 1 << i));

		for (int i = 0; i < treasures.size(); ++i)
			if (!valid_step(s[treasures[i].first][treasures[i].second]))
				ans = OO;
		if (!valid_step(s[start.first][start.second]))
			ans = OO;
		if (!treasures.size())
			ans = 0;
		printf("%d\n", ans >= OO ? -1 : ans);
	}
	return 0;
}

