#include<bits/stdc++.h>
using namespace std;
int b, s;
int main(void)
{
	for(int tc = 1; scanf("%d%d", &b, &s), b || s; ++tc)
	{
		printf("Case %d: :-", tc);
		if (b == 1)
		{
			printf("\\");
		}
		else
		{
			if (s >= b)
			{
				printf("|");
			}
			else
			{
				printf("(");
			}
		}

		printf("\n");
	}

	return 0;
}

