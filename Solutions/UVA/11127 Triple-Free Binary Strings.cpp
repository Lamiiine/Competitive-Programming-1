#include<bits/stdc++.h>
#define MAX 64
using namespace std;
char s[MAX];
int ans;
int n;
// are the first i items of the array valid?
inline bool valid(const int i)
{
	for (int j = 1; j * 3 <= i; ++j)
		if (!strncmp(s + i - j, s + i - 2 * j, j) && !strncmp(s + i - 2 * j, s + i - 3 * j, j))
			return false;

	return true;
}
inline void rec(const int i)
{
	if (i == n)
		++ans;
	else
	{
		if (s[i] == '*')
		{
			s[i] = '1';
			if (valid(i + 1)) rec(i + 1);
			s[i] = '0';
			if (valid(i + 1)) rec(i + 1);
			s[i] = '*';
		}
		else
		{
			if (valid(i + 1)) rec(i + 1);
		}
	}
}
int main(void)
{
	for(int tc = 1; scanf("%d", &n), n; ++tc)
	{
		scanf("%s", s);
		ans = 0;
		rec(0);
		printf("Case %d: %d\n", tc, ans);
	}
	return 0;
}
/*
4 0**1
5 *****
10 **01**01**
0
 */

