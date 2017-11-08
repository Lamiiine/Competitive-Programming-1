#include<stdio.h>
#include<algorithm>
#include<math.h>
#define MAX 105
using namespace std;
typedef double d;
struct point{
	int x, y;
};
int n;
point p[MAX];
d dist(point a, point b){
	d dx = a.x - b.x;
	d dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}
inline const bool operator < (const point & a, const point & b){
	return b.x < a.x;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
		sort(p, p + n);
		int Max = 0;	// y coordinate of previous peak
		d ans = 0.0;
		for (int i = 0; i < n - 1; i += 2){
			// I am not interested in the last point
			point a = p[i], b = p[i + 1];
			if (Max >= b.y) continue;
			// CORNER CASE!
			if (a.y != b.y) ans += dist(a, b)*(d)(b.y - Max)/(b.y-a.y);
			Max = b.y;
		}
		printf("%.2lf\n", ans);
	}
}