#include<bits/stdc++.h>
using namespace std;
int s, b, m;
int main(void)
{
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc)
	{
		scanf("%d%d", &s, &b);
		printf("Practice #%d: %d %d\n", tc, s, b);
		scanf("%d", &m);
		for(int x; m--;)
		{
			scanf("%d", &x);
			while(b <= x)
			{
				b <<= 1;
			}

			b -= x;
			printf("%d %d\n", x, b);
		}
		printf("\n");
	}
	return 0;
}
/*
2
20 60
8
15
10
20
18
9
12
2
10
15 100
4
1
2
3
5
 */

