#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
typedef long double ld;
int main(){
	// freopen("Input.txt", "r", stdin);
	const ld PI = acos(-1.0);
	int d, l, TC;
	scanf("%d", &TC);
	while (TC--)
		scanf("%d%d", &d, &l), printf("%.3llf\n", (ld)PI*(l / 2.0)*sqrt((ld)(l / 2.0)*(l / 2.0) - (d / 2.0)*(d / 2.0)));
}