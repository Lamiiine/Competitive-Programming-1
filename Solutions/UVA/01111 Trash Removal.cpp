#include<bits/stdc++.h>
using namespace std;
typedef complex<int> point;
#define EPS 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define polar(r, t) ((r)*exp(point(0, t)))
#define angle(v) (atan2((v).Y, (v).X))
#define lengthSqr(v) (dot(v, v))
#define dot(v, u) (v.X*u.X + v.Y*u.Y)
#define cross(v, u) (v.X*u.Y - v.Y*u.X)
#define rotate(v, t) (polar(v, t))
#define rotate_about(v, a, t) (rotate(vec(a, v), t) + a)
using namespace std;
typedef complex<double> d_point;
inline bool eq(const double x, const double y){
	return fabs(x - y) < EPS;
}
int n;	// number of points!
vector<point>p;
struct cmp{
	point pivot;
	cmp(point a):pivot(a){}
	inline const bool operator ()(const point & a, const point & b){
		int cr = cross(vec(pivot, a), vec(pivot, b));
		if (cr)	// if not alligned, pick the one to the left of the other
			return cr > 0;
		// else, pick the one closer to your pivot
		// The pair comparision gives you closer one to the pivot. Why?
		return make_pair(a.Y, a.X) < make_pair(b.Y, b.X);
	}
};
inline void find_pivot(void){
	point ans = p[0], tmp;
	int ans_index = 0;
	for (int i = 1; i < n; ++i){
		tmp = p[i];
		if (make_pair(tmp.Y, tmp.X) < make_pair(ans.Y, ans.X))
			ans = tmp, ans_index = i;
	}
	swap(p[0], p[ans_index]);
}
inline vector<point> convex_hull(void){
	vector<point>ans;
	p.push_back(p[0]);
	ans.push_back(p[0]);
	ans.push_back(p[1]);
	for (int i = 2; i <= p.size(); ++i)
	{
		const point c = p[i % p.size()];
		while(ans.size() > 1){
			point b = ans.back();
			point a = ans[ans.size() - 2];
			if (cross(vec(a, b), vec(b, c)) > 0)
				break;
			ans.pop_back();
		}
		ans.push_back(c);
	}
	return ans;
}
inline void read(void){
	p.clear();
	for (int i = 0, x, y; i < n; ++i)
		scanf("%d%d", &x, &y), p.push_back(point(x, y));
}
struct line{
	double a, b, c;	// ax + by + c = 0;
	line():a(0), b(0), c(0){}
	line(const point & p, const point & q){
		if (p.X == q.X){
			a = 1.0; b = 0.0; c = -(double)p.X;
		}
		else {
			a = -(double)((double)q.Y - p.Y) / (double)((double)q.X - p.X);
			b = 1.0;
			c = -(double)((double)a * p.X) - p.Y;
		}
	}
	line (const d_point & p, double m){
		a = -m;
		b = 1.0;
		c = - (double)a*p.X - p.Y;
	}
};
d_point intersect(const line & l, const line & m){
	double x =(m.b * l.c - l.b * m.c) / (m.a * l.b - l.a * m.b);
	double y =(fabs(l.b) > EPS) ? -(l.a * x + l.c) : -(m.a * x + m.c);
	return d_point(x, y);
}
d_point closest(const d_point & p, const line & l){
	if (eq(l.b, 0.0))
		return d_point(-l.c, p.Y);
	if (eq(l.a, 0.0))
		return d_point (p.X, -l.c);
	return intersect(l, line(p, 1.0/ l.a));
}
double dist(const d_point & p, const d_point & q){
	return hypot(p.X - q.X, p.Y - q.Y);
}
double dist(const d_point & p, const line & l){
	return dist(p, closest(p, l));
}
inline double solve(const vector<point>&ch){
	double ans = OO;
	for (int i = 1; i < ch.size(); ++i){
		double cur = 0.0;
		point a = ch[i], b = ch[i-1];
		line l(a, b);
		for (int j = 0; j < ch.size(); ++j)
			cur = max(cur, dist(d_point(ch[j].X, ch[j].Y), l));
		ans = min(ans, cur);
	}
	return ans;
}
int main(void){
	for (int tc = 1; scanf("%d", &n), n; ++tc){
		read();
		find_pivot();
		sort(p.begin(), p.end(), cmp(p[0]));
		vector<point>ch = convex_hull();	// last point is repeated!
		printf("Case %d: %.2lf\n", tc, solve(ch));
	}
}

