#include<bits/stdc++.h>
#define MAX 62510
using namespace std;
int occ[MAX];
int n, p, q;
int arr[MAX];
int counter;
inline void read(void){
	scanf("%d%d%d", &n, &p, &q);
	memset(occ, 0xFF, sizeof occ);
	for (int x, i = 0; i <= p; ++i)
		scanf("%d", &x), occ[x] = i;
	counter = 0;
	for (int x, i = 0; i <= q; ++i)
	{
		scanf("%d", &x);
		int y = occ[x];
		if (y != -1)
			arr[counter++] = y;
	}
}
int l[MAX];
inline int solve(void){
	int lis = 0;
	for (int i = 0; i < counter; ++i)
	{
		int x = arr[i];
		int ind = lower_bound(l, l + lis, x) - l;
		l[ind] = x;
		lis = max(lis, ind + 1);
	}
	return lis;
}
int main(void){
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		read();
		printf("Case %d: %d\n", tc, solve());
	}
	return 0;
}

