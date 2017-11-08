#include<stdio.h>
#include<algorithm>
#define MAX 300005
using namespace std;
bool a[MAX];
int acc[MAX]; 	// number of zeros before and including i
int n, k;
int main(){
	// freopen("Input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	int x;
	scanf("%d", &x);
	a[0] = x;
	acc[0] = (!x);
	for (int i = 1; i < n; ++i){
		scanf("%d", &x);
		a[i] = x;
		acc[i] = acc[i - 1] + (!x);
	}
	if (acc[n - 1] <= k){
		printf("%d\n", n);
		for (int i = 0; i < n; ++i) printf("1 ");
		return 0;
	}
	int start = 0, end = 0;
	int ans = 0, Start = 0, End = 0;	// my range, inclusive
	while (end < n && start < n){
		int Bef = (!start) ? 0 : acc[start - 1];
		while (acc[end] - Bef <= k && end < n) ++end;
		if (ans < end - start){
			ans = end - start;
			Start = start;
			End = end;
		}
		++start;
		while (acc[start - 1] == Bef && start < n) ++start;
	}
	printf("%d\n", ans);
	for (int i = 0; i < Start; ++i)
		printf("%d ", a[i]);
	for (int i = Start; i < End; ++i)
		printf("1 ");
	// YOU WROTE 'end' INSTEAD OF 'n'
	for (int i = End; i < n; ++i) printf("%d ", a[i]);
	return 0;
}