#include<bits/stdc++.h>
using namespace std;
char memo[3][3][3][3][3][3][3][3][3][3][3][3][3][3][3][3];
// return 1 if and only if x wins
inline char dp(const int a1, const int a2, const int a3, const int a4, const int a5, const int a6, const int a7, const int a8, const int a9, const int a10, const int a11, const int a12, const int a13, const int a14, const int a15, const int a16)
{
	char & ret = memo[a1][a2][a3][a4][a5][a6][a7][a8][a9][a10][a11][a12][a13][a14][a15][a16];
	if (ret != -1)
	{
		return ret;
	}
	int cur[4][4] = {{a1, a2, a3, a4}, {a5, a6, a7, a8}, {a9, a10, a11, a12}, {a13, a14, a15, a16}};
	// base case?
	for (int i = 0; i < 4; ++i)
	{
		int z = cur[i][0];
		if (!z) continue;
		bool flag = true;
		for (int j = 1; j < 4; ++j)
		{
			if (cur[i][j] != z)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			return ret = (z == 1 ? 1 : 0);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		int z = cur[0][i];
		if (!z) continue;
		bool flag = true;
		for (int j = 1; j < 4; ++j)
		{
			if (cur[j][i] != z)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			return ret = (z == 1 ? 1 : 0);
		}
	}
	{
		int z;
		z = cur[0][0];
		if (z && cur[1][1] == z && cur[2][2] == z && cur[3][3] == z)
		{
			return ret = (z == 1) ? 1 : 0;
		}
		z = cur[0][3];
		if (z && cur[1][2] == z && cur[2][1] == z && cur[3][0] == z)
		{
			return ret = (z == 1) ? 1 : 0;
		}
	}
	// recurse
	int counter = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			counter += bool(cur[i][j]);
	if (counter & 1)
	{
		// o
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (!cur[i][j])
				{
					cur[i][j] = 2;
					if (!dp(cur[0][0], cur[0][1], cur[0][2], cur[0][3], cur[1][0], cur[1][1], cur[1][2], cur[1][3], cur[2][0], cur[2][1], cur[2][2], cur[2][3], cur[3][0], cur[3][1], cur[3][2], cur[3][3]))
					{
						return ret = 0;
					}
					cur[i][j] = 0;
				}
			}
		}
		return ret = 1;
	}
	else
	{
		// x
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (!cur[i][j])
				{
					cur[i][j] = 1;
					if (dp(cur[0][0], cur[0][1], cur[0][2], cur[0][3], cur[1][0], cur[1][1], cur[1][2], cur[1][3], cur[2][0], cur[2][1], cur[2][2], cur[2][3], cur[3][0], cur[3][1], cur[3][2], cur[3][3]))
					{
						return ret = 1;
					}
					cur[i][j] = 0;
				}
			}
		}
		return ret = 0;
	}
}
int init[4][4];
inline void read(void)
{
	char s[5];
	for (int i = 0; i < 4; ++i)
	{
		scanf("%s", s);
		for (int j = 0; j < 4; ++j)
		{
			init[i][j] = s[j] == '.' ? 0 : s[j] == 'x' ? 1 : 2;
		}
	}
}
int main(void)
{
	memset(memo, -1, sizeof memo);
	char temp[5];
	while(scanf("%s", temp), *temp == '?')
	{
		read();
		bool flag = false;
		for (int i = 0; i < 4 && !flag; ++i)
		{
			for (int j = 0; j < 4 && !flag; ++j)
			{
				if (!init[i][j])
				{
					init[i][j] = 1;
					if (dp(init[0][0], init[0][1], init[0][2], init[0][3], init[1][0], init[1][1], init[1][2], init[1][3], init[2][0], init[2][1], init[2][2], init[2][3], init[3][0], init[3][1], init[3][2], init[3][3]))
					{
						printf("(%d,%d)\n", i, j);
						flag = true;
					}
					init[i][j] = 0;
				}
			}
		}
		if (!flag)
		{
			printf("#####\n");
		}
	}
	return 0;
}

