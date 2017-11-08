#include<bits/stdc++.h>
#define LSOne(s) ((s) & (-s))
using namespace std;
inline int count_ones(int s){
	int ans = 0;
	while(s)
		++ans, s -= LSOne(s);
	return ans;
}
inline void print(int s){
	int i = 31;
	while(!(s & (1 << i))) --i;
	for (; i >= 0; --i)
		printf("%c", '0' + bool(s & (1 << i)));
}
int main(void){
	for (int x; scanf("%d", &x), x; ){
		printf("The parity of ");
		print(x);
		printf(" is %d (mod 2).\n", count_ones(x));
	}
	return 0;
}

