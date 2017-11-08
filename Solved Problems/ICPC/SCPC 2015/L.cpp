#include<bits/stdc++.h>
#define MAX 100100
#define lsone(s) ((s) & (-s))
using namespace std;
int arr[MAX] = { 0 };
vector<int> primes;
inline void sieve(void)
{
	const int UP = 32;
	bitset<UP + 10> bs;
	bs.set();
	for (int i = 2; i <= UP; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			for (int j = i * i; j <= UP; j += i)
				bs[j] = 0;
		}
}
inline bool is_prime(const int i)
{
	return binary_search(primes.begin(), primes.end(), i);
}
inline int count_ones(int i)
{
	int ans = 0;
	while(i)
	{
		++ans;
		i -= lsone(i);
	}
	return ans;
}
inline void init(void)
{
	for (int i = 0; i < MAX; ++i)
		arr[i] = is_prime(count_ones(i));
	for (int i = 1; i < MAX; ++i)
		arr[i] += arr[i - 1];
}
int main(void)
{
	sieve();
	init();
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		int l, r; scanf("%d%d", &l, &r);
		printf("%d\n", arr[r] - (l ? arr[l - 1] : 0));
	}
	return 0;
}
