#include <stdio.h>
#include <algorithm>

using namespace std;

int p, x[21];
bool find(int y, int i){	// start looking at y from index i and backward
	if (y == 0) return true;
	if (y < 0) return false;
	while (x[i] > y && i >= 0) i--;
	if (i < 0) return false;
	for (int j = i; j >= 0; j--)
	if (find(y-x[j], j-1)) return true;
	return false;
}
int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int TC;
	scanf("%d", &TC);
	int n;
	int total;
	while (TC--){
		scanf("%d%d", &n, &p);
		total = 0;
		for (int i = 0; i < p; i++)
			scanf("%d", &x[i]), total += x[i];
		sort(x, x + p);
		if (find(total - n, p-1)) printf("YES\n"); else printf("NO\n");
	}
}