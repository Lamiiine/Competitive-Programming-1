#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int TC; scanf("%d", &TC);
	for (double a, b, s; TC--;)
	{
		scanf("%lf%lf%lf", &a, &b, &s);
		if (s == 0.0)
		{
			printf("100.000000\%\n");
			continue;
		}
		const double w = s / b;
		if (w >= a)
		{
			printf("0.000000\%\n");
			continue;
		}
		const double tot = a * b;
		const double in = w * b + s * (log(a) - log(w));
		printf("%.6lf\%\n", (1.0 - in / tot) * 100);
	}
	return 0;
}

