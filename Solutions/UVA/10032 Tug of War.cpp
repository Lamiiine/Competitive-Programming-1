#include<bits/stdc++.h>
#define MAX 54
using namespace std;
bool memo[MAX][MAX * 450];
int arr[MAX << 1];
int acc[MAX << 1];
int n;
inline void init_memo(void)
{
	memset(memo, 0, sizeof memo);
	memo[0][0] = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int sz = min(i + 1, n >> 1); sz >= 1; --sz)
		{
			const int cur = arr[i];
			for (int tot = min(MAX*450 - 1, acc[i]); tot >= cur; --tot)
			{
				memo[sz][tot] |= memo[sz - 1][tot - cur];
			}
		}
	}
}
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
	}
	acc[0] = arr[0];
	for (int i = 1; i < n; ++i)
		acc[i] = acc[i - 1] + arr[i];
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		init_memo();
		int x = 0, y = acc[n - 1];
		for (int i = 0; i < 25505; ++i)
		{
			if (memo[n >> 1][i] && abs(acc[n-1] - (i << 1)) < abs(x - y))
			{
				x = i; y = acc[n - 1] - i;
			}
		}
		printf("%d %d\n", min(x, y), max(x, y));
		if (TC) printf("\n");
	}
	return 0;
}

