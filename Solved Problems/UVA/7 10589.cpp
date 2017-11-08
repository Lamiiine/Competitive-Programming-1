#include<stdio.h>
#define eps 1e-9
using namespace std;
typedef long double d;
struct point{
	d x, y;
};
inline const d dist_sq(const point & a, const point & b){
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
int n, a;
int main(){
	// freopen("Input.txt", "r", stdin);
	while (scanf("%d", &n), n){
		scanf("%d", &a);
		int a_2 = a*a;
		d x, y;
		int counter = 0;
		int X[4] = { 0, 0, a, a };
		int Y[4] = { 0, a, 0, a };
		for (int i = 0; i < n; ++i){
			scanf("%llf%llf", &x, &y);
			bool flag = true;
			for (int j = 0; j < 4 && flag; ++j)
				if ((x - X[j])*(x - X[j]) + (y - Y[j])*(y - Y[j]) > a_2) flag = false;
			counter += flag;
		}
		// HAD TO WRITE THE PRECISION SPECIFIER ".5"
		printf("%.5llf\n", (d)counter*a*a / n);
	}
	return 0;
}