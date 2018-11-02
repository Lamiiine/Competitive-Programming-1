#include<bits/stdc++.h>
#define MAX 302
using namespace std;
typedef long long int ll;
const int n = 301;
int arr[MAX];
ll memo[MAX][MAX];
/*
 * memo[i][j] counts the number of ways a set of size i
 * can sum up to j!
 */
inline void solve(void)
{
	memset(memo, 0, sizeof memo);
	memo[0][0] = 1LL;
	for (int i = 1; i < n; ++i)
	{
		const int v = arr[i];
		for (int j = 1; j < MAX; ++j)
			for (int k = v; k < MAX; ++k)
				memo[j][k] += memo[j - 1][k - v];
	}
}
const char space[6] = " \n\t";
inline void init_arr(void)
{
	for (int i = 1; i <= 300; ++i)
		arr[i] = i;
}
int main(void)
{
	init_arr();
	solve();
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
				ans += memo[j][v[0]];
		}
		if (v.size() == 2)
		{
			v[1] = min(v[1], 300);
			for (int j = 0; j <= v[1]; ++j)
				ans += memo[j][v[0]];
		}
		if (v.size() == 3)
		{
			v[2] = min(v[2], 300);
			for (int j = v[1]; j <= v[2]; ++j)
				ans += memo[j][v[0]];
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

