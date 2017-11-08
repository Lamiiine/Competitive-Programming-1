#include<bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979;
const double eps = 1e-9;
double s, r;
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%lf%lf", &s, &r);
		const double s_diag = hypot(s * 0.5, s * 0.5);
		if (r >= s_diag - eps)
		{
			printf("%.2lf\n", s * s);
			continue;
		}

		if (r <= s * 0.5 + eps)
		{
			printf("%.2lf\n", PI * r * r);
			continue;
		}

		const double t = 0.5 * s - sqrt(r * r - (0.25 * s * s));
		const double t_area = t * t * 0.5;
		const double t_diag = hypot(t, t);
		// const double alpha = asin(t * sin(PI * 0.25) / r);
		const double alpha = PI * 0.25 - acos((0.5 * s) / r);

		const double sector_area = r * r * (alpha);

		// const double cent_t_area = 0.5 * t_diag * (s_diag - (t_diag * 0.5));
		const double cent_t_area = 0.5 * t_diag * r * cos(alpha);
		const double segment_area = sector_area - cent_t_area;

		printf("%.2lf\n", s * s - (4.0 * (t_area - segment_area)));
	}
	return 0;
}
/*
3
1 1
8 5
10 4
 */

