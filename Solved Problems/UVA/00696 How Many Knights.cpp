#include<bits/stdc++.h>
using namespace std;
int m, n;
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	while(scanf("%d%d", &m, &n), m || n)
	{
		const int area = n * m;
		int ans = (area >> 1) + (area & 1);
		int h = min(n, m), w = max(n, m);
		// n <= m
		if (h == 1)
			ans = w;
		if (h == 2)
			ans = max(ans, ((w / 4) * 2 + min(w & 3, 2)) * 2);
		printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
	}
	return 0;
}

