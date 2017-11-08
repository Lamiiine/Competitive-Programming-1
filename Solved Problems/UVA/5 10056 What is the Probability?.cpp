#include<bits/stdc++.h>
#define eps 1e-5
using namespace std;
int main(void)
{
	int n, i; double p;
	int TC;
	scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d%lf%d", &n, &p, &i);
		if (p == 1.0)
		{
			printf("%.4lf\n", i == 1 ? 1.0 : 0.0);
			continue;
		}
		if (p == 0.0)
		{
			printf("%.4lf\n", 0.0);
			continue;
		}
		double q = 1.0 - p;
		double sum = 1.0;
		for (int i = 1;; ++i)
		{
			const double cur = pow(q, i * n);
			sum += cur;
			if (cur < eps)
			{
				break;
			}
		}
		sum *= pow(q, i - 1);
		printf("%.4lf\n", sum * p);
	}
	return 0;
}

