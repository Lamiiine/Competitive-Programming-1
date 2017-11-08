#include<bits/stdc++.h>
#define MAX_L 1024
#define MAX_N 55
using namespace std;
int n, l;
vector<int> loc;
int memo[MAX_N][MAX_N];
/*
100
3
25 50 75
10
4
4 5 7 8
0
 */
inline int dp(const int i, const int j)
{
	// memorization
	int & ret = memo[i][j];
	if (ret != -1)
	{
		return ret;
	}
	if (j <= i + 1)
	{
		return ret = 0;
	}
	// recursion
	ret = INT_MAX;
	for (int k = i + 1; k < j; ++k)
	{
		ret = min(ret, loc[j] - loc[i] + dp(i, k) + dp(k, j));
	}

	return ret;
}
int main()
{
	while(scanf("%d", &l), l)
	{
		loc.clear();
		loc.push_back(0);
		scanf("%d", &n);
		for (int i = 0, x; i < n; ++i)
		{
			scanf("%d", &x);
			loc.push_back(x);
		}
		loc.push_back(l);
		memset(memo, -1, sizeof memo);
		printf("The minimum cutting is %d.\n", dp(0, loc.size() - 1));
	}
	return 0;
}

