#include<bits/stdc++.h>
using namespace std;
double d, l, ha, hb, errdist;
double alph, bet, gam, delt;
const double PI = acos(-1);
const double eps = 1e-9;
inline double rad(const double deg){
	return deg * PI / 180.0;
}
inline bool valid_1(const double a){
	return (a > 0.0 && a < 90.0);
}
inline bool valid_2(const double a){
	return (a > 90.0 && a < 180.0);
}
int main(void){
	int TC; scanf("%d", &TC);
	scanf("%lf%lf%lf%lf%lf", &d, &l, &ha, &hb, &errdist);
	for (int tc = 1; tc <= TC; ++tc){
		printf("%d ", tc);
		scanf("%lf%lf%lf%lf", &alph, &bet, &gam, &delt);
		if (!(valid_1(alph)&&valid_1(bet) && valid_1(gam) && valid_2(delt))){
			printf("DISQUALIFIED\n");
			continue;
		}
		delt = 180.0 - delt;
		double theta = 180.0 - (gam + delt);
		alph = rad(alph);
		bet = rad(bet);
		gam = rad(gam);
		delt = rad(delt);
		theta = rad(theta);
		double ac = (d/sin(theta))*sin(delt);
		double bc = (d/sin(theta))*sin(gam);
		double h1 = ha + tan(alph)*ac;
		double h2 = hb + tan(bet)*bc;
		if (fabs(h1 - h2) > errdist + eps){
			printf("ERROR\n");
			continue;
		}
		double ans = (h1 + h2) * 0.5;
		ans = round(ans + eps);
		printf("%d\n", int(ans + 0.1));
	}
	return 0;
}
/*
4
100.0 300.0 5.25 2.92 5.00
40.1 36.2 35.3 151.6
64.9 71.1 15.7 160.1
44.9 41.2 33.1 152.5
44.9 41.2 33.1 52.5
*/

