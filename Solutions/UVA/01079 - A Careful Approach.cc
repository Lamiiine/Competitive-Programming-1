#include <bits/stdc++.h>
#define MAX 8
#define eps 1e-15
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long double ld;
inline int dbl_cmp(const double a, const double b)
{
	if (fabs(a - b) < eps) return 0;
	return a < b ? -1 : 1;
}
int n;
iii plane[MAX];
inline bool can_aux(const ld minutes)
{
	ld last = plane[0].second.first;
	for (int i = 1; i < n; ++i)
	{
		const ii & cur_plane = plane[i].second;
		if (dbl_cmp(last + minutes, cur_plane.second) <= 0)
			last = max(last + minutes, (ld) cur_plane.first);
		else return false;
	}
	return true;
}

inline bool can(const ld minutes)
{
	do {
		if (can_aux(minutes)) return true;
	} while(next_permutation(plane, plane + n));
	return false;
}
int main()
{
	for (int tc = 1; scanf("%d", &n), n; ++tc)
	{
		for (int i = 0, x, y; i < n; ++i)
			scanf("%d%d", &x, &y),
			plane[i] = iii(i, ii(x, y));
		ld a = 0, b = 1440;
		while (b - a > eps)
		{
			const ld mid = (a + b) * 0.5;
			if (can(mid))
				a = mid;
			else b = mid;
		}
		const int ans = round((a + b) * 0.5 * 60.0 + eps);	// number of seconds!
		printf("Case %d: %d:%02d\n", tc, ans/ 60, ans % 60);
	}
	return 0;
}

