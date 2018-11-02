#include<stdio.h>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define MAX 200005
#define eps 1e-9
using namespace std;
int a[MAX];
int n;
bool can(int x){
	int start = 0;
	for (int i = 0; i < 3 && start < n; ++i){
		start = upper_bound(a, a + n, a[start] + x) - a;
	}
	return start == n;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	scanf("%d", &n);
	a[n] = 0;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	sort(a, a + n);
	int lo = 0, hi = 1000000000;
	while(lo != hi){
		int mid = min((lo + hi) >> 1, hi - 1);
		if (can(mid)) hi = mid;
		else lo = mid + 1;
	}
	printf("%lf\n", (double)lo/2.0);
	int start = 0;
	for (int i = 0; i < 3; ++i){
		printf("%lf ", (double)a[start] + lo/2.0);
		start = upper_bound(a, a + n, a[start] + lo) - a;
	}
	return 0;
}

