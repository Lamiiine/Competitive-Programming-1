#include <bits/stdc++.h>
#define MAX 10010
#define OO 1000000
using namespace std;
int n, m;
int memo[MAX][10];
/*
 * what is the minimum number of jumps, required to climb a distance of i,
 * knowing that your current number of moves is j
 */
inline int dp(const int i, const int j)
{
	int & ret = memo[i][j];
	// memorization
	if (ret != -1) return ret;
	// base case
	if (!i) return ret = (!j ? 0 : OO);
	// recursion
	return ret = 1 + min(i >= 2 ? dp(i - 2, (j + 1) % m) : OO, dp(i - 1, (j + 1) % m));
}
int main()
{
	memset(memo, -1, sizeof memo);
	cin >> n >> m;
	const int ans = dp(n, 0);
	cout << (ans < OO ? ans : -1);
	return 0;
}
