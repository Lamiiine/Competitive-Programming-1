#include<stdio.h>
#define MAX 13
using namespace std;
typedef long long int ll;
ll memo[MAX];
void init(void){
	memo[0] = 1LL;
	for (int i = 1; i <= 10; ++i)
		memo[i] = (2*(2*i - 1)*memo[i - 1])/(i + 1);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	int n;
	bool first = true;
	while(scanf("%d", &n) != EOF){
		if(!first) printf("\n");
		first = false;
		printf("%d\n", memo[n]);
	}
}

