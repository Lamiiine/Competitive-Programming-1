#include<bits/stdc++.h>
using namespace std;
int n, m;
bool flag;
int arr[2200];
int ans[1 << 10];
/*
 * knapsack style problem
 * using recursive backtracking (high complexity, however
 * it finds a solution and returns quickly)
 */
inline void rec(const int i, const int j, const int k)
{
	// starting at i, with count = j, and sum = k
	if (k == 0 && j == n)
	{
		flag = true;
		return;
	}
	if (j == n || i == m)
	{
		return;
	}
	ans[j] = arr[i];
	rec(i + 1, j + 1, (k + arr[i]) % n);
	if (!flag)
	{
		rec(i + 1, j, k);
	}
}
int main(void)
{
	while(scanf("%d", &n), n)
	{
		m = (n << 1) - 1;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d", arr + i);
		}
		flag = false;
		rec(0, 0, 0);
		if (!flag)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
			for (int i = 0; i < n; ++i)
			{
				printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
			}
		}
	}
	return 0;
}

