#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	freopen("gold.in", "r", stdin);
	int TC; scanf("%d", &TC);
	for(int a, b, c; TC--; )
	{
		scanf("%d%d%d", &a, &b, &c);
		printf("%s\n", a == b && b == c ? "yes" : "no");
	}
	return 0;
}
