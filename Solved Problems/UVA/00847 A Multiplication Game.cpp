#include<bits/stdc++.h>
#define MAX 4294967295LL
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> ii;
vector<ii> states;
inline void init_states(void)
{
	states.push_back(ii(1, 9));
	while(states.back().second < MAX)
	{
		if (states.size() & 1)
		{
			// construct a losing range
			const ii prev = states.back();
			states.push_back(ii(prev.second + 1, prev.second * 2LL));
		}
		else
		{
			const ii prev = states.back();
			states.push_back(ii(prev.second + 1, prev.second * 9LL));
		}
	}
}
int main(void)
{
	init_states();
	for(ll n; ~scanf("%lld", &n);)
	{
		for (int i = 0; i < states.size(); ++i)
		{
			const ii cur = states[i];
			if (n >= cur.first && n <= cur.second)
			{
				printf("%s wins.\n", i & 1 ? "Ollie" : "Stan");
				break;
			}
		}
	}
	return 0;
}

