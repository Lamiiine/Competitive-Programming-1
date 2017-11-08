#include<stdio.h>
#include<algorithm>
using namespace std;
int main(void)
{
	int TC; scanf("%d", &TC);
	for (int ox, x, y; TC--;)
	{
		scanf("%d%d%d", &ox, &x, &y);
		const int inc = max(ox - x, 0);
		printf("%d\n", inc / y + (bool(inc % y)));
	}
	return 0;
}
