#include<bits/stdc++.h>
#define MAX (1 << 4)
using namespace std;
typedef pair<int, int> ii;
int arr[MAX][MAX];
int ans;
inline void read(void)
{
	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; ++j)
			if (i || j) scanf("%d", arr[i] + j);
}
inline bool valid(const int i, const int j, const int x)
{
	for (int k = 0; k < 9; ++k)
		for (int t = 0; t < 9; ++t)
			if ((i != k || j != t)
					&& (i == k || j == t || (i / 3 == k / 3 && j / 3 == t / 3))
					&& arr[k][t] == x)
				return false;

	return true;
}
inline void rec(const int idx)
{
	if (idx == 81)
	{
		++ans;
		return;
	}
	const int i = idx / 9, j = idx % 9;
	if (arr[i][j])
	{
		rec(idx + 1);
		return;
	}

	for (int k = 1; k <= 9 && ans < 2; ++k)
		if (valid(i, j, k))
		{
			arr[i][j] = k;
			rec(idx + 1);
		}
	arr[i][j] = 0;
}
int main(void)
{
	for(int tc = 1; ~scanf("%d", arr[0] + 0); ++tc)
	{
		read();
		bool illiegal = false;
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				for (int k = 0; k < 9; ++k)
					for (int t = 0; t < 9; ++t)
						if ((i != k || j != t)
								&& (i == k || j == t || (i / 3 == k / 3 && j / 3 == t / 3))
								&& arr[i][j]
								&& arr[i][j] == arr[k][t])
						{
							illiegal = true;
						}

		printf("Case %d: ", tc);
		if (illiegal) printf("Illegal");
		else
		{
			ans = 0;
			rec(0);
			switch(ans)
			{
			case 0: printf("Impossible"); break;
			case 1: printf("Unique"); break;
			case 2: printf("Ambiguous"); break;
			}

		}
		printf(".\n");
	}
	return 0;
}

