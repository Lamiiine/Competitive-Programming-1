#include<bits/stdc++.h>
using namespace std;
int init_pos[8];
int cur_pos[8];
inline int rec(const int i)
{
	if (i == 8)
	{
		// 0 moves needed
		return 0;
	}

	int ans = 1000000;
	// try all rows
	for (int j = 0; j < 8; ++j)
	{
		bool flag = true;
		// check if this position is valid
		// looping over all the previous columns
		for (int k = 0; k < i && flag; ++k)
		{
			if (cur_pos[k] == j)
			{
				flag = false;
			}

			if (i + j == k + cur_pos[k])
			{
				flag = false;
			}

			if (i - j == k - cur_pos[k])
			{
				flag = false;
			}
		}
		// if so
		if (flag)
		{
			cur_pos[i] = j;
			ans = min(ans, (init_pos[i] != j) + rec(i + 1));
		}
	}

	return ans;
}
int main(void)
{
	for (int tc = 1; ~scanf("%d", init_pos); ++tc)
	{
		for (int i = 1; i < 8; ++i)
		{
			scanf("%d", init_pos + i);
		}
		for (int i = 0; i < 8; ++i)
		{
			--init_pos[i];
		}
		printf("Case %d: %d\n", tc, rec(0));
	}
	return 0;
}

