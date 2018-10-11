#include <bits/stdc++.h>
using namespace std;
int n, b;
int main()
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d%d", &n, &b);
		int ans = 0;
		for(int k; b--; )
		{
			int cur = 1;
			scanf("%d", &k);
			for (int a; k--; )
			{
				scanf("%d", &a);
				cur *= a, cur %= n;
			}
			ans += cur, ans %= n;
		}
		printf("%d\n", ans);
	}
	return 0;
}

