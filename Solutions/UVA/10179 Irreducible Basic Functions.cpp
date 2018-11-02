#include<bits/stdc++.h>
using namespace std;
vector<int>primes;
inline void sieve(void){
	const int upper_bound = (1 << 15);
	bitset<upper_bound + 10>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
		if (bs[i]){
			primes.push_back(i);
			for (int j = i*i; j <= upper_bound && j > 0; j += i)
				bs[j] = 0;
		}
}
int phi(int x){
	int ans = x;
	for (int i = 0, p = 2; p*p <= x; p = primes[++i])
		if (x % p == 0){
			ans -= ans /p;
			while(x % p == 0) x /= p;
		}
	if (x != 1) ans -= ans /x;
	return ans;
}
int main(void){
	sieve();
	for (int x; scanf("%d", &x), x; printf("%d\n", phi(x)));
	return 0;
}

