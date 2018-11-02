#include<bits/stdc++.h>
#define MAX 100100
using namespace std;
const double eps = 1e-4;
double arr[MAX];
int n, m;
inline bool can(double w)
{
	w += w;
	int i = 0;
	for (int j = 0; j < n && i < m; ++j)
	{
		const double next = arr[i] + w + eps;
		while(i < m && arr[i] <= next)
		{
			++i;
		}
	}

	return i >= m;
}

int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%lf", arr + i);
		}
		sort(arr, arr + m);

		double lo = 0.0, hi = 1e6 + 1;
		while(hi - lo > eps)
		{
			const double mid = (lo + hi) * 0.5;
			if (can(mid))
			{
				hi = mid;
			}
			else
			{
				lo = mid;
			}
		}

		printf("%.1lf\n", lo);
	}

	return 0;
}

