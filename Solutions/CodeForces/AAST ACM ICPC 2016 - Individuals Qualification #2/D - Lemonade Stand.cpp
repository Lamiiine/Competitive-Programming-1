#include<bits/stdc++.h>
#define MAX (1 << 10)
using namespace std;
typedef long long int ll;
int d, l, s;
int c[MAX], lp[MAX], sp[MAX];	// each bag of sugar has 80 ounces
int main(void)
{
	int TC; cin >> TC;
	while(TC--)
	{
		cin >> d >> l >> s;
		for (int i = 0; i < d; ++i)
		{
			cin >> c[i] >> lp[i] >> sp[i];
		}

		for (int i = 1; i < d; ++i)
		{
			lp[i] = min(lp[i], lp[i - 1]);
			sp[i] = min(sp[i], sp[i - 1]);
		}

		int cur_s = 0;
		ll tot_cost = 0LL;
		for (int i = 0; i < d; ++i)
		{
			tot_cost = (ll) tot_cost + ((ll)c[i] * l) * lp[i];
			const int need_s = c[i] * s;
			if (need_s > cur_s)
			{
				const int shortage_s = need_s - cur_s;
				const int buy = (int) (shortage_s / 80) + (shortage_s % 80 != 0 ? 1 : 0);
				tot_cost = (ll) tot_cost + ((ll)buy * sp[i]);
				cur_s = (cur_s + buy * 80) - need_s;
			}
			else
			{
				cur_s -= need_s;
			}
		}

		cout << tot_cost << '\n';
	}
	return 0;
}
/*
2
3 3 2
200 10 399
300 8 499
400 12 499
2 5 10
9 10 199
8 20 99
 */

