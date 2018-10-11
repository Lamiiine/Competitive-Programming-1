#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
inline bool test(const ll potential_x, const ll final)
{
	return (potential_x - (potential_x / 10)) == final;
}
set<ll> solve(ll given)
{
	set<ll> ans;
	for (int rem = 0; rem <= 9; ++rem)
	{
		const ll x_9 = (10LL * given - rem);
		if (x_9 % 9 == 0 && test(x_9 / 9, given))
			ans.insert(x_9 / 9);
	}
	return ans;
}
int main()
{
	for (ll given; scanf("%llu", &given), given; )
	{
		const auto ans = solve(given);
		for (const auto x : ans)
			printf("%llu%s", x, x == *ans.rbegin() ? "" : " ");
		printf("\n");
	}
	return 0;
}

