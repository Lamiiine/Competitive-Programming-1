#include<bits/stdc++.h>
#define avg(l, r) (((l) + (r)) >> 1)
using namespace std;
int inversion_index;
int arr[1010];
int n;
int temp[1010];
inline void merge_sort(int l, int r){
	if (l == r) return;
	int m = avg(l, r);
	merge_sort(l, m);
	merge_sort(m + 1, r);
	int i = l, j = m + 1, counter = 0;
	while(i <= m && j <= r)
		if (arr[i] <= arr[j])
			temp[counter++] = arr[i++];
		else inversion_index += (m - i + 1), temp[counter++] = arr[j++];
	while(i <= m)
		temp[counter++] = arr[i++];
	while(j <= r)
		temp[counter++] = arr[j++];
	memcpy(arr + l, temp, counter * sizeof (int));
}
int main(void){
	while(~scanf("%d", &n)){
		inversion_index = 0;
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		merge_sort(0, n - 1);
		printf("Minimum exchange operations : %d\n", inversion_index);
	}
	return 0;
}


