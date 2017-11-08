#include<stdio.h>
#include<algorithm>
#include<vector>
#include<set>
#include<bitset>
#include<math.h>
using namespace std;
vector<int> primes;
int arr[20010];
int n, k;
inline void sieve(void)
{
	const int UP = 1000200;
	primes.reserve(UP / log(UP));
	bitset<UP + 10> bs;
	bs.set();
	for (int i = 2; i <= UP; ++i)
	{
		if (bs[i])
		{
			primes.push_back(i);
			if (i <= 1000)
			for (int j = i * i; j <= UP; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}

inline set<int> factorize(int x)
{
	set<int> ans;
	for (int i = 0, p = 2; p * p <= x; p = primes[++i])
	{
		if (x % p == 0)
		{
			ans.insert(p);
			x /= p;
			while (x % p == 0)
			{
				x /= p;
			}
		}
	}

	if (x != 1)
	{
		ans.insert(x);
	}

	return ans;
}

inline void read(void)
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
	}
}

inline bool can(const int limit)
{
	int i = 0;
	for (int j = 0; j < k && i < n; ++j)
	{
		set<int> factors = factorize(arr[i]);
		if (*factors.rbegin() < limit)
		{
			return false;
		}

		for (++i; i < n; ++i)
		{
			const int cur = arr[i];
			vector<int> invalid;
			for (set<int>::iterator iter = factors.begin(); iter != factors.end(); ++iter)
			{
				if (cur % *iter != 0)
				{
					invalid.push_back(*iter);
				}
			}

			for (int k = 0; k < invalid.size(); ++k)
			{
				factors.erase(invalid[k]);
			}

			if (factors.empty() || *factors.rbegin() < limit)
			{
				break;
			}
		}
	}

	return i >= n;
}

int main(void)
{
	// freopen("Input.txt", "r", stdin);
	sieve();
	read();
	int lo = 0, hi = primes.size() - 1;
	while (lo < hi)
	{
		const int mid = max((lo + hi) >> 1, lo + 1);
		if (can(primes[mid]))
		{
			lo = mid;
		}
		else
		{
			hi = mid - 1;
		}
	}
	printf("%d\n", can(primes[lo]) ? primes[lo] : 0);
	return 0;
}