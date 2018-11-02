#include<bits/stdc++.h>
#define MAX 302
using namespace std;
typedef long long int ll;
const int n = 300;
int arr[MAX];
ll memo[MAX][MAX][MAX];
/*
 * memo[i][j][k] counts how many ways one can obtain a sum of size j
 * summing up to k, starting at coin value i
 */
inline void init(void)
{
	memset(memo, -1, sizeof memo);
}
inline ll dp(const int i, const int j, const int k)
{
	ll & ret = memo[i][j][k];
	if (ret != -1LL) return ret;
	if (j == 0 || k == 0)
		return ret = (j == 0 && k == 0);
	if (i == 301) return ret = 0LL;
	return ret = dp(i + 1, j, k) + (k >= arr[i] ? dp(i, j - 1, k - arr[i]) : 0);
}
const char space[6] = " \n\t";
inline void init_arr(void)
{
	for (int i = 1; i <= 300; ++i)
		arr[i] = i;
}
int main(void)
{
	memset(memo, -1, sizeof memo);
	init_arr();
	string line;
	while(getline(cin, line))
	{
		vector<int> v;
		for (char * c = strtok(const_cast<char *> (line.c_str()), space); c; c = strtok(0, space))
		{
			int x;
			sscanf(c, "%d", &x);
			v.push_back(x);
		}
		ll ans = 0LL;
		if (v.size() == 1)
		{
			for (int j = 0; j < MAX; ++j)
				ans += dp(1, j, v[0]);
		}
		if (v.size() == 2)
		{
			v[1] = min(v[1], 300);
			for (int j = 0; j <= v[1]; ++j)
				ans += dp(1, j, v[0]);
		}
		if (v.size() == 3)
		{
			v[2] = min(v[2], 300);
			for (int j = v[1]; j <= v[2]; ++j)
				ans += dp(1, j, v[0]);
		}

		printf("%lld\n", ans);
	}
}
/*
6
6 3
6 2 5
6 1 6
 */

