#include<bits/stdc++.h>
using namespace std;
vector<int>primes;
inline void sieve(void){
	const int upper_bound = 100;
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
inline int raise(int x, int p){
	int ans = 1;
	for (;p; p >>= 1, x *= x)
		if (p & 1) ans *= x;
	return ans;
}
inline int sum_div(int x){
	int ans = 1;
	for (int i = 0, p = 2; p*p <= x; p = primes[++i]){
		int power = 0;
		while(x % p == 0) x /= p, ++power;
		ans *= (raise(p, power + 1) - 1)/(p - 1);
	}
	if (x != 1) ans *= (raise(x, 2) - 1)/(x - 1);
	return ans;
}
int arr[1001];
inline void init(void){
	sieve();
	memset(arr, 0xFF, sizeof arr);
	for (int i = 1; i <= 1000; ++i){
		int sum = sum_div(i);
		if (sum <= 1000LL && arr[sum] == -1) arr[sum] = i;
	}
}
int main(void){
	init();
	for (int x, tc = 0; scanf("%d", &x), x;printf("Case %d: %d\n", ++tc, arr[x]));
	return 0;
}

