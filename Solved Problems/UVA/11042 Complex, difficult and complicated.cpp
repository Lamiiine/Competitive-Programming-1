#include<bits/stdc++.h>
#define N (1 << 10)
#define MAX (1LL << 30LL)
using namespace std;
typedef long long int ll;
typedef complex<ll> cll;
int main(void)
{
	int TC; scanf("%d", &TC);
	for(int x, y, n; TC--; )
	{
		scanf("%d%d", &x, &y);
		cll z = cll(x, y);
		cll t = z;
		n = 1;
		while(n < N && t.imag() != 0 && t.imag() <= MAX && t.real() <= MAX)
		{
			t *= z;
			++n;
		}
		if (n < N && t.imag() == 0 && t.real() <= MAX)
			printf("%d\n", n);
		else
			printf("TOO COMPLICATED\n");
	}
	return 0;
}

