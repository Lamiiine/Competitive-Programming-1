#include<stdio.h>
#include<algorithm>
#include<bitset>
#include<vector>
#include<math.h>
using namespace std;
typedef vector<int> vi;
vi primes;
vi acc;
inline void sieve(void) {
	const int upper_bound = 10100;
	primes.reserve(upper_bound / log(upper_bound));
	bitset<upper_bound + 10>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
		if (bs[i]) {
			primes.push_back(i);
			for (int j = i*i; j <= upper_bound; j += i)
				bs[j] = 0;
		}
	acc.resize(primes.size());
	acc[0] = primes[0];
	for (int i = 1; i < primes.size(); ++i)
		acc[i] = acc[i - 1] + primes[i];
}
int solve(int n) {
	int ans = binary_search(acc.begin(), acc.end(), n);
	for (int j = 0; j < acc.size(); ++j)
		ans += binary_search(acc.begin() + j + 1, acc.end(), acc[j] + n);	// find an i such that acc[i] - acc[j] = n (acc[i] = acc[j] + n)
	return ans;
}
int main(void) {
	sieve();
	for (int x; scanf("%d", &x), x; printf("%d\n", solve(x)));
}