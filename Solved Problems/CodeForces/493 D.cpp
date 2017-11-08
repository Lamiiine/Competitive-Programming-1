#include <stdio.h>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	if (n & 1) printf("black");
	else printf("white\n1 2");
	return 0;
}