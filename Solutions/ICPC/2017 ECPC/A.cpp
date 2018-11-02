#include <bits/stdc++.h>
#define MAX_N 52
#define MAX_K 3002
using namespace std;
typedef long double ld;
int n, x, y, k;
ld p;
ld memo_equal[MAX_N][MAX_K];
ld memo[MAX_N][MAX_N][MAX_K];
inline void init()
{
	for (int i = 0; i < MAX_N; ++i)
	{
		for (int j = 0; j < MAX_N; ++j)
		{
			for (int k = 0; k < MAX_K; ++k)
			{
				memo[i][j][k] = -1.0;
			}
		}
	}
	for (int i = 0; i < MAX_N; ++i)
	{
		for (int j = 0; j < MAX_K; ++j)
		{
			memo_equal[i][j] = -1.0;
		}
	}
}
inline ld dp_equal(const int i, const int k)
{
	ld & ret = memo_equal[i][k];
	// memorization
	if (ret != -1.0) return ret;
	// base case
	if (!k) return ret = (i == x) ? 1.0 : 0.0;
	ret = 0.0; int p_count = 0;
	if (i) ret += p * dp_equal(i - 1, k - 1), ++p_count;
	if (i < n - 1) ret += p * dp_equal(i + 1, k - 1), ++p_count;
	ret += (1.0 - p * p_count) * dp_equal(i, k - 1);
	return ret;
}
inline bool valid(const int i, const int j)
{
	return i >= 0 && i < n && j >= 0 && j < n && i != j;
}
inline ld dp(const int i, const int j, const int k)
{
	ld & ret = memo[i][j][k];
	// memorization
	if (ret != -1.0) return ret;
	// base case
	if (!k) return ret = (x == j && i == y) ? 1.0 : 0.0;
	// recursion
	ret = 0.0;
	int p_count = 0;
	if (abs(i - j) == 1) ret += p * dp(j, i, k - 1), ++p_count;
	if (valid(i + 1, j)) ret += p * dp(i + 1, j, k - 1), ++p_count;
	if (valid(i - 1, j)) ret += p * dp(i - 1, j, k - 1), ++p_count;
	if (valid(i, j + 1)) ret += p * dp(i, j + 1, k - 1), ++p_count;
	if (valid(i, j - 1)) ret += p * dp(i, j - 1, k - 1), ++p_count;
	ret += (1.0 - p_count * p) * dp(i, j, k - 1);
	return ret;
}
inline ld solve()
{
	// scanf("%d%llf%d%d%d", &n, &p, &x, &y, &k);
	cin >> n >> p >> x >> y >> k;
	if (n == 1) return 1.0;
	p /= (n - 1.0);
	return (x == y) ? dp_equal(x, k) : dp(x, y, k);
}
int main()
{
	freopen("assessment.in", "r", stdin);
	int TC; cin >> TC; // scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		init();
		// printf("Case %d: %.5llf\n", tc, solve());
		cout << "Case " << tc << ": " << fixed << setprecision(5) << solve() << endl;
	}
	return 0;
}
/*
3
4 1.0 1 1 2
4 0.0 0 2 1
2 0.5 0 1 1
 */

