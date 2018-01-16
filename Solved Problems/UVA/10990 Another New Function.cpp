#include<bits/stdc++.h>
#define MAX 2000000
using namespace std;
typedef long long int ll;
ll acc[MAX];
int dep_phi[MAX + 10];
int phi[MAX + 10];
inline void init(void){
	for (int i = 1; i <= MAX; ++i)
		phi[i] = i;
	for (int i = 2; i <= MAX; ++i)
		if (phi[i] == i)
			for (int j = i; j <= MAX; j += i)
				phi[j] = (phi[j]/i)*(i-1);
	dep_phi[1] = 0;
	for (int i = 2; i <= MAX; ++i)
		dep_phi[i] = 1 + dep_phi[phi[i]];
	acc[1] = 0;
	for (int i = 2 ;i <= MAX; ++i)
		acc[i] = dep_phi[i] + acc[i - 1];
}
int main(void){
	init();
	int TC; scanf("%d", &TC);
	for (int x, y; TC--;){
		scanf("%d%d", &x, &y);
		printf("%lld\n", acc[y] - acc[x - 1]);
	}
	return 0;
}

