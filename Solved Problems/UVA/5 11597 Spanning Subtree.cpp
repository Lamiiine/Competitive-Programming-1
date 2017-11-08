#include<bits/stdc++.h>
using namespace std;
int komplete(int n){
	return (n*(n-1)) >> 1;
}
int main(void){
	int n;
	for(int tc = 1; scanf("%d", &n), n; ++tc)
		printf("Case %d: %d\n", tc, komplete(n)/(n-1));
	return 0;
}

