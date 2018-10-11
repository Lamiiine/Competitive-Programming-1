#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
inline int lcm(int a, int b){
	return a * (b / __gcd(a, b));
}
vi primes;
inline void sieve(void){
	const int upper_bound = 45000;
	primes.reserve(upper_bound/log(upper_bound));
	bitset<upper_bound + 10>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
		if (bs[i]){
			primes.push_back(i);
			for (int j = i*i; j <= upper_bound; j += i)
				bs[j] = 0;
		}
}
vii factors;
inline void factorize(int x){
	for (int i = 0, p = primes[i]; p*p <= x; p = primes[++i])
		if (x % p == 0){
			int counter = 1; x/= p;
			while(x % p ==0) x /= p, ++counter;
			factors.push_back(ii(p, counter));
		}
	if (x != 1) factors.push_back(ii(x, 1));
}
vi divisors;
int val = 1;
inline void generate_div(int i){
	if (i == factors.size()) {divisors.push_back(val);return;}
	generate_div( i + 1);
	ii t = factors[i];
	int tmp = 1;
	for (int j = 0; j < t.second; ++j)
		val *= t.first, tmp *= t.first, generate_div(i + 1);
	val /= tmp;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	sieve();
	for (int n; scanf("%d", &n), n; divisors.clear(), factors.clear(), val = 1){
		factorize(n);
		generate_div(0);
		int ans = 1;
		for (int i = 0; i < divisors.size(); ++i)
			for (int j = i + 1; j < divisors.size(); ++j)
				ans += (lcm(divisors[i], divisors[j]) == n);
		printf("%d %d\n", n, ans);
	}
	return 0;
}

