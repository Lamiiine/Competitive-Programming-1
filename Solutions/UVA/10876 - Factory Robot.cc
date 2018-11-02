#include <bits/stdc++.h>
#define MAX 210
#define eps 1e-9
#define NORTH 208
#define SOUTH 207
#define EAST 206
#define WEST 205
using namespace std;
typedef long double ld;
const vector<int> directions = {EAST, WEST, NORTH, SOUTH};
int n;
struct pillar {
	int x, y, r;
} pillars[MAX];
int p[MAX];


inline int dbl_cmp(const ld a, const ld b)
{
	if (fabs(a - b) < eps) return 0;
	return a < b ? -1 : 1;
}
inline ld dist_in_between(const pillar & a, const pillar & b)
{
	return hypot(a.x - b.x, a.y - b.y) - a.r - b.r;
}
inline void read()
{
	scanf("%d", &n);
	for (int i = 0, x, y , r; i < n; ++i)
		scanf("%d%d%d", &x, &y, &r), pillars[i] = pillar{x, y, r};
}
inline int parent(const int i)
{
	return (p[i] == i) ? i : (p[i] = parent(p[i]));
}
inline bool same(const int i, const int j)
{
	return parent(i) == parent(j);
}
inline void unite(const int i, const int j)
{
	p[parent(j)] = parent(i);
}
inline void init_p()
{
	for (int i = 0; i < MAX; ++i) p[i] = i;
}
inline bool within_grid(const ld x)
{
	return dbl_cmp(x, 0) >= 0 && dbl_cmp(x, 1000) <= 0;
}
inline bool can(const ld robot_radius)
{
	const ld robot_diameter = 2.0 * robot_radius;
	init_p();
	for (int i = 0; i < n; ++i)
	{
		const pillar & cur_pillar = pillars[i];
		for (int j = i + 1; j < n; ++ j)
			if (dbl_cmp(dist_in_between(cur_pillar, pillars[j]), robot_diameter) < 0)
				unite(i, j);
		const vector<ld> potential_violations = {
				cur_pillar.x + cur_pillar.r + robot_diameter,
				cur_pillar.x - cur_pillar.r - robot_diameter,
				cur_pillar.y + cur_pillar.r + robot_diameter,
				cur_pillar.y - cur_pillar.r - robot_diameter
		};
		for (int j = 0; j < 4; ++j)
			if (!within_grid(potential_violations[j]))
				unite(i, directions[j]);
	}
	for (int i = 0; i < 4; ++i)
		for (int j = i + 1; j < 4; ++j)
			if (same(directions[i], directions[j]))
				return false;
	return true;
}
inline ld solve()
{
	ld a = 0.0, b = 500.0;
	while (b - a > eps)
	{
		const ld mid = (a + b) * 0.5;
		if (can(mid))
			a = mid;
		else b = mid;
	}
	return (a + b) * 0.5;
}
int main()
{
	int TC; scanf("%d", &TC);
	while (TC--)
	{
		read();
		printf("%.3llf\n", solve());
	}
	return 0;
}

