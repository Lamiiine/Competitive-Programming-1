#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long int ll;
ll cube[MAX];
inline void init_cube(void)
{
	for (ll i = 0LL; i < MAX; ++i)
	{
		cube[i] = i * i * i;
	}
}
int main(void)
{
	init_cube();
	for (ll n; scanf("%lld", &n), n;)
	{
		bool flag = false;
		for (ll y = 1LL; y < MAX; ++y)
		{
			if (binary_search(cube + 1, cube + MAX, cube[y] + n))
			{
				ll x = lower_bound(cube + 1, cube + MAX, n + cube[y]) - cube;
				printf("%lld %lld\n", x, y);
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			printf("No solution\n");
		}
	}
	return 0;
}

