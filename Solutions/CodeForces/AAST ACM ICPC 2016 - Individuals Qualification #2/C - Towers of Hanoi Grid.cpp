#include<bits/stdc++.h>
using namespace std;
int d, n;
int main(void)
{
	int TC; scanf("%d", &TC);
	for(int tc = 1; tc <= TC; ++tc)
	{
		scanf("%d%d", &d, &n);
		printf("Grid #%d: ", tc);
		const int free = (n - 1) * (n - 1);
		if (free >= d - 1)
		{
			printf("%d", (d << 1) * (n - 1));
		}
		else
		{
			printf("impossible");
		}
		printf("\n\n");
	}
	return 0;
}
/*
3
2 2
100 8
3 100
 */

