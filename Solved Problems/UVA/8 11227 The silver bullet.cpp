#include<bits/stdc++.h>
#define MAX 128
#define X real()
#define Y imag()
#define eps 1e-9
#define eq(a, b) (fabs((a) - (b)) < eps)
#define cross(a, b) ((a).X * (b).Y - (a).Y * (b).X)
#define vec(a, b) ((b) - (a))
#define collinear(a, b, c) (eq(cross(vec((a), (b)), vec((a), (c))), 0))
using namespace std;
typedef complex<double> point;
vector<point> v;
int n;

struct cmp
{
	inline bool operator()(const point & a, const point & b)
	{
		if (!eq(a.X, b.X)) return a.X < b.X;
		return a.Y < b.Y;
	}
};


inline void read()
{
	set<point, cmp> s;
	scanf("%d", &n);
	double x, y;
	for (int i = 0; i < n; ++i)
		scanf("%lf%lf", &x, &y), s.insert(point(x, y));
	v.clear();
	for (set<point>::iterator iter = s.begin(); iter != s.end(); ++iter)
		v.push_back(*iter);
}
inline int solve()
{
	int ans = 1;
	for (int i = 0; i < v.size(); ++i)
		for (int j = i + 1; j < v.size(); ++j)
			for (int cur = 0, k = 0; k < v.size(); ++k)
				ans = max(ans, cur += collinear(v[i], v[j], v[k]));
	return ans;
}
int main()
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		read();
		if (v.size() == 1)
			printf("Data set #%d contains a single gnu.\n", tc);
		else printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n", tc, v.size(), solve());
	}
	return 0;
}

