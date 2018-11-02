#include<bits/stdc++.h>
#define MAX 12
using namespace std;
int fact[MAX + 3];
inline void init_fact(void)
{
	fact[0] = 1;
	for (int i = 1; i <= MAX; ++i)
	{
		fact[i] = i * fact[i - 1];
	}
}
int memo[MAX + 1][1 << MAX];
inline int dp(const int i, const int mask)
{
	// memory
	int & ret = memo[i][mask];
	if (ret != -1)
	{
		return ret;
	}
	// base case
	if (mask == (1 << MAX) - 1)
	{
		return ret = 1;
	}
	ret = 0;
	for (int j = 0; j < MAX; ++j)
	{
		// current hat is empty!
		if (i != j && !(mask & (1 << j)))
		{
			ret += dp(i + 1, mask | (1 << j));
		}
	}
	return ret;
}
int main(void)
{
	memset(memo, -1, sizeof memo);
	init_fact();
	int TC; scanf("%d", &TC);
	for(int n; TC--;)
	{
		scanf("%d", &n);
		printf("%d/%d\n", dp(0, ((1 << MAX) - 1) &~((1 << n) - 1)), fact[n]);
	}
	return 0;
}

