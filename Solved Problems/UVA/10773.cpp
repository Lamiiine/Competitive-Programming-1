#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define eps 1e-9
using namespace std;
int main(){
	// freopen("Input.txt", "r", stdin);
	long double d, v, u;
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		scanf("%llf%llf%llf", &d, &v, &u);
		printf("Case %d: ", tc);
		// CORNER CASE: INPUT IS 0?
		if ((v > u) || v < eps || u < eps || u == v) printf("can't determine\n");
		else {
			// LOOK AT THE EQUATION AND SEE WHEN IT FAILS. E.G. U = V
			long double x = d/sqrt(u*u - v*v);
			long double y = d/u;
			printf("%.3llf\n", (x > y)? x-y:y-x);
		}
	}
	return 0;
}

