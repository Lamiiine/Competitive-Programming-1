#include<bits/stdc++.h>
#define MAX 128
#define eps 1e-9
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define cross(a, b) ((a).X * (b).Y - (a).Y * (b).X)
using namespace std;
typedef long long int ll;
typedef complex<ll> point;

point arr[MAX];
vector<point> polygon;
int n;
inline void read(void)
{
	for (int i = 0, a , b; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		arr[i] = point(a, b);
	}
	// make it counterclockwise
	for (int i = 0, j = n - 1; i < j; ++i, --j)
		swap(arr[i], arr[j]);
}
inline point intersect(const point & a, const point & b, const point & p, const point & q)
{
	// ab is either horizontal or vertical
	if (a.X == b.X)
		return point(a.X, p.Y);
	else return point(p.X, a.Y);
}
vector<point> polygon_cut(const vector<point> & p, const point & a, const point & b)
{
	vector<point> ans;
	const int sz = p.size();
	for (int i = 0; i < sz; ++i)
	{
		const int j = (i + 1) % sz;
		bool in_1 = cross(vec(a, b), vec(a, p[i])) >= 0;
		bool in_2 = cross(vec(a, b), vec(a, p[j])) >= 0;
		if (in_1)
			ans.push_back(p[i]);
		if (in_1 ^ in_2)
			ans.push_back(intersect(a, b, p[i], p[j]));
	}
	return ans;
}
inline bool solve()
{
	polygon.clear();
	for (int i = 0; i < n; ++i)
		polygon.push_back(arr[i]);
	arr[n] = arr[0];
	for (int i = 0; i < n && !polygon.empty(); ++i)
		polygon = polygon_cut(polygon, arr[i], arr[i + 1]);

	return !polygon.empty();
}
int main(void)
{
	for(int tc = 1; scanf("%d", &n), n; ++tc)
	{
		read();
		printf("Floor #%d\nSurveillance is %spossible.\n\n", tc, solve() ? "" : "im");
	}
	return 0;
}

