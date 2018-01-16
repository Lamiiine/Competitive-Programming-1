#include<bits/stdc++.h>
#define MAX 16
#define X real()
#define Y imag()
#define cross(a, b) ((a).X * (b).Y - (a).Y * (b).X)
using namespace std;
typedef complex<int> point;
bool memo[MAX][MAX] = { 0 };
point s[MAX], e[MAX];
int n;
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 0, a, b, c, d; i < n; ++i)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		s[i] = point(a, b);
		e[i] = point(c, d);
	}
}
enum dir {RIGHT, LEFT, ON};
dir get_dir(const point & v, const point & u)
{
	int d = cross(v, u);
	if (!d)
	{
		return ON;
	}
	return d > 0 ? RIGHT: LEFT;
}
inline bool on_seg(const point & p, const point & q, const point & a)
{
	// is a inside pq
	return (a.X >= min(p.X, q.X) && a.X <= max(p.X, q.X))
			&& (a.Y >= min(p.Y, q.Y) && a.Y <= max(p.Y, q.Y));
}
inline bool intersect(const point & p, const point & q, const point & a, const point & b)
{
	dir x = get_dir(q - p, a - p);
	dir y = get_dir(q - p, b - p);
	dir w = get_dir(b - a, p - a);
	dir z = get_dir(b - a, q - a);
	if((x != y) && (w != z))
	{
		return true;
	}
	if (x == ON && y == ON && w == ON && z == ON &&
			(on_seg(p, q, a) || on_seg(p, q, b) || on_seg(a, b, p) || on_seg(a, b, q)))
	{
		return true;
	}
	return false;
}
inline void find_intersections(void)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			memo[i][j] = intersect(s[i], e[i], s[j], e[j]);
		}
	}
}
inline void floyd_warshall(void)
{
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				memo[i][j] |= (memo[i][k] & memo[k][j]);
			}
		}
	}
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		memset(memo, 0, sizeof memo);
		read();
		find_intersections();
		floyd_warshall();
		for (int x, y; scanf("%d%d", &x, &y), x || y; printf("%sCONNECTED\n", memo[--x][--y] ? "" : "NOT "));
		if (TC)
		{
			printf("\n");
		}
	}
	return 0;
}

