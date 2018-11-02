#include <bits/stdc++.h>
#define MAX_PRIME 1000000
#define MAX 10000
using namespace std;
typedef pair<int, int> ii;
vector<int> primes;
bitset<MAX_PRIME> bs;
inline void sieve()
{
	primes.reserve(MAX_PRIME / log(MAX_PRIME));
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i < MAX_PRIME; ++i)
		if (bs[i])
		{
			primes.push_back(i);
			if (1LL * i * i < MAX_PRIME)
			for (int j = i * i; j < MAX_PRIME; j += i)
				bs[j] = 0;
		}
}
vector<ii> factors;
inline void factorize(int x)
{
	for (int i = 0, p = primes[0]; 1LL * p * p <= x; p = primes[++i])
	{
		int counter = 0;
		while (x % p == 0)
			++counter, x /= p;
		if (counter)
			factors.push_back(ii(p, counter));
	}
	if (x != 1)
		factors.push_back(ii(x, 1));
}
vector<int> divisors; int val = 1;
inline void gen_div(const int i)
{
	if (i == factors.size())
		divisors.push_back(val);
	else
	{
		gen_div(i + 1);
		ii t = factors[i];
		int tmp = 1;
		while (t.second--)
		{
			val *= t.first;
			tmp *= t.first;
			gen_div(i + 1);
		}
		val /= tmp;
	}
}
inline int sum_digits(int x)
{
	int ans = 0;
	for (; x; x /= 10)
		ans += (x % 10);
	return ans;
}
int memo[MAX], len_memo[MAX];
inline int get_next(const int x)
{
	int & ret = memo[x];
	if (ret != -1) return ret;
	factors.clear(); divisors.clear();
	factorize(x);
	gen_div(0);
	ret = 0;
	for (const int divisor : divisors)
		ret += sum_digits(divisor);
	return ret;
}
inline int get_len(const int x)
{
	int & ret = len_memo[x];
	if (ret != -1) return ret;
	const int nxt = get_next(x);
	if (x == nxt)
		return ret = 1;
	return ret = 1 + get_len(nxt);
}
inline void init()
{
	memset(memo, -1, sizeof memo);
	memset(len_memo, -1, sizeof len_memo);
}
inline void print(const int x)
{
	printf(" %d", x);
	if (get_next(x) != x)
		print(get_next(x));
}
int main()
{
	sieve();
	init();
	for (int TC = 1, n, m; scanf("%d%d", &n, &m) != EOF; ++TC)
	{
		printf("Input%d: %d %d\n", TC, n, m);
		if (n > m) swap(n, m);
		int ans = 0, ans_start;
		for (int x = n; x <= m; ++x)
		{
			const int cur = get_len(x);
			if (cur > ans)
				ans = cur, ans_start = x;
		}
		printf("Output%d:", TC);
		print(ans_start);
		printf("\n");
	}
	return 0;
}

