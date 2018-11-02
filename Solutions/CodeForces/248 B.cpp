#include <stdio.h>
#include <string.h>
#define MAX 100005
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	if (n < 3){
		printf("-1");
		return 0;
	}
	if (n == 3) {
		printf("210");
		return 0;
	}
	char num[MAX];
	memset(num, '0', n*sizeof(char));
	num[0] = '1';
	num[n] = 0;
	int toAdd = 50;
	for (int i = 0; i < n - 4; ++i){
		toAdd *= 10;
		toAdd %= 210;
	}
	int counter = 1;
	while (toAdd){
		num[n-(counter++)] += (toAdd%10);
		toAdd /= 10;
	}
	printf("%s", num);
	return 0;
}