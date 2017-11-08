#include<stdio.h>
#include<algorithm>
#define MAX 1005
using namespace std;
int v[MAX];
int n, m;
bool can(int x){
	int j = 0;
	for (int i = 0; i < m && j < n; ++i){
		int temp = x;
		while(temp >= v[j] && j < n) temp -= v[j++];
	}
	return j >= n;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d%d", &n, &m) != EOF){
		for (int i = 0; i < n; ++i)
			scanf("%d", v + i);
		int lo = 0, hi = 1000000000;
		while(lo != hi){
			int mid = min((lo + hi) >> 1, hi - 1);
			if (can(mid))hi = mid;
			else lo = mid + 1;
		}
		printf("%d\n", hi);
	}
	return 0;
}

