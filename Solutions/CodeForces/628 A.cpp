#include <stdio.h>

using namespace std;

int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int n, b, p;
	scanf("%d%d%d", &n, &b, &p);
	int numTowels = n * p;
	int numBottles = 0;
	int k, m;
	while (n > 1){
		k = -1;
		m = n;
		while (m)
		{
			k++;
			m >>= 1;
		}
		k = 1 << k;
		n -= (k/2);
		numBottles += (k*b + k/2);
	}
	printf("%d %d", numBottles, numTowels);
	return 0;
}