#include<stdio.h>
#include<float.h>
#include<algorithm>
#include<math.h>
#define MAX 105
#define eps 1e-9
using namespace std;
typedef double d;
const inline bool eq(const double a, const double b){
	return fabs(a - b) < eps;
}
struct point{
	d x, y;
};
inline bool operator ==(const point & p, const point & q){
	return eq(q.x, p.x) && eq(q.y, p.y);
}
d dist_sq(point a, point b){
	d dx = a.x - b.x;
	d dy = a.y - b.y;
	return dx*dx + dy*dy;
}
struct vec{
	d x, y;
	vec(point a, point b) :x(b.x - a.x), y(b.y - a.y){}
	vec(d X, d Y) :x(X), y(Y){}
};
inline const d dot(const vec & v, const vec & u){
	return v.x*u.x + v.y*u.y;
}
inline const d norm_sq(const vec & v){
	return dot(v, v);
}
point p;
inline point translate(const point & a, const vec & v){
	return point{ a.x + v.x, a.y + v.y };
}
vec scale(vec v, d s){
	return vec(v.x*s, v.y*s);
}
point closest(point a, point b){
	vec ap(a, p), ab(a, b);
	return translate(a, scale(ab, dot(ap, ab) / norm_sq(ab)));
}
point closestSeg(point a, point b){
	vec ap(a, p), ab(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) return a;
	if (u > 1.0) return b;
	return closest(a, b);
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int n;
	while (scanf("%lf%lf", &p.x, &p.y) != EOF){
		point prev, cur;
		scanf("%d%lf%lf", &n, &prev.x, &prev.y);
		// consider the first point
		point ans = prev;
		d Min = dist_sq(prev, p);
		while (n--){
			scanf("%lf%lf", &cur.x, &cur.y);
			point c = closestSeg(prev, cur);
			d temp = dist_sq(c, p);
			if (temp < Min){
				Min = temp;
				ans = c;
			}
			prev = cur;
		}
		printf("%.4lf\n%.4lf\n", ans.x, ans.y);
	}
}