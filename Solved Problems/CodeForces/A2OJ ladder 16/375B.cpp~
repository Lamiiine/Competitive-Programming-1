#include <bits/stdc++.h>
#define MAX 5002
using namespace std;
int n, m;
char s[MAX][MAX];
int acc[MAX * MAX] = { 0 };
inline int interval_idx(const int i, const int j)
{
	return i * MAX + j;
}
inline void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
		for (int j = 0; j < m; ++j)
		{
			s[i][j] -= '0';
		}
	}
}
inline void process()
{
	for (int r = 0; r < n; ++r)
	{
		const char * c = s[r];
		for (int i = 0; i < m; )
		{
			while (i < m && !c[i]) ++i;
			int j = i;
			while (j < m && c[j]) ++j;
			// You need to account for intervals [i, j - 1], [i + 1, j - 1], ... [j - 1, j - 1]
			while (i < j)
			{
				++acc[interval_idx(i, i)];
				--acc[interval_idx(i, j)];
				++i;
			}
		}
	}
	for (int i = 1; i < MAX * MAX; ++i)
		acc[i] += acc[i - 1];
}
int main()
{
	read();
	process();
	int ans = 0;
	for (int i = 0; i < m; ++i)
	{
		for (int j = i; j < m; ++j)
		{
			ans = max(ans, (j - i + 1) * acc[interval_idx(i, j)]);
		}
	}
	printf("%d", ans);
	return 0;
}
/*
1 1
1

2 2
10
11

4 3
100
011
000
101

4 3
100
011
000
111

 */

