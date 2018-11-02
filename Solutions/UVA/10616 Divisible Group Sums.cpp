#include<bits/stdc++.h>
#define MAX 206
using namespace std;
typedef long long int ll;
int n, q, d, m;	// how many sets of size m are divisible by d?
ll memo[MAX][25][12];
int arr[MAX];
/*
 * starting at index i in the array, how many subsets are there of size
 * m that are divisible by d, knowing that you have accumulated a set of
 * size k that has a sum sum equal to j modulo d
 */
inline ll dp(const int i, const int j, const int k)
{
	ll & ret = memo[i][j][k];
	if (ret != -1LL) return ret;
	// base case
	if (k == m)
		return ret = (j == 0);
	if(i == n)
		return ret = 0LL;
	return ret = dp(i + 1, ((j + arr[i]) % d + d) % d, k + 1) + dp(i + 1, j, k);
}
inline void read(void)
{
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
}
int main(void)
{
	for(int Set = 1; scanf("%d%d", &n, &q), n || q; ++Set)
	{
		printf("SET %d:\n", Set);
		read();
		for(int Q = 1; q--; ++Q)
		{
			scanf("%d%d", &d, &m);
			memset(memo, -1, sizeof memo);
			printf("QUERY %d: %lld\n", Q, dp(0, 0, 0));
		}
	}
	return 0;
}

