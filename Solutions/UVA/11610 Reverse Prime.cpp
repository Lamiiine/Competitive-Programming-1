#include<bits/stdc++.h>
#define lsone(s) ((s) & (-s))
#define avg(a, b) (((a) + (b)) >> 1)
using namespace std;
vector<int> primes;
vector<int> rev_primes;
vector<int> num_factors;
int n;
vector<int> ft;
vector<int> ft_ones;
inline int reverse(int i)
{
	int ans = 0;
	while(i)
	{
		ans = ans * 10 + i % 10;
		i /= 10;
	}
	return ans;
}
inline void sieve(void)
{
	const int N = 1000000;
	primes.reserve(N / log(N));
	bitset<N + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= N; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			if ((long long int) i * i <= N)
			{
				for (int j = i * i; j <= N; j += i)
				{
					bs[j] = 0;
				}
			}
		}
	}

	n = primes.size();
	rev_primes.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int x = reverse(primes[i]);
		while(x < N)
		{
			x *= 10;
		}
		rev_primes[i] = x;
	}

	sort(rev_primes.begin(), rev_primes.end());

	num_factors.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int x = rev_primes[i];
		int & cur = num_factors[i];
		for (int j = 0, p = 2; p * p <= x; p = primes[++j])
		{
			while(x % p == 0)
			{
				x /= p;
				++cur;
			}
		}
		if (x != 1)
		{
			++cur;
		}
	}
}
inline void update(int i, const int v)
{
	for(++i; i <= n; i += lsone(i))
	{
		ft[i] += v;
	}
}
inline int rsq(int i)
{
	int sum = 0;
	for (++i; i; i -= lsone(i))
	{
		sum += ft[i];
	}
	return sum;
}
inline void construct_ft(void)
{
	ft.resize(n);
	for (int i = 0; i < n; ++i)
	{
		update(i, num_factors[i]);
	}
	ft_ones.resize(n);
}
inline void update_ones(int i, const int v)
{
	for (++i; i <= n; i += lsone(i))
	{
		ft_ones[i] += v;
	}
}
inline int rsq_ones(int i)
{
	int sum = 0;
	for (++i; i; i -= lsone(i))
	{
		sum += ft_ones[i];
	}
	return sum;
}
inline int binary_search_ones(const int i)
{
	// return the true index of the element whose index is i
	int lo = 0, hi = n - 1;
	while(lo != hi)
	{
		const int mid = avg(lo, hi);
		const int cur_index = mid - rsq_ones(mid);
		if (cur_index == i)
		{
			return mid;
		}
		if (cur_index < i)
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid - 1;
		}
	}
	return lo;
}
int main(void)
{
	sieve();
	construct_ft();
	char s[5];
	int x;
	while(~scanf("%s%d", s, &x))
	{
		if (*s == 'q')
		{
			int i = binary_search_ones(x);
			printf("%d\n", rsq(i));
		}
		else
		{
			int i = lower_bound(rev_primes.begin(), rev_primes.end(), x) - rev_primes.begin();
			update(i, -num_factors[i]);
			update_ones(i, 1);
		}
	}
	return 0;
}

