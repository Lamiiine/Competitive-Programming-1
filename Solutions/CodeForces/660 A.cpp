#include<stdio.h>
#include<string.h>
#define MAX 1005
using namespace std;
int a[MAX];
bool done[MAX];
inline int gcd(int m, int n) {
	if (!(m % n))
		return n;
	return gcd(n, m % n);
}
int pCount;
int prime[1000000];
bool isPrime[1000000];
int main() {
	// freopen("Input.txt", "r", stdin);
	memset(isPrime, 1, sizeof isPrime);
	isPrime[0] = isPrime[1] = 0;
	for (int i = 2; i <= 500000; ++i)
		if (isPrime[i])
			for (int j = 1; j < 1000000 / i; ++j)
				isPrime[i * j] = 0;
	for (int i = 0; i < 1000000; ++i)
		if (isPrime[i])
			prime[pCount++] = i;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	int counter = 0;
	memset(done, 0, sizeof done);
	for (int i = 1; i < n; ++i)
		if (gcd(a[i], a[i - 1]) != 1)
			done[i] = true, ++counter;
	printf("%d\n", counter);
	printf("%d", a[0]);
	for (int i = 1; i < n; ++i) {
		if (done[i]) {
			for (int j = pCount - 1; j >= 0; --j) {
				int x = prime[j];
				if (gcd(x, a[i]) == 1 && gcd(x, a[i - 1]) == 1) {
					printf(" %d", x);
					break;
				}
			}
		}
		printf(" %d", a[i]);
	}
}

