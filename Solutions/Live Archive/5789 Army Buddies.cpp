#include<bits/stdc++.h>
#define MAX 100010
using namespace std;
int nxt[MAX], p[MAX];
int s, b;
inline void init(void){
	for (int i = 1; i <= s; ++i)
	{
		nxt[i] = i + 1;
		p[i] = i - 1;
	}
	nxt[s] = 0;
	p[1] = 0;
}
int main(void){
	while(scanf("%d%d", &s, &b), s || b){
		init();
		for(int x, y; b--;){
			scanf("%d%d", &x, &y);
			int a = p[x];
			int b = nxt[y];
			nxt[a] = b;
			p[b] = a;
			if (a) printf("%d ", a);
			else printf("* ");
			if (b) printf("%d\n", b);
			else printf("*\n");
		}
		printf("-\n");
	}
	return 0;
}

