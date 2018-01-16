#include<bits/stdc++.h>
using namespace std;
typedef complex<long double> point;
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
const long double eps = 1e-9;
const long double inf = 1e9;
const long double cross(const point & a, const point & b){
	return a.X * b.Y - a.Y * b.X;
}
point intersect(const point & a, const point & b, const point & p, const point & q){
	long double d1 = cross(p - a, b - a);
	long double d2 = cross(q - a, b - a);
	return (d1 * q - d2 * p) / (d1 - d2);
}
long double polygon_area(const vector<point> & v){
	long double ans = 0.0;
	const int sz = v.size();
	for (int i = 0; i < sz; ++i)
		ans += cross(v[i], v[(i + 1) % sz]);
	return fabs(ans) * 0.5;
}
void polygon_cut(const vector<point> & p, const point & a, const point & b, vector<point> & ans){
	ans.clear();
	const int sz = p.size();
	for (int i = 0; i < sz; ++i){
		int j = (i + 1) % sz;
		bool in1 = cross(vec(a,b),vec(a,p[i])) > eps;
		bool in2 = cross(vec(a,b),vec(a,p[j])) > eps;
		if (in1)
			ans.push_back(p[i]);
		if (in1 ^ in2)
			ans.push_back(intersect(a, b, p[i], p[j]));
	}
}
int n;
point fountain;
inline vector<point> read(void){
	int w, h, x, y;
	scanf("%d%d%d%d", &w, &h, &x, &y);
	fountain = point(x, y);
	vector<point>ans;
	ans.push_back(point(0, 0));
	ans.push_back(point(w, 0));
	ans.push_back(point(w, h));
	ans.push_back(point(0, h));
	return ans;
}
bool counter_clock_wise(const point & a, const point & b){
	// b is counterclockwise from a
	return cross(a, b) > eps;
}
int main(void){
	for (int tc = 1; ~scanf("%d", &n); ++tc){
		vector<point> p = read();
		vector<point> q;
		for (int i = 0, x, y, w, z; i < n; ++i){
			scanf("%d%d%d%d", &x, &y, &w, &z);
			point a(x, y), b(w, z);
			if (counter_clock_wise(vec(a, b), vec(a, fountain)))
				polygon_cut(p, a, b, q);
			else
				polygon_cut(p, b, a, q);
			p = q;
		}
		printf("Case #%d: %.3llf\n", tc, polygon_area(p));
	}
	return 0;
}

