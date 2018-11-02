#include<bits/stdc++.h>
#define MAX 10001000
using namespace std;
typedef long long int ll;
vector<int>primes;
vector<int>num_factors;
inline void sieve(void){
	const int upper_bound = sqrt(MAX) + 100;
	primes.reserve(upper_bound/log(upper_bound));
	bitset<upper_bound + 10> bs;
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
int main(void){
	sieve();
	num_factors.push_back(0);
	num_factors.push_back(0);
	int acc = 0;
	while(true){
		acc += num_factors.back();
		if (acc >= MAX) break;
		int x = num_factors.size();
		if (binary_search(primes.begin(), primes.end(), x))
		{
			num_factors.push_back(1);
			continue;
		}
		bool flag = false;
		for (int i = 0; i < primes.size(); ++i)
			if (x % primes[i] == 0){
				num_factors.push_back(1 + num_factors[x / primes[i]]);
				flag = true;
				break;
			}
		if (!flag) num_factors.push_back(1);
	}
	for (int i = 1; i < num_factors.size(); ++i)
		num_factors[i] += num_factors[i - 1];
	for (int x, tc = 1; scanf("%d", &x), x >= 0;++x, ++tc){
		printf("Case %d: ", tc);
		int y = lower_bound(num_factors.begin(), num_factors.end(), x) - num_factors.begin();
		if (num_factors[y] == x) printf("%d!\n", y);
		else printf("Not possible.\n");
	}
	return 0;
}

