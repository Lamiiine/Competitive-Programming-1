#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
inline ll solve()
{
	ll ans = 0LL;
	int n, a;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &a);
		ans = ans + ll((a / 30) + bool(a % 30));
	}
	return ans;
}
int main(void)
{
	freopen("leap.in", "r", stdin);
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		cout << solve() << '\n';
	}
	return 0;
}
