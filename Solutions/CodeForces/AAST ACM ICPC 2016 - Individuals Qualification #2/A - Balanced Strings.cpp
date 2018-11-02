#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char s[102];
int n;
ll memo[105][2];
const char vowels[7] = "aeiouy";
inline bool vowel(const char c)
{
	return binary_search(vowels, vowels + 7, c);
}
inline ll dp(const int i, const int j)
{
	ll & ret = memo[i][j];
	if (ret != -1LL)
	{
		return ret;
	}
	if (i == n)
	{
		return ret = 1LL;
	}
	const char c = s[i];
	if (c == '?')
	{
		return ret = ((bool) j) ? 20 * dp(i + 1, 0) : 6 * dp(i + 1, 1);
	}

	if ((bool)vowel(c) == bool(j))
	{
		return ret = 0;
	}
	return ret = dp(i + 1, vowel(c));
}
inline void init_memo(void)
{
	memset(memo, -1, sizeof memo);
}
int main(void)
{
	int TC; scanf("%d", &TC);
	for(int tc = 1; tc <= TC; ++tc)
	{
		scanf("%s", s);
		n = strlen(s);
		init_memo();
		const char c = s[0];
		ll ans;
		if (c != '?')
		{
			ans = dp(1, vowel(c));
		}
		else
		{
			ans = 6 * dp(1, 1) + 20 * dp(1, 0);
		}

		cout << "String #" << tc << ": " << ans << "\n\n";
	}
	return 0;
}
/*
7
orooji
al?
a?i
g?ha
a?u?
?????????????????
arup
 */

