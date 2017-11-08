#include<stdio.h>
#include<string.h>
using namespace std;
int num[10];
inline void solve(int i){
	while(i){
		++num[i%10];
		i/=10;
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while(TC--){
		int n;
		scanf("%d", &n);
		memset(num ,0, sizeof num);
		for (int i = 1; i <= n; ++i) solve(i);
		printf("%d", num[0]);
		for (int i = 1; i < 10; ++i) printf(" %d", num[i]);
		printf("\n");
	}
}

