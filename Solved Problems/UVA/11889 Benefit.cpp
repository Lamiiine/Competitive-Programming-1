#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
vi primes;
inline void sieve(void){
	const int upper_bound = 3200;
	bitset<upper_bound>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
		if (bs[i]){
			primes.push_back(i);
			for (int j = i * i; j <= upper_bound; j += i)
				bs[j] = 0;
		}
}
inline void factorize(int x, vii & factors){
	for (int i = 0, p = 2; p*p <= x; p = primes[++i]){
		if (x % p == 0){
			int counter = 1; x /= p;
			while(x % p == 0) ++counter, x /= p;
			factors.push_back(ii(p, counter));
		}
	}
	if (x != 1) factors.push_back(ii(x, 1));
}
vii fact_a, fact_b;
inline int raise(int x, int p){
	int ans = 1;
	for (;p; p>>= 1, x *= x)
		if (p & 1) ans *= x;
	return ans;
}
inline int comp(int a, int b){
	fact_a.clear();
	fact_b.clear();
	factorize(a, fact_a), factorize(b, fact_b);
	int ans = 1, i = 0, j =0;
	// loop over a's factorization
	for (; i < fact_a.size(); ++i){
		ii v = fact_a[i];
		while(j < fact_b.size() && v.first > fact_b[j].first){
			ans *= raise(fact_b[j].first, fact_b[j].second);
			++j;
		}
		if (j == fact_b.size()) return -1;
		ii u = fact_b[j];
		if (u.first != v.first) return -1;
		if (u.second < v.second) return -1;
		if (u.second > v.second) ans *= raise(u.first, u.second);
		++j;
	}
	for (;j < fact_b.size(); ++j)
		ans *= raise(fact_b[j].first, fact_b[j].second);
	return ans;
}
int main(void){
	sieve();
	int TC;
	int a, b;
	for(scanf("%d", &TC);TC--;){
		scanf("%d%d", &a, &b);
		int ans = comp(a, b);
		if (ans == -1) printf("NO SOLUTION\n");
		else printf("%d\n", ans);
	}
	return 0;
}

