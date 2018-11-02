#include<stdio.h>
#include<limits.h>
#include<algorithm>
#define N 100100
#define M 11
using namespace std;
char name[N][28];
int h[N];
int l[N];
int n, m;	// cities, days
int t1[M];
int t2[M];
inline void read(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", name[i]);
		int & hh = h[i];
		int & ll = l[i];
		hh = INT_MIN;
		ll = INT_MAX;
		// read midday temperature
		for (int j = 0, x; j < m; ++j)
		{
			scanf("%d", &x);
			hh = max(hh, x);
		}
		// read night temperature
		for (int j = 0, x; j < m; ++j)
		{
			scanf("%d", &x);
			ll = min(ll, x);
		}
	}
}
inline int pick()
{
	int ans_index = 0;
	int ans_diff = abs(h[0] - l[0]);
	int ans_high = h[0];
	for (int i = 0; i < n; ++i)
	{
		const int cur_diff = abs(h[i] - l[i]);
		const int cur_high = h[i];
		if (cur_diff > ans_diff)
		{
			ans_diff = cur_diff;
			ans_high = cur_high;
			ans_index = i;
		}
		else
		if (cur_diff == ans_diff && cur_high > ans_high)
		{
			ans_high = cur_high;
			ans_index = i;
		}
	}

	return ans_index;
}
int main(void)
{
	// freopen("Input.txt", "r", stdin);
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		printf("%s\n", name[pick()]);
	}
}