#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
int n, k;
int arr[MAX];
int tmp[MAX];
int main(void){
	// freopen("Input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 0, a, b, c, d; i < n; ++i){
		scanf("%d.%d.%d.%d", &a, &b, &c, &d);
		arr[i] = (a << 24) | (b << 16) | (c << 8) | d;
	}
	for (int i = 31; i > 0; --i){
		int mask = ~((1 << i) - 1);
		for (int j = 0; j < n; ++j)
			tmp[j] = arr[j] & mask;
		sort(tmp, tmp + n);
		int count = 0;
		for (int j = 0; j < n;){
			int network = tmp[j];
			++count;
			while(j < n && tmp[j] == network) ++j;
		}
		if (count == k){
			printf("%d.%d.%d.%d",(mask & 0xFF000000) >> 24, (mask & 0xFF0000) >> 16, (mask&0xFF00) >> 8, (mask & 0xFF));
			return 0;
		}
	}
	printf("-1");
	return 0;
}

