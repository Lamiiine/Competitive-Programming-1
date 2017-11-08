#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		int a, b, c, d, e, f;
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		int tot_1 = a + b + c;
		int tot_2 = d + e + f;
		printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
		bool win_count = tot_1 > tot_2;
		bool win_color = (a != d) ? (a > d) : ((b != e) ? b > e : c > f);
		printf("%s\n\n", win_count && win_color ? "both" : win_count ? "count" : win_color ? "color" : "none");
	}
	return 0;
}
/*
5
10 5 15 10 1 0
10 5 15 10 6 10
12 5 10 5 20 30
10 0 15 10 5 30
10 5 15 10 5 15
 */

