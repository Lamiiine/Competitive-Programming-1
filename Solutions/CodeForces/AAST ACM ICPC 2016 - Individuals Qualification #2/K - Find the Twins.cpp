#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		bool mack = false, zack = false;
		for (int i = 0, x; i < 10; ++i)
		{
			scanf("%d", &x);
			printf("%d%c", x, i == 9 ? '\n' : ' ');
			mack |= (x == 18);
			zack |= (x == 17);
		}

		printf("%s\n\n", mack && zack ? "both" : mack ? "mack" : zack ? "zack" : "none");
	}
	return 0;
}
/*
4
11 99 88 17 19 20 12 13 33 44
11 12 13 14 15 16 66 88 19 20
20 18 55 66 77 88 17 33 44 11
12 23 34 45 56 67 78 89 91 18
 */

