#include<bits/stdc++.h>
using namespace std;
vector<int>primes;
char memo[1010][15][65];
char a[15], b[15];
inline bool cmp(const int x, const int y){
	sprintf(a, "%d", x);
	sprintf(b, "%d", y);
	return strcmp(a, b) < 0;
}
inline void sieve(void){
	const int upper_bound = 300;
	bitset<upper_bound + 10> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
		if(bs[i]){
			primes.push_back(i);
			for (int j = i*i; j <= upper_bound; j += i)
				bs[j] = 0;
		}
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
}
inline char dp(const int n, const int t, const int i){
	if (n < 0 || t < 0) return 0;
	if (n == 0 || t == 0 || i == primes.size()) return (n == 0 && t == 0);
	char & ret = memo[n][t][i];
	if (ret != -1) return ret;
	return ret = (primes[i] != 2 && dp(n - (primes[i] << 1), t - 2, i + 1)) || dp(n - primes[i], t - 1, i + 1) || dp(n, t, i + 1);
}
inline void path(const int n, const int t, const int i){
	if (primes[i] != 2 && dp(n - (primes[i] << 1), t - 2, i + 1)){
		printf("%d+%d", primes[i], primes[i]);
		if (n - (primes[i] << 1) == 0) printf("\n");
		else {
			printf("+");
			path(n - (primes[i] << 1), t - 2, i + 1);
		}
	}
	else if (dp(n - primes[i], t - 1, i + 1)){
		printf("%d", primes[i]);
		if (n - primes[i] == 0) printf("\n");
		else {
			printf("+");
			path(n - primes[i], t - 1, i + 1);
		}
	}
	else path(n, t, i + 1);
}
int main(void){
	sieve();
	sort(primes.begin(), primes.end(), cmp);
	init();
	for (int x, y, tc = 1; scanf("%d%d", &x, &y), x || y; ++tc){
		printf("CASE %d:\n", tc);
		if (!dp(x, y, 0)) printf("No Solution.\n");
		else path(x, y, 0);
	}
	return 0;
}

