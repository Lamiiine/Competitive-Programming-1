#include<bits/stdc++.h>
#define MAX 1000100
#define left(s) ((s) << 1)
#define right(s) (((s) << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
using namespace std;
vector<int> primes;
int arr[MAX + 10];
inline void sieve(void)
{
	for (int i = 1; i <= MAX; ++i)
	{
		arr[i] = 1;
	}

	bitset<MAX + 10> bs;
	bs.set();
	for (int i = 2; i <= MAX; ++i)
	{
		if (bs[i])
		{
			for (int j = i; j <= MAX; j += i)
			{
				bs[j] = 0;
				int power = 1;
				int x = j;
				while(x % i == 0)
				{
					x /= i;
					++power;
				}

				arr[j] *= power;
			}
		}
	}
}
int st[MAX << 2];
inline void build(const int p, const int l, const int r)
{
	if (l == r)
	{
		st[p] = r;
		return;
	}
	build(left(p), l, avg(l, r));
	build(right(p), avg(l, r) + 1, r);
	int p1 = st[left(p)], p2 = st[right(p)];
	st[p] = arr[p1] > arr[p2] ? p1 : p2;
}
inline int rmq(const int p, const int l, const int r, const int i, const int j)
{
	if (r < i || l > j)
	{
		return -1;
	}

	if (l >= i && r <= j)
	{
		return st[p];
	}

	int p1 = rmq(left(p), l, avg(l, r), i, j), p2 = rmq(right(p), avg(l, r) + 1, r, i, j);
	if (p1 == -1)
	{
		return p2;
	}
	if (p2 == -1)
	{
		return p1;
	}
	return arr[p1] > arr[p2] ? p1 : p2;
}
int main(void)
{
	sieve();
	build(1, 1, MAX);
	int TC; scanf("%d", &TC);
	int n;
	while(TC--)
	{
		scanf("%d", &n);
		printf("%d\n", rmq(1, 1, MAX, 1, n));
	}
	return 0;
}

