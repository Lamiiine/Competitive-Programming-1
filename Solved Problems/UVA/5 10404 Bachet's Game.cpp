#include<bits/stdc++.h>
#define MAX 1000100
using namespace std;
char memo[MAX];
int m;
int arr[10];
inline char win(const int i){
	if (i < 0) return 1;
	char & ret = memo[i];
	if (ret != -1) return ret;
	for (int j = m-1; j >= 0; --j)
		if (!win(i - arr[j])) return ret = 1;
	return ret = 0;
}
inline void init_memo(void){
	memset(memo, 0xFF, sizeof memo);
	memo[0] = 0;
	for (int i = 0; i < m; ++i)
		memo[arr[i]] = 1;
}
int main(void){
	for(int n; ~scanf("%d%d", &n, &m);){
		for (int i = 0; i < m; ++i) scanf("%d", arr + i);
		sort(arr, arr + m);
		init_memo();
		printf("%s wins\n", win(n) ? "Stan" : "Ollie");
	}
	return 0;
}

