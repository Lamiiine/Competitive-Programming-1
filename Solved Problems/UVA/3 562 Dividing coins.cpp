#include<bits/stdc++.h>
#define MAX 102
using namespace std;
int arr[MAX], acc[MAX], n, tot;
int memo[MAX][MAX*500];
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	if (i == n) return ret = abs((tot - j) - j);
	return ret = min(dp(i + 1, j), dp(i + 1, j + arr[i]));
}

int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		memset(memo, -1, sizeof memo);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		tot = 0;
		for (int i = 0; i < n; ++i)
			tot += arr[i];
		printf("%d\n", dp(0, 0));
	}
}
/*
2
3
2 3 5
4
1 2 4 6
 */

