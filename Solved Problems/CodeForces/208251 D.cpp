#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

ll n, k;
int main(void)
{
	ll TC; cin >> TC;
	while(TC--)
	{
		cin >> n >> k;
		ll counter = 0LLU;
		for (ll t = k; t <= n && t > 0LLU; t *= 10LLU)
			counter += min(n - t + 1LLU, t / k);
		printf("%.7lf\n", (double) double(counter) / double(n));
	}

	return 0;
}

