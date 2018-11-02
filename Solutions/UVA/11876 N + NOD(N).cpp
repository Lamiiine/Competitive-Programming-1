#define MAX 1000005
#include<math.h>
#include<algorithm>
#include<vector>
#include<bitset>
#include<string>
#include<stdio.h>
using namespace std;
typedef long long int ll;
vector<int>primes;
void sieve(){
	bitset<MAX + 10> bs;
	bs.set();
	int upper_bound = 1000001;
	primes.reserve(upper_bound/log(upper_bound));
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
		if (bs[i]){
			primes.push_back(i);
			if ((ll) i * i <= upper_bound)
				for (int j = i *i; j <= upper_bound; j += i)
					bs[j] = 0;
		}
}
int numDiv(int x){
	int ans = 1;
	int p = 1;
	for (vector<int>::iterator iter = primes.begin(); p*p <= x; ++iter){
		p = *iter;
		int power = 0;
		while(!(x % p))x /= p, ++power;
		ans *= (power + 1);
	}
	if (x != 1) ans <<= 1;
	return ans;
}
vector<int>v;
int main(void){
	// freopen("Input.txt", "r", stdin);
	sieve();
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(7);
	v.push_back(9);
	v.push_back(12);
	v.push_back(18);
	while(v.back() < 1000000)v.push_back(v.back() + numDiv(v.back()));
	int TC;
	scanf("%d", &TC);
	for (int tc = 1, x, y; tc <= TC; ++tc)
		scanf("%d%d", &x, &y), printf("Case %d: %d\n", tc, upper_bound(v.begin(), v.end(), y) - lower_bound(v.begin(), v.end(), x));
	return 0;
}

