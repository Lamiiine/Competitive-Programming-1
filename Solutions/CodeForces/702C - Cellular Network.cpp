#include<stdio.h>
#include<algorithm>
#define MAX 100100
using namespace std;
int n, m;
int city[MAX], tower[MAX];
inline void read(void)
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", city + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", tower + i);
}
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	read();
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		const int j = lower_bound(tower, tower + m, city[i]) - tower;
		int cur_dist = INT_MAX;
		if (j < m)
			cur_dist = min(cur_dist, tower[j] - city[i]);
		if (j - 1 >= 0)
			cur_dist = min(cur_dist, city[i] - tower[j - 1]);
		ans = max(ans, cur_dist);
	}

	printf("%d\n", ans);
	return 0;
}