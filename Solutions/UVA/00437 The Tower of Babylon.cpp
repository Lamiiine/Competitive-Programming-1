#include<bits/stdc++.h>
#define MAX 32
#define INF 1000000000
using namespace std;
struct stone{
	int x;
	int y;
	int z;
	stone(int a, int b, int c):x(a), y(b), z(c){}
	stone(){x = y = z = 0;}
};
int n;
int counter[MAX];
stone arr[MAX][6];
int memo[MAX][6];
// maximum tower to be built if your last stone with stone i with orientation j
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j];
	if (ret != -1)
		return ret;
	ret = 0;
	// try all possible stones!
	const stone & cur = arr[i][j];
	const int l = min(cur.x, cur.y);
	const int w = max(cur.x, cur.y);
	// dimensions of my base!
	for (int k = 0; k < n; ++k)
		for (int t = 0; t < counter[k]; ++t)
		{
			const stone & v = arr[k][t];
			if (min(v.x, v.y) < l && max(v.x, v.y) < w)
				ret = max(ret, v.z + dp(k, t));
		}
	return ret;
}
inline void read(void)
{
	int temp[3] = {0};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
			scanf("%d", temp + j);
		sort(temp, temp + 3);
		counter[i] = 0;
		do
		{
			arr[i][counter[i]++] = stone(temp[0], temp[1], temp[2]);
		} while(next_permutation(temp, temp + 3));
	}
}
inline void init(void)
{
	memset(memo, -1, sizeof memo);
}
int main(void)
{
	for(int tc = 1; scanf("%d", &n), n; ++tc)
	{
		init();
		read();
		arr[n][0] = stone(INF, INF, INF);
		counter[n] = 1;
		printf("Case %d: maximum height = %d\n", tc, dp(n, 0));
	}
}

