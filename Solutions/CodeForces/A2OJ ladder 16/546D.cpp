#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAX 5000005
using namespace std;
int PrimeCount;
int prime[MAX >> 1];
long long Factor[MAX];
long long factor(int n){	// number of factors of a given integer n
	if (Factor[n] != -1LL) return Factor[n];
	for (int i = 0; i < min(PrimeCount, n/2 + 1); ++i)
	if (!(n%prime[i])) return Factor[n] = 1 + factor(n / prime[i]);
}
void generatePrimes(){
	bool isPrime[MAX + 1];
	memset(isPrime, 0x1, sizeof isPrime);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i < MAX; ++i)
	if (isPrime[i])
	for (int j = 2; j <= MAX / i; ++j)
		isPrime[i*j] = false;
	PrimeCount = 0;
	for (int i = 2; i < MAX; ++i)
	if (isPrime[i]){
		Factor[prime[PrimeCount++] = i] = 1;
	}
	return;
}
int main(){
	memset(Factor, 0xFF, sizeof Factor);
	Factor[1] = 0;
	generatePrimes();
	int TC;
	scanf("%d", &TC);
	int a, b;
	for (int i = 1; i < MAX; ++i) factor(i);
	for (int i = 1; i < MAX; ++i) Factor[i] += Factor[i - 1];
	while (TC--){
		scanf("%d%d", &a, &b);
		cout << Factor[a] - Factor[b] << '\n';
	}
	return 0;
}
