#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int TC; scanf("%d", &TC);
	for (int a, b; TC--;)
	{
		scanf("%d%d", &a, &b);
		printf("%c\n", a == b ? '=' : a < b ? '<' : '>');
	}
	return 0;
}

