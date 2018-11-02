#include<bits/stdc++.h>
#define MAX 10100
using namespace std;
int A, B, C, M, N;
int arr[MAX];
int acc[MAX];
int counter[MAX];
inline void init_arr(void){
	arr[0] = A;
	for (int i = 1; i < N; ++i)
		arr[i] = (arr[i-1]*B + C) % M + 1;
}
inline void read(void){
	scanf("%d%d%d%d%d", &A, &B, &C, &M, &N);
}
inline void init_acc(void){
	acc[0] = 0;
	for (int i = 1; i <= N; ++i)
		acc[i] = (acc[i-1] + arr[i-1]) % M;
}
inline int sum(const int n){
	return n > 0 ? (n*(n+1)) >> 1 : 0;
}
int main(void){
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		read();
		init_arr();
		init_acc();
		memset(counter, 0, sizeof counter);
		for (int i = 0; i <= N; ++i)
			++counter[acc[i]];
		int ans = 0;
		for (int i = 0; i <= M; ++i)
			ans += sum(counter[i] - 1);
		printf("Case %d: %d\n", tc, ans);
	}
	return 0;
}

