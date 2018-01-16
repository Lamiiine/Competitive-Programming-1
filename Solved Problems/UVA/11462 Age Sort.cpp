#include<bits/stdc++.h>
#define MAX 105
using namespace std;
int counter[MAX];
inline void init(void){
	memset(counter, 0, sizeof counter);
}
inline void read(int n){
	for (int x; n--;){
		scanf("%d", &x);
		++counter[x];
	}
}
inline void print(int n){
	for (int i = 0; i < MAX; ++i)
	{
		int v = counter[i];
		while(v--)
			printf("%d%c", i, " \n"[!--n]);
	}
}
int main(void){
	for (int n;scanf("%d", &n), n; ){
		init();
		read(n);
		print(n);
	}
	return 0;
}

