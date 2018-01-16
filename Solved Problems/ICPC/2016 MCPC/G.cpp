#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
int arr[MAX], n, k;

bool check(int diam)
{
	int i = 0;

	for (int iter = 0; iter < k && i < n; ++iter)
	{
		const int start = arr[i];
		int j = i + 1;
		while(j < n && arr[j] - start <= diam)
			++j;
		i = j;
	}

	return i == n;
}

int main(){

#ifdef ONLINE_JUDGE
	freopen("going.in", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		sort(arr, arr + n);
			int s = 0, e = arr[n - 1] - arr[0];
			while (s != e)
			{
				int m = (s + e) >> 1;
				if (check(m))
					e = m;
				else
					s = m + 1;
			}
			printf("%.3lf\n", (double) s * 0.5);
	}
}
