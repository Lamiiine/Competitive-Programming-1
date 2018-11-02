#include<bits/stdc++.h>
#define MAX 1100
#define INIT 1000000
using namespace std;
vector<int> primes;
inline void sieve(void)
{
	bitset<MAX + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= MAX; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			for (int j = i * i; j <= MAX; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}
inline bool is_prime(const int x)
{
	if (x <= MAX)
	{
		return binary_search(primes.begin(), primes.end(), x);
	}
	for (int i = 0, p = primes[i]; p * p <= x; p = primes[++i])
	{
		if (x % p == 0)
		{
			return 0;
		}
	}
	return 1;
}
int ans_i, ans_j;
int arr[MAX], n, acc[MAX];
inline int solve(void)
{
	int ans = INIT;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			if (j > i && j - i + 1 < ans && is_prime(acc[j] - (i ? acc[i - 1] : 0)))
			{
				ans = j - i + 1;
				ans_i = i;
				ans_j = j;
			}
		}
	}
	return ans;
}
inline void read(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
	}
	acc[0] = arr[0];
	for (int i = 1; i < n; ++i)
	{
		acc[i] = acc[i - 1] + arr[i];
	}
}
int main(void)
{
	sieve();
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		int ans = solve();
		if (ans == INIT)
		{
			printf("This sequence is anti-primed.\n");
		}
		else
		{
			printf("Shortest primed subsequence is length %d:", ans);
			for (int k = ans_i; k <= ans_j; ++k)
			{
				printf(" %d", arr[k]);
			}
			printf("\n");
		}
	}
	return 0;
}

