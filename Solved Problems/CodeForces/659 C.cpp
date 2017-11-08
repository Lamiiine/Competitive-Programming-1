#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	// freopen("Input.txt", "r", stdin);
	int n, m;
	int a[100005];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", a + i);
	sort(a, a + n);
	int k = 0;
	int b[100005];
	// THIS IS HOW YOU CAN LOOP OVER ELEMENTS NOT IN THE ARRAY
	int j = 0;
	int i = 1;
	while (m >= i){
		for (; i != a[j] && m >= i; ++i)
		{
			m -= i;
			b[k++] = i;
		}
		++i;
		++j;
	}
	printf("%d\n", k);
	for (int i = 0; i < k; ++i) printf("%d ", b[i]);
	return 0;
}