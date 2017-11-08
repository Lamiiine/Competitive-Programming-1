#include<bits/stdc++.h>
using namespace std;
typedef double d;
typedef pair<d, d> dd;
const d eps = 1e-9;
const d inf = 1e9;
const d PI = acos(-1);
inline d to_rad(const d deg){
	return deg * PI / 180.0;
}
inline bool eq(const d a, const d b){
	return fabs(a - b) < eps;
}
struct point {
	d x, y;
	inline point(d a, d b){
		x = a; y = b;
	}
	inline point(){x = y = 0.0;}
	// vector constructor
	inline point(const point & start, const point & end){
		x = end.x - start.x;
		y = end.y - start.y;
	}
};
inline point operator + (const point & a, const point & b){
	return point(a.x + b.x, a.y + b.y);
}
inline double cross(const point & a, const point & b){
	return a.x*b.y - a.y*b.x;
}
struct cmp{
	point pivot;
	cmp(const point & a):pivot(a){}
	inline bool operator ()(const point & a, const point & b) const{
		d cr = cross(point(pivot, a), point(pivot, b));
		if (eq(cr, 0.0))	// both points aligned
			return (!eq(a.x, b.x)) ? a.x < b.x : a.y < b.y;
		return cr > 0.0;
	}
};
int n;	// number of polygons
point p[2500];
int pn;	// point number
inline point rotate(const point & a, const d rad){
	return point(a.x*cos(rad) - a.y*sin(rad), a.x*sin(rad) + a.y*cos(rad));
}
inline point rotate(const point & a, const point & about, const d angle){
	return rotate(point(about, a), angle) + about;
}
inline d read(void){
	d total_area = 0.0;
	pn = 0;
	scanf("%d", &n);
	d x, y, w, h, f;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf%lf%lf%lf%lf", &x, &y, &w, &h, &f);
		total_area += (w * h);
		w *= 0.5; h *= 0.5;
		point p1(x + w, y + h);
		point p2(x + w, y - h);
		point p3(x - w, y + h);
		point p4(x - w, y - h);
		const point center(x, y);
		f = to_rad(-f);
		p[pn++] = rotate(p1, center, f);
		p[pn++] = rotate(p2, center, f);
		p[pn++] = rotate(p3, center, f);
		p[pn++] = rotate(p4, center, f);
	}
	return total_area;
}
inline void select_pivot(void){
	point ans = p[0];
	int ans_index = 0;
	for (int i = 1; i < pn; ++i)
	{
		const point& tmp = p[i];	// point # i
		if (make_pair(tmp.y, tmp.x) < make_pair(ans.y, ans.x))
			ans = tmp, ans_index = i;
	}
	swap(p[0], p[ans_index]);
}
inline vector<point> convex_hull(void){
	vector<point> ans;
	select_pivot();
	sort(p + 1, p + pn, cmp(p[0]));
	ans.push_back(p[0]);
	ans.push_back(p[1]);
	for (int i = 2; i <= pn; ++i){
		const point c = p[i % pn];
		while(ans.size() > 1){
			point a = ans[ans.size() - 2];
			point b = ans.back();
			if (cross(point(b, a), point(b, c)) < -eps)
				break;
			ans.pop_back();
		}
		ans.push_back(c);
	}
	return ans;
}
inline d polygon_area(const vector<point> & v){
	d ans = 0.0;
	const int sz = v.size();
	for (int i = 0; i < sz; ++i)
		ans += cross(v[i], v[(i + 1) % sz]);
	return fabs(ans) * 0.5;
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		d a = read();
		d b = polygon_area(convex_hull());
		printf("%.1lf %%\n", a / b * 100.0);
	}
	return 0;
}

