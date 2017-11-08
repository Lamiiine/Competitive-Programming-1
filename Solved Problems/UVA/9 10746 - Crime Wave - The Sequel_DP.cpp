#include<bits/stdc++.h>
#define MAX 20
#define lsone(s) ((s) & (-s))
#define inf 1e9
#define eps 1e-9
using namespace std;
int n, m;
inline int count_ones(int i)
{
	int ans = 0;
	while(i)
		++ans, i -= lsone(i);
	return ans;
}
double memo[1 << MAX];
inline void init(void)
{
	for (int i = 0; i < (1 << MAX); ++i)
		memo[i] = -1.0;
}
double mat[MAX][MAX];	// mat[i][j] = reachability time to bank i from officer j
inline double dp(const int mask)
{
	// having used the officer marked in 'mask'
	double & ret = memo[mask];
	if (ret != -1.0) return ret;
	const int i = count_ones(mask);
	if (i == n) return ret = 0.0;
	ret = inf;
	for (int j = 0; j < m; ++j)
		if (!(mask & (1 << j)))
			ret = min(ret, mat[i][j] + dp(mask | (1 << j)));
	return ret;
}
inline void read(void)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%lf", mat[i] + j);
}
int main(void)
{
	while(scanf("%d%d", &n, &m), n || m)
	{
		init();
		read();
		printf("%.2lf\n", dp(0) / n + eps);
	}
	return 0;
}

