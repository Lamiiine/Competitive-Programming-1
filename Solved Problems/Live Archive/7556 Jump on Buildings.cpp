#include<bits/stdc++.h>
#define MAX 5010
using namespace std;
int n, h[MAX], r[MAX], l[MAX];
inline void read(void){
	for (int i = 0; i < n; ++i)
		scanf("%d", h + i);
}
inline void solve(void){
	r[0] = l[0] = 0;
	for (int i = 1; i < n; ++i){
		r[i] = l[i] = 0;
		for (int j = i - 1; j >= 0; --j)
			if (h[i] > h[j])
				l[i] = max(l[i], 1 + r[j]);
			else if (h[j] > h[i])
				r[j] = max(r[j], 1 + l[i]);
	}
}
inline void print(void){
	for (int i = 0; i < n; ++i)
		printf("%d ", max(l[i], r[i]));
	printf("\n");
}
int main(void){
	while(~scanf("%d", &n)){
		read();
		solve();
		print();
	}
	return 0;
}

