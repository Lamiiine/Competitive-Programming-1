#include<bits/stdc++.h>
#define MAX (1 << 11)
using namespace std;
int n, m;
int arr[MAX];
int origin[MAX];
map<int, int> counter;
vector<int> occ[MAX];
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	const int ans = n / m;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
		if (counter.find(arr[i]) == counter.end())
			counter[arr[i]] = 1;
		else ++counter[arr[i]];
	}
	for (int i = 1; i <= m; ++i)
		counter[i];

	int replacements = 0;
	memcpy(origin, arr, sizeof arr);
	for (int p = 1; p <= m; ++p)
	{
		for (int j = 0; j < n && counter[p] < ans; ++j)
		{
			const int q = arr[j];
			if (q < 1 || q > m || counter[q] > ans)
			{
				++replacements;
				arr[j] = p;
				--counter[q];
				++counter[p];
			}
		}
	}

	printf("%d %d\n", ans, replacements);
	for (int i = 0; i < n; ++i)
		printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
	return 0;
}

