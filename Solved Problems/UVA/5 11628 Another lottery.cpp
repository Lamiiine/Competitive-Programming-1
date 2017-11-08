#include<bits/stdc++.h>
using namespace std;
int arr[10100];
int n, m;
int main(void)
{
	while(scanf("%d%d", &n, &m), n || m)
	{
		int tot = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", arr + i);
			}
			tot += arr[i];
		}

		for (int i = 0; i < n; ++i)
		{
			const int d = __gcd(arr[i], tot);
			printf("%d / %d\n", arr[i] / d, tot / d);
		}
	}

	return 0;
}

