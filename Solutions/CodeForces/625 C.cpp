#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	int val1 = n*n + 1, val2 = n - k + 1;
	printf("%d\n", n*(val1)-(val2)*(n*(n + 1)) / 2);
	int counter = 1, count = 1, counting;
	int x, y;
	for (int i = 0; i < n; i++){
		counting = 1;
		for (int j = 1; j < k; j++){
			printf("%d ", counter++); counting++;
		}
		y = val1 - count++*(val2);
		if (counting == n) { printf("%d", y); counting++; }
		else { printf("%d ", y); counting++; }
		for (int j = 1; j <= n-k; j++){
			if (counting == n){ printf("%d", y + j); counting++; }
			else { printf("%d ", y + j); counting++; }
		}
		printf("\n");
	}
}