#include<bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int n, s;
int main(void)
{
	freopen("equilaterals.in", "r", stdin);
	const double factor = sin(PI / 3.0) / 3.0;
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d%d", &n, &s);
		const int num_sides = n * 3;
		const double alpha = (double) PI / num_sides;
		const double l = (double) s * factor;

		printf("%.4lf\n", l * l * tan(alpha) * num_sides);
	}
	return 0;
}

