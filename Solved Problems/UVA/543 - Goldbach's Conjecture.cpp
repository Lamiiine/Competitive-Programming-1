#include<stdio.h>
#include<math.h>
#include<vector>
#include<bitset>
#define MAX 1000000
using namespace std;
typedef long long int ll;
bitset<MAX + 10> bs;
vector<int>primes;
void sieve(void){
	primes.reserve(MAX/log(MAX));
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 3; i <= MAX; i += 2)
		if (bs[i]){
			primes.push_back(i);
			if ((ll) i*i <= MAX)
			for (int j = i*i; j <= MAX; j += i)
				bs[j] = 0;
		}
}
void solve(int x){
	for (int i = 0; i < primes.size() && primes[i] < x; ++i)
		if (bs[x - primes[i]]){
			printf("%d = %d + %d\n", x, primes[i], x - primes[i]);
			return;
		}
	printf("Goldbach's conjecture is wrong.’\n");
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	sieve();
	int x;
	while(scanf("%d", &x), x) solve(x);
	// for (int i = 6; i < 1000000; i += 2) solve(i);
	return 0;
}

