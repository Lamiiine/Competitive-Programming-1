#include<bits/stdc++.h>
#define MAX (1 << 14)
using namespace std;
typedef long long int ll;
int deg[MAX];
int n;
inline bool read(void)
{
	scanf("%d", &n);
	if (!n) return false;
	for (int i = 0; i < n; ++i)
		scanf("%d", deg + i);
	return true;
}
inline bool tot_sum_even(void)
{
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ll) ans + deg[i];
	return (ans & 1LL) == 0;
}
inline ll sum(const int start, const int k)
{
	ll ans = 0;
	for (int i = start; i < n; ++i)
		ans = (ll) ans + min(deg[i], k);
	return ans;
}
inline bool valid(void)
{
	if (!tot_sum_even()) return false;
	ll a = 0;

	for (int i = 0; i < n; ++i)
	{
		a = (ll) a + deg[i];
		if (a > i * (i + 1) + sum(i + 1, i + 1))
			return false;
	}
	return true;
}
inline void flip()
{
	int i = 0, j = n - 1;
	while(i < j)
	{
		swap(deg[i], deg[j]);
		++i; --j;
	}
}
int main(void)
{
	while(read())
	{
		sort(deg, deg + n);
		flip();
		printf("%sossible\n", valid() ? "P" : "Not p");
	}
	return 0;
}

