
#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
vector<int>primes;
inline void sieve(void){
	const int upper_bound = (1 << 15);
	primes.reserve(upper_bound/log(upper_bound));
	bitset<upper_bound + 10>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
		if (bs[i]){
			primes.push_back(i);
			for (int j = i*i; j <= upper_bound && j > 0; j += i)
				bs[j] = 0;
		}
}
vector<int>v[MAX + 10];
int val[MAX + 10];
inline void sieve(int n, int m){
	n = max(n, 2);
	const int upper_bound = m - n + 1;
	for (int i = 0; i < primes.size(); ++i){
		const int p = primes[i];
		int j = max(p*p, (n/p)*p);
		while(j < n) j += p;
		// j is the first multiple of p that is >= n
		for (;j <= m; j+= p){
			int count = 0;
			int temp = val[j - n];
			while(temp % p == 0)temp/= p, ++count;
			val[j - n] = temp;
			v[j - n].push_back(count);
		}
	}
	for (int i = 0; i < upper_bound; ++i)
		if (val[i] != 1)
			v[i].push_back(1);
}
inline void init(int x, int y){
	const int size = y - x + 1;
	for (int i = 0; i < size; ++i)
		v[i].clear(), val[i] = i + x;
}
inline int cal(const vector<int>& v){
	int ans = 1;
	for (int i = 0; i< v.size(); ++i)
		ans *= (v[i]+1);
	return ans;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	sieve();
	int TC;
	scanf("%d", &TC);
	for (int x, y; TC--;)
	{
		scanf("%d%d", &x, &y);
		if (x == 1 && y == 1){
			printf("Between 1 and 1, 1 has a maximum of 1 divisors.\n");
			continue;
		}
		int old_x = x;
		x = max(x, 2);
		init(x, y);
		sieve(x, y);	// segment sieve from x to y
		const int upper_bound = y - x + 1;
		int ans = 0, ind = 0;
		for (int i = 0; i < upper_bound; ++i){
			int j = cal(v[i]);
			if (j > ans)
				ans = j, ind = i + x;
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n", old_x, y, ind, ans);
	}
	return 0;
}

