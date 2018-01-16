#include<bits/stdc++.h>
#define MAX 105
#define mid(a, b) (((a) + (b)) / 2LL)
#define X real()
#define Y imag()
#define perp(a) (point(-(a).Y, (a).X))
#define vec(a, b) ((b) - (a))
#define cross(a, b) ((a).X * (b).Y - (a).Y * (b).X)
#define length(a) ((double)hypot((a).X, (a).Y))
using namespace std;
const double eps = 1e-9;
const double inf = 1e9;
typedef long long int ll;
typedef complex<ll> point;
bool intersect(const point & a, const point & b, const point & p, const point & q, point & ret){
	ll d1 = cross(p - a, b - a);
	ll d2 = cross(q - a, b - a);
	if (d1 == d2) return 0;
	ret = (d1 * q - d2 * p) / (d1 - d2);
	return 1;
}
void circle(const point & a, const point & b, point & cen, double & r){
	cen = mid(a, b);
	r = length(vec(a, b))/2;
}
bool circle(const point & a, const point & b, const point & c, point & cen, double & r){
	point m1 = mid(a, b);
	point m2 = mid(b, c);
	point perp1 = perp(vec(a, b));
	point perp2 = perp(vec(b, c));
	bool res = intersect(m1, m1 + perp1, m2, m2 + perp2, cen);
	r = length(vec(cen, a));
	return res;
}
point p[MAX], r[3], cen;
int ps, rs;
double rad;
bool out(const point & cen, const double r, const point & a){
	return (length(vec(cen, a)))> r + eps;
}
void mec(){
	if (rs == 3){
		circle(r[0], r[1], r[2], cen, rad);
		return;
	}
	if (rs == 2 && ps == 0){
		circle(r[0], r[1], cen, rad);
		return;
	}
	if (!ps){
		cen = r[0];
		rad = 0;
		return;
	}
	ps--;
	mec();
	if (out(cen, rad, p[ps])){
		r[rs++] = p[ps];
		mec();
		rs--;
	}
	ps++;
}
double RAD;
inline void read(void){
	for (int i = 0, x, y; i < ps; ++i)
		scanf("%d%d", &x, &y), p[i] = point(x, y);
	scanf("%lf", &RAD);
}
int main(void){
	while(scanf("%d", &ps), ps){
		read();
		mec();
		printf("%s\n",
				rad - eps < RAD
				? "The polygon can be packed in the circle."
						: "There is no way of packing that polygon."
						);
	}
}

