#include <bits/stdc++.h>
#define MAX 102
using namespace std;
int n;
int ans[MAX][MAX];
int main()
{
	cin >> n;
	// loop over rows!
	int a = 1, b = n * n;
	for (int r = 0; r < n; ++r)
	{
		for (int c1 = 0, c2 = n - 1; c1 < c2; ++c1, --c2)
		{
			ans[r][c1] = a++;
			ans[r][c2] = b--;
		}
	}
	for (int r = 0; r < n; ++r)
	{
		for (int c = 0; c < n; ++c)
		{
			printf("%d%c", ans[r][c], c == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}
