#include<bits/stdc++.h>
#define MAX (1 << 6)
#define X real()
#define Y imag()
#define cross(a, b) ((a).X * (b).Y - (a).Y * (b).X)
#define vec(a, b) ((b) - (a))
using namespace std;
typedef long long int ll;
typedef complex<ll> point;

int n;
vector<point> polygon;
inline void init()
{
	polygon.clear();
}
inline void reverse(vector<point> & polygon)
{
	for (int i = 0, j = polygon.size() - 1; i < j; ++i, --j)
		swap(polygon[i], polygon[j]);
}
inline void read()
{
	for (int a, b, i = 0; i < n; ++i)
		scanf("%d%d", &a, &b), polygon.push_back(point(a, b));
}
inline bool is_clock_wise(const vector<point> & v)
{
	ll area = 0LL;
	const int sz = v.size();
	for (int i = 0; i < sz; ++i)
		area += cross(v[i], v[(i + 1) % sz]);
	return area < 0LL;
}
inline bool is_concave()
{
	// assumed to be sorted counterclockwise
	polygon.push_back(polygon[0]);
	polygon.push_back(polygon[1]);
	for (int i = 0; i < n; ++i)
		if (cross(vec(polygon[i], polygon[i + 1]), vec(polygon[i + 1], polygon[i + 2])) < 0LL)
			return true;
	return false;
}
int main(void)
{
	while(scanf("%d", &n), n)
	{
		init();
		read();
		if (is_clock_wise(polygon))
			reverse(polygon);
		printf("%s\n", is_concave() ? "Yes" : "No");
	}
	return 0;
}
/*
4
0 0
3 0
3 3
0 3
40 0
3 0
1 1
0 3
0
 */

