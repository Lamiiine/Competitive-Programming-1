#include<bits/stdc++.h>
#define MAX 5000100
using namespace std;
int memo[MAX] = {0};
int acc[MAX];
inline void sieve(void){
	for (int i = 2; i < MAX; ++i)
		if (!memo[i])
			for (int j = i << 1; j < MAX; j += i)
				memo[j] += i;
	acc[1] = 0;
	acc[2] = 1;
	for (int i = 3; i < MAX; ++i)
		acc[i] = acc[i - 1] + (!memo[i] || !memo[memo[i]]);
}
int main(void){
	sieve();
	for (int a, b; scanf("%d", &a), a; ){
		scanf("%d", &b);
		printf("%d\n", acc[b] - acc[a-1]);
	}
	return 0;
}

