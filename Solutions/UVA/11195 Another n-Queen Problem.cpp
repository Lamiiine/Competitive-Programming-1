#include<bits/stdc++.h>
#define MAX 16
using namespace std;
char s[MAX][MAX];
int n;
int pos[MAX];
int ans;
inline void read(void)
{
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s[i]);
	}
}
inline void init(void)
{
	ans = 0;
}
inline void rec(const int i, const int rows, const int ld, const int rd)
{
	if (i == n)
	{
		++ans;
		return;
	}

	for (int j = 0; j < n; ++j)
	{
		if (s[j][i] == '.' && !(rows & (1 << j)) && !(ld & (1 << (i + j))) && !(rd & (1 << (i - j + MAX))))
		{
			pos[i] = j;
			rec(i + 1, rows | (1 << j), ld | (1 << (i + j)), rd | (1 << (i - j + MAX)));
		}
	}
}
int main(void)
{
	for (int tc = 1; scanf("%d", &n), n; ++tc)
	{
		read();
		init();
		rec(0, 0, 0, 0);
		printf("Case %d: %d\n", tc, ans);
	}
	return 0;
}

