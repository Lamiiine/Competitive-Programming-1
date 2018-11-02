#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define eps 1e-9
using namespace std;
int main(){
	// freopen("Input.txt", "r", stdin);
	long long n;
	long long sum;
	printf("PERFECTION OUTPUT\n");
	while(scanf("%lld", &n), n){
		// N = 1 IS A SPECIAL CASE
		sum = 1;
		for (int i = 2; i <= (n >> 1); ++i)
			if (!(n%i))
				sum += i;
		if(n == 1) sum = 0;
		printf("%5d  %s\n", n, (sum == n)?"PERFECT":(sum < n)?"DEFICIENT":"ABUNDANT");
	}
	printf("END OF OUTPUT\n");
	return 0;
}

