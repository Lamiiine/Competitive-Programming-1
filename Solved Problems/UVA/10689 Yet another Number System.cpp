#include<stdio.h>
#define MAX 15005
using namespace std;
int a, b, n, m;
int memo[MAX];
int solve(void){
	int upper_bound;
	switch(m){
		case 1:upper_bound = 60;break;
		case 2:upper_bound = 300;break;
		case 3:upper_bound = 1500;break;
		case 4:upper_bound = 15000;break;
	}
	int ten = 1;
	while(m--) ten *= 10;
	n %= upper_bound;
	memo[0] = a % ten, memo[1] = b% ten;
	for (int i = 2; i <= n; ++i)
		memo[i] = (memo[i - 1] + memo[i - 2])% ten;
	return memo[n];
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while(TC--){
		scanf("%d%d%d%d", &a, &b, &n, &m);
		printf("%d\n", solve());
	}
	return 0;
}

