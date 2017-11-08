#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<bitset>
#include<vector>
using namespace std;
vector<int>primes;
bitset<100005>bs;
void sieve(int n, int m){
	n = max(n, 2);
	const int upper_bound = m - n + 1;
	bs.set();
	// loop over all primes
	for (int i = 0; i < primes.size(); ++i)
	{
		int p = primes[i];
		// WHAT IF 'n' IS TOO SMALL?
		int j = max((n/p)*p, p*p);
		while(j < n) j += p;
		for (;j <= m; j += p)
			bs[j-n] = 0;
	}
	for (int i = 0; i < upper_bound; ++i)
		if (bs[i]) printf("%d\n", i + n);
}
void init(void){
	// get all primes up to 32000
	const int upper_bound = 32000;
	primes.reserve(upper_bound/log(upper_bound));
	bitset<upper_bound + 10>bs;
	bs.set();
	bs[0] = bs[1] = 0;	// not primes
	for (int i = 2; i <= upper_bound; ++i)
		if (bs[i]){
			primes.push_back(i);
			for (int j = i*i; j <= upper_bound; j += i)
				bs[j] = 0;
		}
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	// now primes contains primes up to sqrt(maximum query value)
	int TC;
	scanf("%d", &TC);
	int n, m;
	while(TC--){
		scanf("%d%d", &n, &m);
		sieve(n, m);
		printf("\n");
	}
	return 0;
}
