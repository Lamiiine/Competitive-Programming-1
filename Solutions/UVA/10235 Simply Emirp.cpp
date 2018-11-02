#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<bitset>
#include<vector>
#include<math.h>
#define MAX 1000000
using namespace std;
typedef long long int ll;
enum prime_t : char{prime = 0, not_prime, emirp} p[MAX + 10];
inline int reverse(int x) {
	int y = 0;
	for (; x; x /= 10)
		y = y * 10 + x % 10;
	return y;
}
inline void sieve(void) {
	memset(p, 0, sizeof p);
	p[0] = p[1] = not_prime;	// not_prime
	for (int i = 2; i <= MAX; ++i)
		if (p[i] == prime) {
			if ((ll) i * i <= MAX)
			for (int j = i*i; j <= MAX; j += i)
				p[j] = not_prime;
		}
	for (int i = 2; i <= MAX; ++i)
		if (p[i] == prime) {
			int j = reverse(i);
			if (i < j && p[j] == prime)
				p[i] = p[j] = emirp;
		}
}
int main(void) {
	sieve();
	for (int x; scanf("%d", &x) != EOF; )
		printf("%d is %s.\n", x, p[x] == prime ? "prime" : p[x] == not_prime ? "not prime" : "emirp");
}