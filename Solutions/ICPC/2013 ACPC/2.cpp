#include <bits/stdc++.h>
#define eps 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define length(v) ((long double) hypot((v).Y, (v).X))
#define length_sqr(v) (dot((v), (v)))
#define dot(a, b) ((conj(a) * (b)).real())
#define cross(a, b) ((conj(a)*(b)).imag())

using namespace std;
typedef complex<long double> point;
point pos[26];
char keyboard[4][7];
vector<int> between[26][26];
inline bool is_between(const long double a, const long double x, const long double y)
{
	return a >= x && a <= y;
}
inline bool inside_square(const point p, const point center)
{
	const long double margin = 0.5 - eps;
	return is_between(p.X, center.X - margin, center.X + margin) &&
			is_between(p.Y, center.Y - margin, center.Y + margin);
}
inline long double manhattan(const point & a, const point & b)
{
	return fabs(a.X - b.X) + fabs(a.Y - b.Y);
}
inline point closest_line(point p, point a, point b)
{
	point ap = vec(a, p), ab = vec(a, b);
	return a + ab * dot(ap, ab) / dot(ab, ab);
}
inline point closest_segment(point p, point a, point b)
{
	point ap = vec(a, p), ab = vec(a, b);
	long double u = dot(ap, ab) / dot(ab, ab);
	if (u < 0.0) return a;
	if (u > 1.0) return b;
	return closest_line(p, a, b);
}
inline void init()
{
	for (int x = 0, y = 0, c = 0; c < 26; ++c, ++y)
	{
		if (y == 7)
			++x, y = 0;
		else if (x == 0 && y == 0)
			y = 1;
		else if (x == 0 && y == 6)
			x = 1, y = 0;
		keyboard[x][y] = c;
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if ((i == 0 && j == 0) || (i == 0 && j == 6)) continue;
			pos[keyboard[i][j]] = point(i, j);
		}
	}
	for (int i = 0; i < 26; ++i)
	{
		for (int j = i + 1; j < 26; ++j)
		{
			vector<pair<long double, int>> path;
			const point & a = pos[i], b = pos[j];
			for (int k = 0; k < 26; ++k)
			{
				if (k != i && k != j)
				{
					const point & c = pos[k];
					// check if k lies on the path from i to j!
					const point closest = closest_segment(c, a, b);
					// if (manhattan(closest, c) < 0.9999)
					if (inside_square(closest, c))
						path.push_back(make_pair(length(vec(a, c)), k));
				}
			}
			sort(path.begin(), path.end());
			for (int idx = 0; idx < path.size(); ++idx)
				between[i][j].push_back(path[idx].second);
			reverse(path.begin(), path.end());
			for (int idx = 0; idx < path.size(); ++idx)
				between[j][i].push_back(path[idx].second);
		}
	}
}
int n;
string p;
inline string expand(const string & p)
{
	string ans;
	for (int i = 0; i < p.size(); ++i)
	{
		ans += string(1, p[i]);
		if (i + 1 < p.size())
		{
			for (int x : between[p[i] - 'A'][p[i + 1] - 'A'])
			{
				ans += string(1, x + 'A');
			}
		}
	}
	return ans;
}
inline bool is_sub_str(const string & a, const string & p)
{
	int i = 0, j = 0;
	while (i < a.size())
	{
		while (j < p.size() && p[j] != a[i]) ++j;
		if (j == p.size()) return false;
		++i; ++j;
	}
	return true;
}
const string NO_SOLUTION = "NO SOLUTION";
inline void test()
{
	string x;
	while (true)
	{
		cin >> x;
		cout << expand(x) << endl;
	}
}
int main()
{
	init();
	// cout << closest_segment(pos['R' - 'A'], pos['Z' - 'A'], pos['E' - 'A']);
	// test();
	int TC; cin >> TC;
	while (TC--)
	{
		int n; string p;
		cin >> n >> p;
		p = expand(p);
		string ans = NO_SOLUTION, x;
		for (int i = 0; i < n; ++i)
		{
			cin >> x;
			if (ans == NO_SOLUTION && is_sub_str(x, p))
				ans = x;
		}
		cout << ans << endl;
	}
	return 0;
}
/*
2
3 ACM
ACPC
AM
ACM
2 ACM
XY
ZW
 */

