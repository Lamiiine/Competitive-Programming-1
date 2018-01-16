#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
long double memo[10][370000];
long double fact[10];

long double p(int count, int num){
	if (memo[count][num] != 0.0) return memo[count][num];
	if (num == 1) return memo[count][num] = 1.0/fact[count];
	return memo[count][num] = (1.0 + 1.0 / fact[count])*p(count, num-1);
	// the probability of winning by using the item right after = (1.0 / fact[count])*p(count, num-1)
	// + the probability of winning without using it  = p(count, num-1)
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	int Fact[10];
	Fact[0] = 1;
	for (int i = 1; i <= 9; i++) Fact[i] = i*Fact[i - 1];
	for (int i = 0; i <= 9; ++i) fact[i] = Fact[i];
	int n;
	int x[11];
	int y[11];
	int count;
	int num;
	memset(memo, 0.0, sizeof memo);
	while (TC--){
		scanf("%d", &n);
		count = 0;
		while (n){
			x[count++] = n % 10;
			n /= 10;
		}
		for (int i = 0; i < count; i++) y[count - i - 1] = x[i];
		num = 0;
		while (next_permutation(y, y + count))
			num++;
		if (!num) printf("0.000000000\n");
		else printf("%1.9llf\n", p(count, num));
	}
	return 0;
}