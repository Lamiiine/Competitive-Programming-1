// YOU GOT A WA, THEN YOU JUST REPLACES 'int' WITH 'long long int' AND IT WORKED PERFECTLY FIND
#include<stdio.h>
#include<limits.h>
#include<math.h>
#include<vector>
#include<bitset>
#define MAX 1000000
using namespace std;
typedef long long int ll;
bitset<MAX + 10>bs;
vector<ll>primes;
void sieve(){
	const ll upper_bound = sqrt(2147483647) + 2LL;
	bitset<upper_bound + 10LL>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= upper_bound; ++i)
		if (bs[i]){
			primes.push_back(i);
			for (int j = i * i; j <= upper_bound; j += i)
				bs[j] = 0;
		}
}
void solve(ll x, ll y){
	x = max(x, 2LL);
	// we first generate all primes in between x and y inclusive
	bs.set();
	for (int i = 0; i < primes.size(); ++i){
		ll p = primes[i];
		// printf("%d\n", p);
		if (p * p > y) break;
		// printf("p*p = %d\n", p*p);
		ll j = max(p*p, p*(x/p));
		while(j < x && j > 0) j += p;
		for (;j <= y && j > 0; j += p)
			bs[j - x] = 0;
	}
	// find the first prime i
	ll i = x;
	while(i <= y && !bs[i - x])++i;
	ll min_dist = INT_MAX, max_dist = INT_MIN;
	ll min_i, min_j, max_i, max_j;
	while(true){
		ll j = i + 1;
		for (; j <= y && j > 0; ++j)
			if (bs[j-x]){	// j is an adjacent prime
				ll cur_dist = j - i;
				if (max_dist < cur_dist)
					max_dist = cur_dist, max_i = i, max_j = j;
				if (min_dist > cur_dist)
					min_dist = cur_dist, min_i = i, min_j = j;
				i = j;
				break;
			}
		if (j > y || j < 0) break;
	}
	if (min_dist == INT_MAX)
		printf("There are no adjacent primes.\n");
	else printf("%lld,%lld are closest, %lld,%lld are most distant.\n", min_i, min_j, max_i, max_j);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	sieve();
	for (ll x, y; scanf("%lld%lld", &x, &y) != EOF;)
		solve(x, y);
	return 0;
}

