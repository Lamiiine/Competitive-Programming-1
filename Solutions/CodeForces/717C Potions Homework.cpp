#include<bits/stdc++.h>
#define MAX 100100
#define MOD 10007LL
using namespace std;
typedef long long int ll;
int arr[MAX];
int n;
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	sort(arr, arr + n);
	long long int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = ((ll) ans + ll(arr[i]) * 1LL * ll(arr[n - 1 - i] * 1LL)) % MOD;
	cout << ans;
	return 0;
}

