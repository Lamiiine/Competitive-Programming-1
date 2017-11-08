#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector<int>primes;
void sieve(){
	const int upper_bound = 32767;
	primes.reserve(upper_bound/log(upper_bound));
	bitset<upper_bound + 10>bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= upper_bound; ++i)
		if (bs[i]){
			primes.push_back(i);
			for (int j = i * i; j <= upper_bound; j += i)
				bs[j] = 0;
		}
}
int raise(int i, int j){
	// return i ^ j
	int ans = 1;
	for (int temp = i; j; j >>= 1, temp *= temp)
		if (j & 1) ans *= temp;
	return ans;
}
void factorize(int x, vector<ii>&v){
	for (int i = 0, p = primes[i]; p*p <= x; p = primes[++i]){
		int counter = 0;
		while(x % p == 0) ++counter, x /= p;
		if (counter) v.push_back(ii(p, counter));
	}
	if (x != 1) v.push_back(ii(x, 1));
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	sieve();
	string line;
	char s[10000];
	while(getline(cin, line), strcmp(line.c_str(), "0")){
		strcpy(s, line.c_str());
		int x = 1;
		for (char * a = strtok(s, " "); a; a = strtok(0, " "))
		{
			char * b = strtok(0, " ");
			int i, j;
			sscanf(a, "%d", &i);
			sscanf(b, "%d", &j);
			x *= raise(i, j);
		}
		vector<ii>v;
		factorize(x - 1, v);
		for (int i = v.size() - 1; i >= 0; --i)
			printf("%d %d%c", v[i].first, v[i].second, !i ? '\n' : ' ');
	}
	return 0;
}

