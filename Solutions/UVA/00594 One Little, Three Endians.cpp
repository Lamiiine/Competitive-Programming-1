#include<stdio.h>
#include<string.h>
using namespace std;
int reverse(int x){
	int temp = 0;
	for (int i = 0; i < 4; ++i){
		temp <<= 8;
		temp |= x & 0xFF;
		x >>= 8;
	}
	return temp;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int x;
	while(scanf("%d", &x) != EOF)
		printf("%d converts to %d\n", x, reverse(x));
	return 0;
}

