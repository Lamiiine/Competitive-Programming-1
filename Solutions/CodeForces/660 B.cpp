#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int mat[105][4];
bool occ[105][4];
int main(){
	// freopen("Input.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	memset(occ, 0, sizeof occ);
	// fill the matrix with passenger numbers
	int val = n << 1;
	for (int i = 0; i < n; ++i)
		mat[i][1] = (mat[i][0] = 1 + (i << 1)) + val;
	for (int i = 0; i < n; ++i)
		mat[i][2] = (mat[i][3] = (i+1) << 1) + val;
	// get people out
	int temp = m;
	for (int i = 0; i < min(temp >> 1, n); ++i) occ[i][0] = true;
	// WHEN YOU FIX A BUG, FIX IT EVERYWHERE
	if ((temp & 1)) occ[min(n-1, temp >> 1)][0] = true;
	for (int i = 0; i < min(temp >> 1, n); ++i) occ[i][3] = true;
	temp -= (n << 1);
	// DON'T SHIFT LEFT A NEGATIVE NUMBER!
	if (temp > 0){
		for (int i = 0; i < min(temp >> 1, n); ++i) occ[i][1] = true;
		if ((temp & 1)) occ[min(n-1, temp >> 1)][1] = true;
		for (int i = 0; i < min(temp >> 1, n); ++i) occ[i][2] = true;
	}
	int d[] = {1, 0, 2, 3};
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 4; ++j)
		if (occ[i][d[j]]) printf("%d ", mat[i][d[j]]);
	}
	return 0;
}

