#include<bits/stdc++.h>
#define MAX 11
using namespace std;
int o[135];
int m, n;
char memo[1 << MAX][1 << MAX];
inline char dp(const int questions, const int answers)
{
	char & ret = memo[questions][answers];
	if (ret != -1)
	{
		return ret;
	}
	// base case;
	{
		int count_match = 0;
		for (int i = 0; i < n; ++i)
		{
			count_match += ((o[i] & questions) == answers);
		}

		if (count_match == 1)
		{
			return ret = 0;
		}
	}
	// recursion
	ret = 20;
	for (int i = 0; i < m; ++i)
	{
		if (!(questions & (1 << i)))
		{
			// if not asked
			ret = min((char) ret,  char(1 + max(dp(questions | (1 << i), answers | (1 << i)), dp(questions | (1 << i), answers))));
		}
	}

	return ret;
}
inline bool read(void)
{
	scanf("%d%d", &m, &n);
	if (m == 0 && n == 0)
	{
		return false;
	}
	char s[MAX + 5];
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		int cur = 0;
		for (int j = 0; j < m; ++j)
		{
			if (s[j] == '1')
			{
				cur |= (1 << j);
			}
		}
		o[i] = cur;
	}
	return true;
}
inline void init(void)
{
	memset(memo, -1, sizeof memo);
}
int main(void)
{
	while(read())
	{
		init();
		printf("%d\n", dp(0, 0));
	}
	return 0;
}

