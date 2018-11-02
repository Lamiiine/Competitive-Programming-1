#include <bits/stdc++.h>
#define MAX_M 1024
#define MAX_W 16
using namespace std;
char memo[MAX_M][MAX_W][MAX_W];
char available_weight_str[MAX_W];
int m;
inline bool has_weight(const int w)
{
	return available_weight_str[w - 1] == '1';
}
inline char dp(const int rem, const int last, const int diff)
{
	char & ret = memo[rem][last][diff];
	if (~ret) return ret;
	ret = 0;
	// try different weights!
	for (int i = 1; i <= 10 && !ret; ++i)
	{
		if (has_weight(i) && i != last && i > diff)
		{
			ret |= dp(rem - 1, i, i - diff);
		}
	}
	return ret;
}
inline void init()
{
	memset(memo, -1, sizeof memo);
	memset(memo[0], 1, sizeof memo[0]);
}
inline void read()
{
	scanf("%s", available_weight_str);
	scanf("%d", &m);
}
inline void path(const int rem, const int last, const int diff)
{
	for (int i = 1; i <= 10; ++i)
	{
		if (has_weight(i) && i != last && i > diff && dp(rem - 1, i, i - diff))
		{
			printf("%d", i);
			if (rem != 1)
			{
				printf(" ");
				path(rem - 1, i, i - diff);
			}
			break;
		}
	}
}
int main()
{
	init();
	read();
	const char ans = dp(m, 0, 0);
	if (ans)
	{
		printf("YES\n");
		path(m, 0, 0);
	}
	else
	{
		printf("NO");
	}
	return 0;
}
/*
0000000101
3

1000000000
2
 */

