#include<bits/stdc++.h>
#define found(mask, i) ((mask) & (1 << (i)))
using namespace std;
char s[10];
char memo[1 << 7][1 << 5];
inline int merge(int i, int j)
{
	return i + j + 1;
}
// you have the ones marked in i available, and you need to reach j!
inline char dp(const int i, const int j)
{
	// memory
	char & ret = memo[i][j];
	if (ret != -1) return ret;
	// base
	if (!j) return ret = 1;
	if (!i) return ret = 0;
	// recursion
	// 1. try taking one problem
	for (int k = 0; k < 7; ++k)
		if (found(i, k) && found(j, s[k]) && dp(i - (1 << k), j - (1 << s[k])))
			return ret = 1;
	// 2. try taking two problems
	for (int k = 0; k < 7; ++k)
		for (int t = k + 1; t < 7; ++t)
			if (found(i, k) && found(i, t) && found(j, s[t] + s[k] + 1) && dp(i - (1 << k) - (1 << t), j - (1 << (s[t] + s[k] + 1))))
				return ret = 1;
	return ret = 0;
}
inline void init()
{
	memset(memo, -1, sizeof memo);
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		scanf("%s", s);
		for (int i = 0; i < 7; ++i)
			s[i] -= 'A';
		printf("%s\n", dp((1 << 7) - 1, (1 << 5) - 1) ? "YES" : "NO");
	}
	return 0;
}
