#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
int num_pf[MAX + 10];
bool sqr_free[MAX + 10];
typedef long long int ll;
inline void sieve(void){
	memset(num_pf, 0, sizeof num_pf);
	memset(sqr_free, 0x01, sizeof sqr_free);
	for (int i = 2; i <= MAX; ++i)
		if (!num_pf[i]){
			for (int j = i; j <= MAX; j += i)
				++num_pf[j];
			if ((ll) i * i <= MAX)
			{
				int inc = i*i;
				for (int j = inc; j <= MAX; j += inc)
					sqr_free[j] = 0;
			}
		}
}
int mu[MAX + 10];
int M[MAX + 10];
inline void init(void){
	sieve();
	mu[1] = 1;
	for (int i = 2; i <= MAX; ++i)
	{
		int & val = mu[i];
		if (!sqr_free[i]) val = 0;
		else val = (num_pf[i] & 1) ? -1 : 1;
	}
	M[1] = 1;
	for (int i = 2; i <= MAX; ++i)
		M[i] = M[i - 1] + mu[i];
}
int main(void){
	init();
	for (int x; scanf("%d", &x), x; printf("%8d%8d%8d\n", x, mu[x], M[x]));
	return 0;
}

