#include<stdio.h>
#include<math.h>
#include<vector>
#include<bitset>
#include<string.h>
#define MAX 1000005
using namespace std;
typedef long long int ll;
vector<int>primes;
int acc[MAX] = { 0LL };
void sieve(){
	const int upper_bound = 1000001;
	primes.reserve(upper_bound / log(upper_bound));
	bitset<MAX>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
	if (bs[i]){
		primes.push_back(i);
		if ((ll) i*i <= upper_bound)
		for (int j = i*i; j <= upper_bound; j += i)
			bs[j] = 0;
	}
}
int numDiv(int x){
	int p = 1, ans = 1;
	for (int i = 0; p*p <= x; ++i){
		p = primes[i];
		int power = 0;
		while (x % p == 0) x /= p, ++power;
		ans += power;
	}
	if (x != 1) ++ans;
	return ans - 1;	// exclude the one
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	sieve();
	acc[1] = 0;
	for (int i = 2; i <= 1000000; ++i)
		acc[i] = acc[i - 1] + numDiv(i);
	int x;
	while (scanf("%d", &x) != EOF)
		printf("%d\n", acc[x]);
	return 0;
}