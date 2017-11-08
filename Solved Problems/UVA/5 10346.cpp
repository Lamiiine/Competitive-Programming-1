#include<stdio.h>
#include<algorithm>
#include<string.h>
#define MAX 152
using namespace std;
int n, k;
int main(){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d%d", &n ,&k) != EOF){
		int ans = 0;
		int rem = 0;
		while(n){
			ans += n;
			n += rem;
			rem = n%k;
			n/= k;
		}
		printf("%d\n", ans);
	}
	return 0;
}

