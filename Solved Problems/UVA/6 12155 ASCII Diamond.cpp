#include<bits/stdc++.h>
using namespace std;
int n, r1, r2, c1, c2;
int main(void)
{
	for (int tc = 1; scanf("%d", &n), n; ++tc)
	{
		printf("Case %d:\n", tc);
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		const int len = (n << 1) - 1;
		for (int i = r1; i <= r2; ++i)
		{
			for (int j = c1; j <= c2; ++j)
			{
				const int dist = (abs(n - 1 - (i % len)) + abs(n - 1 - (j % len)));
				printf("%c", dist >= n ? '.' : 'a' + (dist % 26));
			}
			printf("\n");
		}
	}
}

