#include<bits/stdc++.h>
#define MAX (1 << 10)
using namespace std;
char s[MAX];
inline int calc(void)
{
	const int n = strlen(s);
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = (ans * 10 + s[i] - '0') % 11;
	}
	return ans;
}

int main(void)
{
	while(scanf("%s", s), strcmp(s, "0"))
		printf("%s is %sa multiple of 11.\n", s, calc() == 0 ? "" : "not ");
	return 0;
}

