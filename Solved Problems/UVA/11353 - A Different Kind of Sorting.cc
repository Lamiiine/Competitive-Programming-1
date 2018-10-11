#include <bits/stdc++.h>
#define MAX 2000000
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
int num_factors[MAX+1] = { 0 };

inline void sieve()
{
	num_factors[1] = 0;
	for (int i = 2; i <= MAX; ++i)
		if (!num_factors[i])
		{
			// Prime!
			for (ll prime = i; prime <= MAX; prime *= i)
				for (ll j = prime; j <= MAX; j += prime)
					++num_factors[j];
		}
}
bool cmp(const int a, const int b)
{
	return make_pair(num_factors[a], a) < make_pair(num_factors[b], b);
}
vector<int> ans;
inline void preprocess()
{
	for (int i = 1; i <= MAX; ++i)
		ans.push_back(i);
	sort(ans.begin(), ans.end(), cmp);
}
int main()
{
	sieve();
	preprocess();
	for (int n, TC = 1; scanf("%d", &n), n; TC++)
	{
		printf("Case %d: %d\n", TC, ans[n-1]);
	}
	return 0;
}

