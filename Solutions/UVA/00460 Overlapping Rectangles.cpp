#include<bits/stdc++.h>
#define X real()
#define Y imag()
#define cross(a, b) ((a).X*(b).Y - (a).Y*(b).X)
#define ccw(a, b) (cross(a, b) > 0)
#define vec(a, b) ((b) - (a))
using namespace std;
typedef long long int ll;
typedef complex<ll> point;
point intersect(const point & a, const point & b, const point & p, const point & q){
	ll d1 = cross(vec(a, p), vec(a, b));
	ll d2 = cross(vec(a, q), vec(a, b));
	return point(d1 * q - d2 * p) / (d1 - d2);
}
vector<point> polygon_cut(const point & a, const point & b, const vector<point> & p){
	vector<point> ans;
	const int sz = p.size();
	for (int i = 0; i < sz; ++i){
		int j = (i + 1) % sz;
		bool in1 = ccw(vec(a, b), vec(a, p[i]));
		bool in2 = ccw(vec(a, b), vec(a, p[j]));
		if (in1)
			ans.push_back(p[i]);
		if (in1 ^ in2)
			ans.push_back(intersect(a, b, p[i], p[j]));
	}
	return ans;
}
vector<point> construct_polygon(){
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	vector<point> p;
	p.reserve(4);
	p.push_back(point(x1, y1));
	p.push_back(point(x2, y1));
	p.push_back(point(x2, y2));
	p.push_back(point(x1, y2));
	return p;
}
inline bool cmp_x(const point & a, const point & b){
    return make_pair(a.X, a.Y) < make_pair(b.X, b.Y);
}
inline bool cmp_y(const point & a, const point & b){
    return make_pair(a.Y, a.X) < make_pair(b.Y, b.X);
}
inline point min_x(const vector<point> & p){
	point ans = p[0];
	for (int i = 1; i < p.size(); ++i)
		ans = min(ans, p[i], cmp_x);
	return ans;
}
inline point max_y(const vector<point> & p){
	point ans = p[0];
	for (int i = 1; i < p.size(); ++i)
		ans = max(ans, p[i], cmp_y);
	return ans;
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		vector<point> p = construct_polygon();
		vector<point> q = construct_polygon();
		for (int i = 0; i < 4 && !p.empty(); ++i){
			int j = (i + 1) & 3;	// i & 3 = i % 4
			p = polygon_cut(q[i], q[j], p);
		}
		if (p.empty()) printf("No Overlap\n");
		else {
			point a = min_x(p), b = max_y(p);
			printf("%lld %lld %lld %lld\n", a.X, a.Y, b.X, b.Y);
		}
		if (TC) printf("\n");
	}
	return 0;
}

