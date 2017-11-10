#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
int n;
int arr[MAX];
int lis[MAX];
int ans = 1;
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	lis[n - 1] = 1;
	for (int i = n - 2; i >= 0; --i)
	{
		if (arr[i] < arr[i + 1])
		{
			lis[i] = 1 + lis[i + 1];
		}
		else
		{
			lis[i] = 1;
		}
		ans = max(ans, lis[i]);
	}
	// Corner case: the optimal subsegment might be obtainable
	// by adding a single element to an already strictly increasing
	// subsegment.
	for (int i = 1; i < n; ++i)
	{
		ans = max(ans, lis[i] + 1);
	}
	for (int i = n - 1; i >= 0; --i)
	{
		if (lis[i] < n - i)
		{
			ans = max(ans, lis[i] + 1);
		}
	}
	// Or, the optimal subsegment might be obtainable by merging
	// two strictly increasing segments, by changing the border
	// elements.
	for (int i = 0; i < n; ++i)
	{
		const int li = lis[i];
		// try changing some border elements!
		const int j = i + li - 1, k = i + li;
		if (j > 0)
		{
			if (arr[j + 1] - arr[j - 1] >= 2)
			{
				ans = max(ans, li + lis[j + 1]);
			}
		}
		if (k < n - 1)
		{
			if (arr[k + 1] - arr[k - 1] >= 2)
			{
				ans = max(ans, li + 1 + lis[k + 1]);
			}
		}
	}
	cout << ans;
	return 0;
}
/*
6
7 2 3 1 5 6
 */

