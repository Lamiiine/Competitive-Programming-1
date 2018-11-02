#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef complex<double> point;
#define eps 1e-9
#define OO 1e9
#define X real()
#define Y imag()
#define vec(a, b) ((b) - (a))
#define polar(r, t) ((r) * exp(point(0, (t))))
#define angle(v) (atan2((v).Y, (v).X))
#define length(v) ((double) hypot((v).Y, (v).X))
// #define cross(a, b) ((conj(a) *(b)).Y)
// #define dot(a, b) ((conj(a) *(b)).X)
#define cross(a, b) ((a).X * (b).Y - (a).Y * (b).X)
#define dot(a, b) ((a).X * (b).X + (a).Y *(b).Y)
#define length_sqr(v) (dot((v), (v)))
int n;
vector<point> polygon;
inline int dbl_cmp(const double & a, const double & b)
{
	if (fabs(a - b) < eps) return 0;	// a == b ? 0
	return a > b ? 1 : -1; // a > b ? 1 : -1
}
inline bool eq(const double & a, const double & b)
{
	return fabs(a - b) < eps;
}
inline bool same(const point & a, const point & b)
{
	return eq(a.X, b.X) && eq(a.Y, b.Y);
}
inline void read()
{
	scanf("%d", &n);
	ll x, y;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld%lld", &x, &y);
		polygon.push_back(point(x, y));
	}
	polygon.push_back(polygon[0]);
}
inline bool opposite_sign(const double a, const double b)
{
	return (a > eps && b < -eps) || (a < -eps && b > eps);
}
inline bool segment_intersect(const point & a, const point & b, const point & p, const point & q)
{
	return opposite_sign(cross(vec(a, b), vec(a, p)), cross(vec(a, b), vec(a, q)))
			&& opposite_sign(cross(vec(p, q), vec(p, a)), cross(vec(p, q), vec(p, b)));
}
inline bool point_on_line(const point & a, const point & b, const point & p)
{
	return fabs(cross(vec(a, b), vec(a, p))) < eps;
}
inline bool point_on_segment(const point & a, const point & b, const point & p)
{
	return dot(vec(a, b) , vec(a, p)) > -eps && point_on_line(a, b, p) && dot(vec(b, a), vec(b, p)) > -eps;
}
inline bool point_on_ray(const point & a, const point & b, const point & p)
{
	return dot(vec(a, b), vec(a, p)) > -eps && point_on_line(a, b, p);
}
inline point get_intersect(const point & a, const point & b, const point & p, const point & q)
{
	double d1 = cross(p - a, b - a);
	double d2 = cross(q - a, b - a);
	return (d1 * q - d2 * p) / (d1 - d2);
}

inline double area(const int s, const int e)
{
	double ans = 0.0;
	for(int i = 0; i < s; ++i)
	{
		ans += cross(polygon[i], polygon[i + 1]);
	}
	ans += cross(polygon[s], polygon[e]);
	for (int i = e; i < n; ++i)
	{
		ans += cross(polygon[i], polygon[i + 1]);
	}
	return fabs(ans) * 0.5;
}
inline double area_2(const int s, const int e)
{
	double ans = 0.0;
	for (int i = s; i < e; ++i)
	{
		ans += cross(polygon[i], polygon[i + 1]);
	}
	ans += cross(polygon[e], polygon[s]);
	return fabs(ans) * 0.5;
}
inline bool point_in_polygon(const point & pnt)
{
	point p2 = pnt + point(1, 0);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (point_on_segment(polygon[i], polygon[i + 1], pnt)) continue;
		point r = get_intersect(pnt, p2, polygon[i], polygon[i + 1]);
		if (!point_on_ray(pnt, p2, r))
			continue;
		if (same(r, polygon[i]) || same(r, polygon[i + 1]))
			if (fabs(r.Y - min(polygon[i].Y, polygon[i + 1].Y)) < eps) continue;
		if (!point_on_segment(polygon[i], polygon[i + 1], r)) continue;
		cnt++;
	}

	return cnt & 1;
}

inline bool valid(const point & a, const point & b, const int ind_a, const int ind_b)
{
	// if (!point_in_polygon((a + b) * 0.5)) { return false; }

	for (int i = 0; i < n; ++i)
	{
		if (segment_intersect(a, b, polygon[i], polygon[i + 1])) return false;
		//if (i != ind_a && i != ind_b && point_on_segment(a, b, polygon[i])
				//&& ( opposite_sign(cross(vec(a, b), vec(a, polygon[i + 1])), cross(vec(a, b), vec(a, polygon[(i - 1 + n) % n])))
						// || opposite_sign(cross(vec(a, b), vec(a, polygon[(i + 2) % n])), cross(vec(a, b), vec(a, polygon[(i - 2 + n) % n])))
						// || opposite_sign(cross(vec(a, b), vec(a, polygon[(i + 3) % n])), cross(vec(a, b), vec(a, polygon[(i - 3 + n) % n])))
						//)
				//) return false;
	}

	return true;
}
int main()
{
	read();
	const double a = area(0, 1);
	double ans = 0.0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, length(vec(polygon[i], polygon[i + 1])));

		for (int j = i + 2; j < n; ++j)
		{
			const double b = area(i, j);
			const double c = area_2(i, j);
			if (valid(polygon[i], polygon[j], i, j)
					// && dbl_cmp(b, a) <= 0 && dbl_cmp(c, a) <= 0 && dbl_cmp(b + c, a) == 0
					)
			{
				ans = max(ans, length(vec(polygon[i], polygon[j])));
			}
		}
	}

	printf("%.8lf", ans);
	return 0;
}
/*
7
0 20
40 0
40 20
70 50
50 70
30 50
0 50

3
0 2017
-2017 -2017
2017 0
 */
