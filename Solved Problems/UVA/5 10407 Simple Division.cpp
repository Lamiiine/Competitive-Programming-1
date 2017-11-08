#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 1005
using namespace std;
inline int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}
int counter;
int a[MAX];
int solve(){
	int ans = a[0] - a[1];
	for (int i = 0; i < counter; ++i)
		for (int j = i + 1; j < counter; ++j)
			ans = gcd(ans, abs(a[i] - a[j]));
	return ans;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int x;
	while(scanf("%d", &x), x){
		a[0] = x;
				counter = 1;
		while(scanf("%d", &x), x)
			a[counter++] = x;
		printf("%d\n", solve());
	}
}

