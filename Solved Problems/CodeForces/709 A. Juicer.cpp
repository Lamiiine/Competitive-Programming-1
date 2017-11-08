#include <bits/stdc++.h>
#define MAX 100100
using namespace std;
int arr[MAX];
int n, b, d;
int main() {
	scanf("%d%d%d", &n, &b, &d);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
	}
	int ans = 0;
	int cur_size = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] > b)
		{
			continue;
		}
		cur_size += arr[i];
		if (cur_size > d)
		{
			cur_size = 0;
			++ans;
		}
	}
	printf("%d", ans);
	return 0;
}