#include<bits/stdc++.h>
#define MAX 16
#define INF 1000000
using namespace std;
char name[1 << 11];
char s[MAX][MAX];
bool arr[MAX][MAX];
int ans;
const int dx[5] = {0, 0, 0, 1, -1};
const int dy[5] = {0, 1, -1, 0, 0};
inline void flip(const int i, const int j)
{
	for (int k = 0; k < 5; ++k)
	{
		const int x = i + dx[k];
		const int y = j + dy[k];
		if (x >= 0 && x < 10 && y >= 0 && y < 10)
		{
			arr[x][y] = !arr[x][y];
		}
	}
}
void rec(const int idx, const int acc)
{
	if (idx == 100)
	{
		bool flag = true;
		for (int i = 0; i < 10; ++i)
		{
			if (arr[9][i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			ans = min(ans, acc);
		return;
	}

	// bound recursive backtracking
	if (acc > ans)
	{
		return;
	}

	const int i = idx / 10, j = idx % 10;
	if (i == 0)
	{
		rec(idx + 1, acc);
		flip(i, j);
		rec(idx + 1, acc + 1);
		flip(i, j);
	}
	else
	{
		if (arr[i - 1][j])
		{
			flip(i, j);
			rec(idx + 1, acc + 1);
			flip(i, j);
		}
		else
		{
			rec(idx + 1, acc);
		}
	}
}

int main(void)
{
	while(scanf("%s", name), strcmp(name, "end"))
	{
		ans = INF;
		for (int i = 0; i < 10; ++i)
			scanf("%s", s[i]);
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				arr[i][j] = !(s[i][j] == '#');
			}
		}
		rec(0, 0);
		printf("%s %d\n", name, ans == INF ? -1 : ans);
	}
}

