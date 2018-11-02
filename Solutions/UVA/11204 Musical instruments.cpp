#include<bits/stdc++.h>
#define MAX (1 << 6)
using namespace std;
typedef long long int ll;
int fav[MAX];
int n, m;
inline void init(void)
{
	memset(fav, 0, sizeof fav);
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		scanf("%d%d", &n, &m);
		for (int x, i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				scanf("%d", &x);
				if (x == 1)
				{
					++fav[j];
				}
			}
		}

		ll ans = 1LL;
		for (int i = 0; i < n; ++i)
			ans *= (ll) max(1, fav[i]);
		printf("%lld\n", ans);
	}
	return 0;
}

