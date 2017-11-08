#include<bits/stdc++.h>
#define MAX 15
using namespace std;
int n;
int memo[MAX][6][1 << MAX];
struct cube
{
	int d[3];// x, y, z
} arr[MAX][6];
inline bool operator <= (const cube & a, const cube & b)
{
	return a.d[0] <= b.d[0] && a.d[1] <= b.d[1];
}
inline int dp(const int i, const int j, const int mask)
{
	int & ret = memo[i][j][mask];
	if (ret != -1) return ret;
	ret = 0;
	// your last cube was i, j
	for (int k = 0; k < n; ++k)
		if (!(mask & (1 << k)))	// if pyramid k has not been used
			for (int t = 0; t < 6; ++t)
				if (arr[k][t] <= arr[i][j])
					ret = max(ret, arr[k][t].d[2] + dp(k, t, mask | (1 << k)));
	return ret;
}


int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d%d", arr[i][0].d, arr[i][0].d + 1, arr[i][0].d + 2);
	for (int i = 0; i < n; ++i)
		sort(arr[i][0].d, arr[i][0].d + 3);
	int temp[3];
	for (int i = 0; i < n; ++i)
	{
		memcpy(temp, arr[i][0].d, sizeof temp);
		for (int j = 1; j < 6; ++j)
		{
			next_permutation(temp, temp + 3);
			memcpy(arr[i][j].d, temp, sizeof temp);
		}
	}
	memset(memo, -1, sizeof memo);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 6; ++j)
			ans = max(ans, arr[i][j].d[2] + dp(i, j, 1 << i));
	printf("%d\n", ans);
	return 0;
}
/*
5
10 10 10
50 50 50
40 40 40
20 20 20
30 30 30

2
20 20 20
30 33 10

2
100 10 10
100 12 8
 */

