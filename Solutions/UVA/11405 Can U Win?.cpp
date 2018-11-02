#include<bits/stdc++.h>
#define N 8
using namespace std;
typedef pair<int, int> ii;

int memo[1 << N][N + 1];

const int di[8] = {2, 2, -2, -2, 1, 1, -1, -1},
		dj[8] = {1, -1, 1, -1, 2, -2, 2, -2};
int n;
char arr[16][16];
int dist[8][8][8][8];
inline void floyd_warshall(void)
{
	for (int k1 = 0; k1 < N; ++k1)
		for (int k2 = 0; k2 < N; ++k2)
			for (int i1 = 0; i1 < N; ++i1)
				for (int i2 = 0; i2 < N; ++i2)
					for (int j1 = 0; j1 < N; ++j1)
						for (int j2 = 0; j2 < N; ++j2)
							dist[i1][i2][j1][j2] = min(
									dist[i1][i2][j1][j2],
									dist[i1][i2][k1][k2] + dist[k1][k2][j1][j2]);
}
int count_pawn;
ii pawn[16];
inline void init(void)
{
	memset(dist, 0x3F, sizeof dist);
	count_pawn = 0;
	memset(memo, -1, sizeof memo);
}
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 0; i < N; ++i)
		scanf("%s", arr[i]);
}
inline void construct_graph(void)
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (arr[i][j] != 'K' && arr[i][j] != 'p')
			for (int k = 0; k < N; ++k)
			{
				const int I = i + di[k], J = j + dj[k];
				if (I >= 0 && I < N && J >= 0 && J < N && arr[I][J] != 'K' && arr[I][J] != 'p')
					dist[i][j][I][J] = 1;
			}
}
inline void find_pawns(void)
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (arr[i][j] == 'P')
				pawn[count_pawn++] = ii(i, j);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (arr[i][j] == 'k')
				pawn[count_pawn] = ii(i, j);
}
inline int dp(const int mask, const int i)
{
	// memory
	int & ret = memo[mask][i];
	if (ret != -1) return ret;
	// base
	if (mask == (1 << count_pawn) - 1)
		return ret = 0;	// no more steps
	// recursion
	ret = 1000000;
	const ii & cur = pawn[i];
	// loop over all pawns
	for (int j = 0; j < count_pawn; ++j)
		if (!(mask & (1 << j)))
		{
			const ii & next = pawn[j];
			ret = min(ret, dist[cur.first][cur.second][next.first][next.second] + dp(mask | (1 << j), j));
		}
	return ret;
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		construct_graph();
		floyd_warshall();
		find_pawns();
		printf("%s\n", dp(0, count_pawn) <= n ? "Yes" : "No");
	}
	return 0;
}

