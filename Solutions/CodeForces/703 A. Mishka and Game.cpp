#include<bits/stdc++.h>
using namespace std;
int main(void){
	int m = 0, c = 0;
	int n; scanf("%d", &n);
	for(int x, y; n--;){
		scanf("%d%d", &x, &y);
		m += (x > y);
		c += (y > x);
	}
	if (m > c) printf("Mishka");
	else if (c > m) printf("Chris");
	else printf("Friendship is magic!^^");
}

