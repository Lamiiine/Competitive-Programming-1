#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define MOD 1000000007
using namespace std;
typedef long long int ll;
int n, w, h;
ll memo[102][10100];
/* number of ways of assigning ribbon starting at index i the frame
* knowingt that you have j inches left of the ribbon
*/
inline void build_memo(void)
{
	for (int i = 0; i <= n; ++i)
	{
		memo[w][i] = 1;
	}
	for (int i = 0; i <= w; ++i)
	{
		memo[i][0] = 1;
	}
	for (int i = w - 1; i >= 0; --i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ll & cur = memo[i][j];
			cur = 0LL;
			const int k = min(j, h);
			for (int t = 0; t <= k; ++t)
			{
				cur = (cur + memo[i + 1][j - t]) % MOD;
			}
		}
	}
}

int main(void)
{
	// freopen("Input.txt", "r", stdin);
	scanf("%d%d%d", &n, &w, &h);
	/*
	how many plain scenes can you form?
	you can form a plain scene of height 0, 1, 2, ... min(h + 1, floor(n / w))
	*/
	build_memo();
	cout << (memo[0][n] - min(h + 1, n / w + 1) + MOD) % MOD;
	return 0;
}