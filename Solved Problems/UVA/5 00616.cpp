#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
int n;
bool can(int m){
	int num = n;
	for (int a = 0; a < m; ++a){	// temp men will wake up
		if (num % m != 1) return false;
		num -= (num/m + 1);
	}
	return !(num%m);
}
int main(){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d", &n), n >= 0){
		printf("%d coconuts, ", n);
		bool flag = false;
		for (int m = sqrt(n)+1; m >= 2; --m)
			if (can(m)) {
				printf("%d people and 1 monkey\n", m);
				flag = true;
				break;
			}
		if (!flag) printf("no solution\n");
	}
	return 0;
}

