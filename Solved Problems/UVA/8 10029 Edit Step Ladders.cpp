#include<bits/stdc++.h>
#define MAX 25002
using namespace std;
int memo[MAX];
char s[MAX][20];
int n;
inline bool step(const char * c, const char * s)
{
	int i = 0;

	while(i < n && c[i] == s[i])
		++i;

	return (i < n) && (
			(!strcmp(c + i, s + i + 1))
			|| (!strcmp(c + i + 1, s + i))
			|| (!strcmp(c + i + 1, s + i + 1))
			);
}

inline void solve(void)
{
	memo[n] = 0;
	memo[n - 1] = 1;
	for (int j = n - 2; j >= 0; --j)
	{
		int & cur = memo[j];
		cur = 1;
		for (int i = j + 1; i < n; ++i)
		{
			if (step(s[j], s[i]))
			{
				cur = max(cur, 1 + memo[i]);
			}
		}
	}
}

int main(void)
{
	n = 0;
	while(~scanf("%s", s[n]))
	{
		++n;
	}
	solve();
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, memo[i]);
	}

	printf("%d\n", ans);
	return 0;
}

