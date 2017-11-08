#include<bits/stdc++.h>
#define MAX (1 << 10)
using namespace std;
int n;
char memo[MAX][MAX];
/* return true if and only if you can divide i
 * over j losing values!
 */
inline char dp(const int i, const int j)
{
	char & ret = memo[i][j];
	// memorization
	if (ret != -1)
	{
		return ret;
	}

	// base case!
	if (j == 1)
	{
		return ret = !dp(i, n);
	}

	// recursion
	for (int k = 1; k < i; ++k)
	{
		/*
		 * which one do you call first???
		 * Order matters. Order really matters. It could save you a TLE verdict.
		 */
		if (!dp(k, n) && dp(i - k, j - 1))
		{
			return ret = 1;
		}
	}

	return ret = 0;
}

inline void init_memo(void)
{
	memset(memo, -1, sizeof memo);
	for (int i = 0; i < MAX; ++i)
	{
		// int * cur = memo[i];
		// memo[i][i] = 1;
		for (int j = i + 1; j < MAX; ++j)
		{
			memo[i][j] = 0;	// losing!
		}
	}

	memo[0][0] = 1;

	for (int i = 1; i < MAX; ++i)
	{
		memo[i][0] = 0;
	}
	
	/*
	for (int i = 0; i < MAX; ++i)
		memo[i][i] = 1;
	*/
}

int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init_memo();
		scanf("%d", &n);
		bool flag = false;
		for (int i = 0, a; i < n; ++i)
		{
			scanf("%d", &a);
			if (!flag && dp(a, n))
			{
				flag = true;
			}
		}

		printf("%s\n", flag ? "Alice" : "Bob");
	}

	return 0;
}

