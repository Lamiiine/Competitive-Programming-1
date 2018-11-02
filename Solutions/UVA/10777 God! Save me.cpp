#include <bits/stdc++.h>
#define MAX 102
using namespace std;
typedef long double ld;
ld t[MAX],  p[MAX];
int n;
inline ld get_sum(void)
{
	ld ans = 0.0;
	for (int i = 0; i < n; ++i)
	{
		ans += fabs(t[i]) * p[i];
	}
	return ans;
}
inline ld get_sum_neg_probabilities(void)
{
	ld ans = 0.0;
	for (int i = 0; i < n; ++i)
	{
		if (t[i] < 0.0)
		{
			ans += p[i];
		}
	}
	
	return ans;
}
int main() {
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%llf%llf", t + i, p + i);
		}
		bool flag = false;	// unsaved
		for (int i = 0; i < n; ++i)
		{
			if (t[i] > 0)
			{
				flag = true;
				break;
			}
		}
		if (flag)
		printf("Case %d: %.2llf\n", tc, get_sum() / (1.0 - get_sum_neg_probabilities()));
		else printf("Case %d: God! Save me\n", tc);
	}
	return 0;
}