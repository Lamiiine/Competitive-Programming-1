#include<bits/stdc++.h>
#define MAX 10010
#define avg(a, b) ((a + b) >> 1)
using namespace std;
const double eps = 1e-9;
const double inf = 1e9;
struct point{
	double x, y;
	point(const double a, const double b) : x(a), y(b){}
	point(){x = y = 0.0;}
};
inline bool x_cmp(const point & a, const point & b){
	return a.x < b.x;
}
inline bool y_cmp(const point & a, const point & b){
	return a.y < b.y;
}
point p[MAX];
int n;
inline void read(void){
	for (int i = 0; i < n; ++i)
		scanf("%lf%lf", &p[i].x, &p[i].y);
}
inline double dist(const point & a, const point & b){
	return hypot(a.x - b.x, a.y - b.y);
}
point tmp[MAX];
inline double closest_pair(int l, int r){
	if (r - l <= 2){
		double ans = inf;
		for (int i = l; i < r; ++i)
			for (int j = i + 1; j <= r; ++j)
				ans = min(ans, dist(p[i], p[j]));
		return ans;
	}
	const int m = avg(l, r);
	double ans = min(closest_pair(l, m), closest_pair(m + 1, r));
	point a((int)p[m].x - ans - 1.0, 0);
	point b((int)p[m].x + ans + 1.0, 0);
	point * low = lower_bound(p, p + n, a, x_cmp);
	point * up = upper_bound(p, p + n, b, x_cmp);
	int num = up - low;
	memcpy(tmp, low, num*sizeof (point));
	sort(tmp, tmp + num, y_cmp);
	for (int i = 0; i < num; ++i)
	{
		int k = i + 1;
		while(k < num && fabs(tmp[i].y - tmp[k].y) < ans)
			ans = min(ans, dist(tmp[i], tmp[k++]));
	}
	return ans;
}
int main(void){
	while(scanf("%d", &n), n){
		read();
		sort(p, p + n, x_cmp);
		double ans = closest_pair(0, n-1);
		if (10000.0 - ans > eps) printf("%1.4lf\n", ans);
		else printf("INFINITY\n");
	}
	return 0;
}

