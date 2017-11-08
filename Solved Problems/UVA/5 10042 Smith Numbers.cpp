#include<stdio.h>
#include<math.h>
#include<vector>
#include<bitset>
using namespace std;
vector<int>primes;
inline void sieve(void){
	const int MAX = 1 << 15;
	primes.reserve(MAX/log(MAX));
	bitset<MAX + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= MAX; ++i)
	if (bs[i]){
		primes.push_back(i);
		for (int j = i*i; j <= MAX; j += i)
			bs[j] = 0;
	}
}
inline void factorize(int x, vector<int> & factors){
	for (int i = 0, p = 2; x != 1 && p*p <= x; p = primes[++i])
		while(x % p == 0) factors.push_back(p), x/= p;
	if (x != 1) factors.push_back(x);
}
inline int sum_digits(int i){
	int ans = 0;
	for(;i; i /= 10)
		ans += (i % 10);
	return ans;
}
inline int sum_digits(vector<int> v){
	int ans = 0;
	for (int i = 0; i < v.size(); ++i)
		ans += sum_digits(v[i]);
	return ans;
}
inline bool smith(int x){
	vector<int>v;
	factorize(x, v);
	return v.size() > 1 && sum_digits(v) == sum_digits(x);
}
inline int solve(int start){
	for (int i = start + 1; ; ++i)
	if (smith(i)) return i;
}
int main() {
	sieve();
	int TC; scanf("%d", &TC);
	for(int x; TC--;) scanf("%d", &x), printf("%d\n", solve(x));
	return 0;
}
