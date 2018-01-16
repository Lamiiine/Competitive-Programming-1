#include<stdio.h>
#include<algorithm>
#define MAX 105
using namespace std;
double memo[MAX];
int n;
int a[MAX];
double b;	// change delay
int r;
double v, e, f;
double dist[10010];
inline void init(void){
	for (int i = 0; i < n; ++i)
		memo[i] = -1.0;
	memo[n] = 0.0;
	int up = a[n];
	dist[0] = 0.0;
	for (int i = 1; i <= up; ++i){
		dist[i] = dist[i - 1];
		if ((i - 1) >= r)
			dist[i] += 1.0 / ((double)v - e *((i-1) - r));
		else dist[i] += 1.0 / ((double)v - f *(r - (i-1)));
	}
}
inline double dp(int i){
	/*minimum distance starting at check point i knowing that you have checked there! */
	double & ret = memo[i];
	if (ret != -1.0) return ret;
	double ans = dist[a[n] - a[i]];
	for (int j = i + 1; j < n; ++j)
		ans = min(ans, b + dist[a[j] - a[i]] + dp(j));
	return ret = ans;
}
inline void read(void){
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	scanf("%lf%d%lf%lf%lf", &b, &r, &v, &e, &f);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	// freopen("Output.txt", "w", stdout);
	a[0] = 0;
	while (scanf("%d", &n), n){
		read();
		init();
		printf("%.4lf\n", dp(0));
	}
	return 0;
}