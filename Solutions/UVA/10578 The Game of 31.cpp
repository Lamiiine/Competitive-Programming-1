#include<bits/stdc++.h>
using namespace std;
char memo[5][5][5][5][5][5];
inline char dp(const int a, const int b, const int c, const int d, const int e, const int f)
{
	char & ret = memo[a][b][c][d][e][f];
	if (ret != -1)
	{
		return ret;
	}
	int cur[6] = {a, b, c, d, e, f};
	int cur_sum = 0;
	for (int i = 0; i < 6; ++i)
	{
		cur_sum += (4 - cur[i]) * (i + 1);
	}
	if (cur_sum > 31)
	{
		// the other player has exceeded 31
		return ret = 1;
	}
	for (int i = 0; i < 6; ++i)
	{
		// if card #i is available
		if (cur[i])
		{
			--cur[i];
			if (!dp(cur[0], cur[1], cur[2], cur[3], cur[4], cur[5]))
			{
				return ret = 1;
			}
			++cur[i];
		}
	}
	return ret = 0;
}
char s[50];
int main(void)
{
	memset(memo, -1, sizeof memo);
	while(~scanf("%s", s))
	{
		int cur[6] = {4, 4, 4, 4, 4, 4};
		int n = strlen(s);
		for (int i = 0; i < n; ++i)
		{
			--cur[s[i] - '1'];
		}
		char next_player = (n & 1) ? 'B' : 'A';
		printf("%s ", s);
		if (dp(cur[0], cur[1], cur[2], cur[3], cur[4], cur[5]))
		{
			printf("%c", next_player);
		}
		else
		{
			printf("%c", next_player == 'A' ? 'B' : 'A');
		}
		printf("\n");
	}
	return 0;
}

