#include<bits/stdc++.h>
#define MAX 1000005
using namespace std;
int memo[MAX] = {0};
inline void init(void){
	for (int i = 2; i <= 1000000; ++i)
		if (!memo[i])
			for (int j = i; j <= 1000000; j += i)
				++memo[j];
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	for (int x; scanf("%d", &x), x;)
		printf("%d : %d\n", x, memo[x]);
	return 0;
}

