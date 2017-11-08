#include<bits/stdc++.h>
#define MAX (1 << 16)
using namespace std;
typedef long long int ll;
vector<int>primes;
inline void sieve(void){
	primes.reserve(MAX/log(MAX));
	bitset<MAX+10>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= MAX; ++i)
		if (bs[i]){
			primes.push_back(i);
				for (ll j = (ll)i * i; (ll)j <= MAX; j += ll(i))
					bs[j] = 0;
		}
}
void factorize(int x, vector<int>&v){
	for (int i = 0, p = primes[i]; (ll)p*p <= x; p = primes[++i])
		while(x%p == 0)x/=p, v.push_back(p);
	if (x != 1) v.push_back(x);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	sieve();
	vector<int>ans; int x;
	while(scanf("%d", &x), x){
		ans.clear();
		factorize(abs(x), ans);
		printf("%d = ", x);
		if (x < 0) printf("-1 x ");
		printf("%d", ans[0]);
		for (int i = 1; i < ans.size(); ++i)
			printf(" x %d", ans[i]);
		printf("\n");
	}
	return 0;
}

