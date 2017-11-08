#include<bits/stdc++.h>
#define MAX 3000000LL
using namespace std;
typedef long long int ll;
int arr[MAX + 10];
inline void sieve(void)
{
	memset(arr, 0, sizeof arr);
	for (ll i = 2; i <= MAX; ++i)
	{
		if (arr[i] == 0)
		{
			for (ll t = i; t <= MAX; t *= i)
			{
				for (ll j = t; j <= MAX; j += t)
				{
					++arr[j];
				}
			}
		}
	}
}
int main(void)
{
	sieve();
	for (int i = 1; i < MAX; ++i)
	{
		arr[i] += arr[i - 1];
	}
	int TC; scanf("%d", &TC);
	for(int n; TC--; printf("%d\n", upper_bound(arr, arr + MAX, n) - arr))
	{
		scanf("%d", &n);
	}
}

