#include<bits/stdc++.h>
#define MAX 11
#define INF 1000000
using namespace std;

int counter;
int cover[MAX][MAX];
int r, c;
char s[MAX][MAX];
int ans;
inline void read(void)
{
	scanf("%d%d", &r, &c);
	for (int i = 0; i < r; ++i)
		scanf("%s", s[i]);
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			counter += (s[i][j] == '#');
}
inline bool all_clear(void)
{
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			if (s[i][j] == '#' && !cover[i][j])
				return false;
	return true;
}

const int di[5] = {0, 0, 0, 1, -1},
		dj[5] = {0, 1, -1, 0, 0};
inline void flip(const int i, const int j)
{
	for (int k = 0; k < 5; ++k)
		if (++cover[i + di[k]][j + dj[k]] == 1)
			--counter;
}
inline void de_flip(const int i, const int j)
{
	for (int k = 0; k < 5; ++k)
		if(!--cover[i + di[k]][j + dj[k]])
			++counter;
}
inline bool is_center(const int i, const int j)
{
	for (int k = 0, x, y; k < 5; ++k)
	{
		x = i + di[k],
				y = j + dj[k];
		if (s[x][y] == '.')
			return false;
	}

	for (int k = 0, x, y; k < 5; ++k)
	{
		x = i + di[k],
				y = j + dj[k];
		if (s[x][y] == '#' && !cover[x][y])
			return true;
	}

	return false;
}
inline void rec(const int i, const int j, const int cur)
{
	if (cur + counter / 5 >= ans)
		return;
	if (i == r - 1 && j == 1)
	{
		// base case!
		if (all_clear())
			ans = cur;
		return;
	}
	if (j == c - 1)
	{
		rec(i + 1, 1, cur);
		return;
	}

	if (
			// if you can only be covered by you!
			!(s[i][j] == '#' && !cover[i][j] && j == c - 2 && i == r - 2)
			// if the one above can not be covered except by you!
			&& !(s[i - 1][j] == '#' && !cover[i - 1][j])
			// if the one below can not be covered except by you!
			&& !(i == r - 2 && s[i + 1][j] == '#')
			// if the one to the left can not be covered except by you!
			&& !(j == 1 && s[i][j - 1] == '#')
			// if the one to the right can not be covered except by you!
			&& !(j == c - 2 && s[i][j + 1] == '#')
			)
		rec(i, j + 1, cur);
	if (is_center(i, j))
	{
		// you can only call this case if you are a center
		flip(i, j);
		rec(i, j + 1, cur + 1);
		de_flip(i, j);
	}
}
int main(void)
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		memset(cover, 0, sizeof cover);
		counter = 0;
		read();
		if (r <= 2 || c <= 2)
		{
			ans = all_clear() ? 0 : INF;
		}
		else if (s[0][0] == '#' || s[0][c - 1] == '#' || s[r - 1][c - 1] == '#'|| s[r - 1][0] == '#')
		{
			ans = INF;
		}
		else
		{
			ans = INF;
			rec(1, 1, 0);
		}
		printf("Image #%d: ", tc);
		if (ans >= INF) printf("impossible");
		else printf("%d", ans);
		printf("\n\n");
	}
	return 0;
}
/*
5
1 1
.
1 1
#
3 3
.#.
###
.#.
3 5
.#.#.
#####
.#.#.
4 7
.##.#..
######.
.######
..#..#.

9 9
.#######.
#########
#########
#########
#########
#########
#########
#########
.#######.

8 8
.######.
########
########
########
########
########
########
.######.
7 7
.#####,
#######
#######
#######
#######
#######
.#####.
5 5
.###.
#####
#####
#####
.###.
 */

