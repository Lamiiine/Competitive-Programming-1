// BE AS PRECISE AS POSSIBLE
// YOU HAD THE RIGHT ANSWER, BUT YOU GOT 'WA' MULTIPLE TIMES BECAUSE OF PRECISION ERRORS AND STUFF LIKE THAT
#include<stdio.h>
#include<algorithm>
#include<math.h>
#define MAX 10005
#define eps 1e-9
using namespace std;
// YOU ARE USED TO WRITING 'int'; YOU CONFUSED IT WITH 'double'
typedef long long  ll;
typedef long double ld;
const ld PI = acos(-1);
int n, f;
ld rr[MAX];
inline bool can(ld v){ll ans = 0;for (int i = 0; i < n; ++i) ans += int(rr[i]/v);return ans >= (ll)f;}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while(TC--){
		int x;
		scanf("%d%d", &n, &f);
		++f;
		for (int i = 0; i < n; ++i) scanf("%d", &x), rr[i] = (ld)x*x*PI;	// radius squared
		ld l = 0.0, h = 100000000.0*PI;
		while(h - l > eps){
			ld mid = (l + h)/2.0;
			// printf("%lf %lf %lf\n", l, h, mid);
			if (can(mid)) l = mid;
			else h = mid;
		}
		printf("%.4llf\n", l);
	}
	return 0;
}

