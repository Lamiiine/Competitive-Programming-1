#include<bits/stdc++.h>
#define MAX 14000000
using namespace std;
int memo[MAX];
inline void init_memo(void)
{
	int i = 1, current_iter = 1;
	for (int up = 10; up <= MAX; up *= 10)
	{
		for (;i < up; ++i)
		{
			memo[i] = current_iter;
		}
		++current_iter;
	}
	for (; i < MAX; ++i)
	{
		memo[i] = current_iter;
	}
}
inline int count_digits(int x)
{
	return (int)floor(1 + log10((double) x));
}
int main(void)
{
	init_memo();
	for (int i = 2; i < MAX; ++i)
		memo[i] += memo[i - 1];
	srand(time(0));
	for (int n; ~scanf("%d", &n);)
	{
		int x = (upper_bound(memo + 1, memo + MAX, n) - memo) - 1;
		/* the answer is in x, since the count of digits up to and including
		 * x is less than or equal to n
		 */
		if (memo[x] < n)
		{
			int m = n - memo[x];
			++x;
			// you need the m^th digit in x
			int counter = count_digits(x) - m;
			while(counter--)
				x /= 10;
		}
		printf("%d\n", x % 10);
	}
	return 0;
}

