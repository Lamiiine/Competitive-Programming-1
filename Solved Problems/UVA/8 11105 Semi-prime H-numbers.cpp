#include<bits/stdc++.h>
#define MAX 1000100
using namespace std;
int ans[MAX];
bool prime[MAX], semi_prime[MAX];
inline void sieve(void){
	memset(prime, 1, sizeof prime);
	for (int i = 5; i*i < MAX; i += 4)
		if (prime[i])
			for (int j = i*i; j < MAX; j += (i << 2))
				prime[j] = 0;
	memset(semi_prime, 0, sizeof semi_prime);
	for (int i = 5; i*i < MAX; i += 4)
		if (prime[i])
			for (int j = i; i*j < MAX; j += 4)
				if (prime[j])
					semi_prime[i * j] = true;
	ans[1] = 0;
	for (int i = 0; i < MAX; ++i)
		ans[i] = ans[i - 1] + semi_prime[i];
}
int main(void){
	sieve();
	for (int n; scanf("%d", &n), n; printf("%d %d\n", n, ans[n]));
	return 0;
}

