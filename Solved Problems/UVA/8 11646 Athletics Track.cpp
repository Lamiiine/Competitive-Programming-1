#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
double r;
char s[3];
inline bool can(const double w)
{
	const double l = w * r;
	const double radius = hypot(l * 0.5, w * 0.5);

	const double alpha = 2.0 * atan2(w * 0.5, l * 0.5);

	return (l + radius * alpha) * 2.0 >= 400.0;
}

int main(void)
{
	double a, b;
	for(int tc = 1; ~scanf("%lf%s%lf", &a, s, &b); ++tc)
	{
		r = a / b;
		double lo = 0.0, hi = 1e9;
		while(hi - lo > eps)
		{
			double mid = (lo + hi) * 0.5;
			if (can(mid))
			{
				hi = mid;
			}
			else
			{
				lo = mid;
			}
		}

		printf("Case %d: %.10lf %.10lf\n", tc, lo * r, lo);
	}

	return 0;
}

