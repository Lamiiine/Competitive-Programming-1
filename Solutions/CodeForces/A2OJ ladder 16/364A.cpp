#include <bits/stdc++.h>
#define MAX 4005
using namespace std;
typedef long long ll;
int freq[MAX * 9];
int a;
char s[MAX];
int main()
{
	cin >> a >> s;
	const int l = strlen(s);
	int tot_sum = 0;
	for (int i = 0; i < l; ++i)
	{
		tot_sum += (s[i] -= '0');
	}

	for (int i = 0; i < l; ++i)
	{
		int sum = 0;
		for (int j = i; j < l; ++j)
		{
			++freq[sum += s[j]];
		}
	}
	ll ans = 0;
	if (a == 0)
	{
		int sum_freq = 0;
		for (int i = 0; i <= tot_sum; ++i)
		{
			sum_freq += freq[i];
		}
		ans = (ll) freq[0] * 1LL * (sum_freq * 2LL - freq[0]);
	}
	else
	{
		for (int i = 1; i <= tot_sum; ++i)
		{
			if (a % i == 0 && a / i <= tot_sum)
			{
				ans += (ll) freq[i] * 1LL * freq[a / i];
			}
		}
	}
	cout << ans;
	return 0;
}
/*
10
12345

16
439873893693495623498263984765

0
1230
 */

