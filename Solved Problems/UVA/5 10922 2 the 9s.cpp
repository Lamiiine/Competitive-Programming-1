#include<bits/stdc++.h>
#define MAX (1 << 10)
using namespace std;
typedef long long int ll;
char s[MAX];
inline int deg(ll i)
{
	if (!i || i % 9LL)
	{
		return 0;
	}
	if (i == 9)
	{
		return 1;
	}

	ll j = 0;
	while(i)
	{
		j += (i % 10LL);
		i /= 10LL;
	}
	return 1 + deg(j);
}
int main(void)
{
	while(scanf("%s", s), strcmp(s, "0"))
	{
		printf("%s ", s);
		const int n = strlen(s);
		ll ans = 0LL;
		for (int i = 0; i < n; ++i)
		{
			ans += (ll) (s[i] - '0');
		}

		if (ans % 9LL)
		{
			printf("is not a multiple of 9.");
		}
		else
		{
			printf("is a multiple of 9 and has 9-degree %d.", deg(ans));
		}
		printf("\n");
	}
	return 0;
}

