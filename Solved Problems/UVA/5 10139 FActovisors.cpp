#include<stdio.h>
#include<bitset>
#include<vector>
#include<math.h>
using namespace std;
vector<int>primes;
typedef long long int ll;
typedef pair<int, int > ii;
void sieve(){
	const int upper_bound = 1 << 16;
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
void factorize(int x, vector<ii>&v){
	for (int i = 0, p = primes[0]; p*p <= x; p = primes[++i]){
		int counter = 0;	// number of occurences of this prime in x
		while(x % p == 0) ++counter, x /= p;
		if (counter) v.push_back(ii(p, counter));
	}
	if (x != 1) v.push_back(ii(x, 1));
}
int power(int p, ll n){	// power of p in n!
	int ans = 0;
	ll temp = p;
	while(temp <= n)
		ans += n/temp, temp *= p;
	return ans;
}
bool dividing(int m, int n){	// does m have support in n!
	vector<ii>v;
	factorize(m, v);
	for (int i = 0; i < v.size(); ++i)
	{
		ii x = v[i];
		if (power(x.first, n) < x.second) return false;
	}
	return true;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	sieve();
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
		bool flag;
		if (!m) flag = false;
		else flag = dividing(m, n);
		printf("%d %s %d!\n", m, flag ? "divides" : "does not divide", n);
	}
	return 0;
}

