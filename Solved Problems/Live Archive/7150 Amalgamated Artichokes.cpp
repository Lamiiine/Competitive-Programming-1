#include<bits/stdc++.h>
#define eps 1
using namespace std;
double p, a, b, c, d;
int n;
inline double price(const double k)
{
	return p * (sin(a * k + b) + cos(c * k + d) + 2.0);
}
int main()
{
	while(~scanf("%lf%lf%lf%lf%lf%d", &p, &a, &b, &c, &d, &n))
	{
		double ans = 0.0;
		double min_so_far = 1e9;
		for (int i = n; i >= 1; --i)
		{
			const double cur_value = price(i);
			ans = max(ans, cur_value - min_so_far);
			min_so_far = min(min_so_far, cur_value);
		}

		printf("%.8lf\n", ans);
	}
	return 0;
}
/*
42 1 23 4 8 10
100 7 615 998 801 3
100 432 406 867 60 1000
 */

