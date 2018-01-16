#include<bits/stdc++.h>
#define lsone(s) ((s) & (-s))
using namespace std;
inline int count_ones(int mask)
{
	int ans = 0;
	while(mask)
	{
		mask -= lsone(mask);
		++ans;
	}
	return ans;
}
typedef long long int ll;
ll memo[4][4][1 << 16];
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
inline int get_index(const int x, const int y)
{
	return 1 << (y + (x << 2));
}
inline ll dp(const int r, const int c, const int mask)
{
	// memory
	ll & ret = memo[r][c][mask];
	if (ret != -1LL)
	{
		return ret;
	}

	// recurse
	ret = 0LL;
	int arr[4][4];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			arr[i][j] = bool(mask & get_index(i, j));
		}
	}

	for (int i = 0; i <= r; ++i)
	{
		for (int j = 0; j <= c; ++j)
		{
			if (arr[i][j])
			{
				// we have a blob here!
				for (int k = 0; k < 8; ++k)
				{
					const int x = i + dx[k];
					const int y = j + dy[k];
					const int next_x = x + dx[k];
					const int next_y = y + dy[k];
					if (x >= 0 && x <= r && y >= 0 && y <= c
							&& next_x >= 0 && next_x <= r && next_y >= 0 && next_y <= c
							&& arr[x][y] && !arr[next_x][next_y])
					{
						ret += dp(r, c, (mask | get_index(next_x, next_y)) - get_index(x, y) - get_index(i, j));
					}
				}
			}
		}
	}

	return ret;
}

inline void init_memo(void)
{
	memset(memo, -1, sizeof memo);
	// base case!
	for (int i = 1; i < (1 << 16); i <<= 1)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				memo[j][k][i] = 1LL;
			}
		}
	}
}
int r, c, mask;
inline void read(void)
{
	int n;
	scanf("%d%d%d", &r, &c, &n);
	--r; --c;
	mask = 0;
	for (int x, y; n--; )
	{
		scanf("%d%d", &x, &y);
		--x; --y;
		mask |= get_index(x, y);
	}
}
int main(void)
{
	init_memo();
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		read();
		printf("Case %d: %lld\n", tc, dp(r, c, mask));
	}
	return 0;
}

