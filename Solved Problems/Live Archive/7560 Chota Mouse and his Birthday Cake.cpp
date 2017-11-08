#include<bits/stdc++.h>
#define MAX 10100
using namespace std;
int p[MAX];
int f, h, w;
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		scanf("%d%d%d", &f, &h, &w);
		for (int i = 0, x; i < f; ++i)
			scanf("%d", p + i);
		p[f++] = 0; p[f++] = w;
		sort(p, p + f);
		int ans = w;
		for (int i = 1; i < f; ++i)
			ans = min(ans, p[i] - p[i - 1]);
		printf("%d\n", ans * h);
	}
}

