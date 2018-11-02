#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define eps 1e-9
using namespace std;
typedef double d;
d a[6];
inline d func(const d x){
	// This function is always decreasing
	return a[0]*exp(-x) + a[1]*sin(x)+a[2]*cos(x)+a[3]*tan(x)+a[4]*x*x+a[5];
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int b[6];
	while(scanf("%d%d%d%d%d%d", b, b + 1, b + 2, b + 3, b + 4, b + 5) != EOF){
		for (int i = 0; i < 6; ++i) a[i] = b[i];
		d lo = 0.0, hi = 1.0;
		while(fabs(lo - hi) > eps){
			d mid = (lo + hi)/2.0;
			d ans = func(mid);
			// printf("ans = %lf\n", ans);
			if (ans > 0.0) lo = mid;
			else hi = mid;
		}
		// printf("lo = %lf, hi = %lf", lo, hi);
		if ((fabs(lo - 1.0) < eps || fabs(hi) < eps) && fabs(func(lo)) > 1e-5)
		printf("No solution\n");
		else printf("%.4lf\n", lo);
	}
	return 0;
}

