#include <stdio.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	if (n <= 10 || n > 21) { printf("0"); return 0; }
	if (n == 20) { printf("15"); return 0; }
	printf("4"); return 0;
}