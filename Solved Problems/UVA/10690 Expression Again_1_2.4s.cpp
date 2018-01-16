// optimization DP
// passed in 2.4 seconds
#include <bits/stdc++.h>
#define MAX 51
using namespace std;
int arr[MAX << 1];
int tot;
int memo_min[MAX << 1][MAX][MAX*100];
int memo_max[MAX << 1][MAX][MAX*100];
int n,m;
inline void read(void)
{
	for (int i = 0; i < (n + m); ++i)
	{
		scanf("%d", arr + i);
	}
}
inline void init(void)
{
	tot = 0;
	for (int i = 0; i < (n + m); ++i)
	{
		tot += arr[i];
	}
	for (int i = 0; i < (n + m); ++i)
	{
		arr[i] += 50;
	}
	memset(memo_min, 0xFF, (n + m + 1) * sizeof memo_min[0]);
	memset(memo_max, 0xFF, (n + m + 1) * sizeof memo_max[0]);
}
/* dp_min(i, j, k) returns the minimum value you can obtain
starting at index i, knowing that you have assigned j integers
to the first bracket (which is supposed to contain a total of n
elements at the end), where the j integers sum up to k */
inline int dp_min(const int i, const int j, const int k)
{
	int & ret = memo_min[i][j][k];
	if (ret != -1)
	{
		return ret;
	}
	if (j == n) 
	{
		return ret = (tot - (k - 50 * n)) * (k - 50 * n);
	}
	if (m - i + j < 0)
	{
		/* if the number of remaining integers is not enough
		to assign n values to the first expression, prune
		#remaining = n + m - i
		#needed = n - j
		it must be that n + m - i >= n - j
		m - i >= - j
		*/
		return ret = INT_MAX;
	}
	return ret = min(dp_min(i + 1, j, k), dp_min(i + 1, j + 1, k + arr[i]));
}
inline int dp_max(const int i, const int j, const int k)
{
	int & ret = memo_max[i][j][k];
	if (ret != -1)
	{
		return ret;
	}
	if (j == n) 
	{
		return ret = (tot - (k - 50*n)) * (k - 50*n);
	}
	if (m - i + j < 0)
	{
		return ret = INT_MIN;
	}
	return ret = max(dp_max(i + 1, j, k), dp_max(i + 1, j + 1, k + arr[i]));
}
int main() {
	while(~scanf("%d%d", &n, &m))
	{
		read();
		init();
		printf("%d %d\n", dp_max(0, 0, 0), dp_min(0, 0, 0));
	}
	return 0;
}
