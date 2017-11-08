#include<bits/stdc++.h>
#define MAX 1000000
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vi primes;
inline void sieve(void){
	const int upper_bound = 1000100;
	primes.reserve(upper_bound/log(upper_bound));
	bitset<upper_bound + 10>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
		if (bs[i]){
			primes.push_back(i);
			if ((ll) i * i <= upper_bound)
			for (int j = i * i; j <= upper_bound; j += i)
				bs[j] = 0;
		}
}
int solve(int x){
	int ans = 1;
	int i = 0;
	int power_2 = 1, power_5 = 1;
	for (int p = 2; p * p <= x; p = primes[++i]){
		int f = p;
		while(f <= x) f *= p;
		f /= p;
		if (p == 2)
			power_2 = f;
		else if (p == 5)
			power_5 = f;
		else ans = (ans *f)%10;
	}
	for (int p = primes[i]; p <= x; p = primes[++i])
	{
		if (p == 2)
			power_2 = 2;
		else if (p == 5)
			power_5 = 5;
		else
		ans = (ans *p)%10;
	}
	while(power_2 > 1 && power_5 > 1)
		power_2 >>= 1, power_5 /= 5;
	return (ans*(power_2*power_5)%10)%10;
}
int main(void){
	sieve();
	for (int x; scanf("%d", &x), x;)
		printf("%d\n", solve(x));
	return 0;
}

