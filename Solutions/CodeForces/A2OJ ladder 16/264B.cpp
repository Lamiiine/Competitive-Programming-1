#include <bits/stdc++.h>
#define MAX 100005
using namespace std;
typedef long long int ll;
vector<int> primes;
vector<int> occurences[MAX];
vector<int> factors[MAX];
int n;
int arr[MAX];
int memo[MAX];
inline int find_next_occurence_of_factor(const int p, const int i)
{
	return *upper_bound(occurences[p].begin(), occurences[p].end(), i);
}
inline int dp(const int i)
{
	int & ret = memo[i];
	// Memorization!
	if (~ret) return ret;
	// Base case (i == n) already handled in init()!
	// Recursion!
	ret = 1;
	for (const int f : factors[i])
	{
		ret = max(ret, 1 + dp(find_next_occurence_of_factor(f, i)));
	}
	return ret;
}
inline void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
	}
}
inline void sieve()
{
	bitset<MAX + 1> bs;
	const int MAX_SQRT = sqrt(MAX) + 10;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= MAX; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			if (i <= MAX_SQRT)
			{
				for (int j = i * i; j <= MAX; j += i)
				{
					bs[j] = 0;
				}
			}
		}
	}
}
inline void factorize(int x, const int idx)
{
	for (int i = 0, p = 2; p * p <= x; p = primes[++i])
	{
		if (x % p == 0)
		{
			occurences[p].push_back(idx);
			factors[idx].push_back(p);
			x /= p;
			while (x % p == 0) x /= p;
		}
	}
	if (x != 1)
	{
		occurences[x].push_back(idx);
		factors[idx].push_back(x);
	}
}
inline void preprocess()
{
	for (int i = 0; i < n; ++i)
	{
		factorize(arr[i], i);
	}
	for (int i = 0; i < MAX; ++i)
	{
		occurences[i].push_back(n);
	}
}
inline void init()
{
	memset(memo, -1, sizeof memo);
	memo[n] = 0;
}
int main()
{
	sieve();
	read();
	preprocess();
	init();
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans = max(ans, dp(i));
	printf("%d", ans);
	return 0;
}

