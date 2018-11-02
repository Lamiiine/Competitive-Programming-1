#include <stdio.h>
#include <cstring>
#define N 5
using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int r[N], c[N];	// positions
	int  rCount[N], cCount[N], d1Count[2 * N], d2Count[2 * N];	// counters
	int rMin[N], cMin[N], rMax[N], cMax[N], d1Min[N*2], d2Min[N*2], d1Max[N*2], d2Max[N*2];
	int x, y;
	memset(rCount, 0, n*sizeof (int));
	memset(cCount, 0, n*sizeof (int));
	memset(d1Count, 0, 2*n*sizeof (int));
	memset(d2Count, 0, 2 * n*sizeof (int));
	memset(rMin, 0x7F, n*sizeof (int));
	memset(cMin, 0x7F, n*sizeof (int));
	memset(rMax, 0xFF, n*sizeof (int));
	memset(cMax, 0xFF, n*sizeof (int));
	memset(d1Min, 0x7F, 2 * n*sizeof (int));
	memset(d2Min, 0x7F, 2 * n*sizeof (int));
	memset(d1Max, 0xFF, 2 * n*sizeof (int));
	memset(d2Max, 0xFF, 2 * n*sizeof (int));

	for (int i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		x--; y--;
		r[i] = x;
		c[i] = y;
		rCount[x]++;
		cCount[y]++;
		d1Count[x + y]++;
		d2Count[x - y + n-1]++;
		if (rMin[x] > y) rMin[x] = y;
		if (rMax[x] < y) rMax[x] = y;
		if (cMin[y] > x) cMin[y] = x;
		if (cMax[y] < x) cMax[y] = x;
		if (d1Min[x + y] > x - y + n - 1) d1Min[x + y] = x - y + n - 1;
		if (d1Max[x + y] < x - y + n - 1) d1Max[x + y] = x - y + n - 1;
		if (d2Min[x - y + n - 1] > x + y) d2Min[x - y + n - 1] = x + y;
		if (d2Max[x - y + n - 1] < x + y) d2Max[x - y + n - 1] = x + y;
	}
	int num;
	int count[9];
	memset(count, 0, sizeof count);
	for (int i = 0; i < m; i++)
	{
		num = 0;
		if (rCount[r[i]] > 1) num += 2 - (rMin[r[i]] == c[i] || rMax[r[i]] == c[i]);
		if (cCount[c[i]] > 1) num += 2 - (cMin[c[i]] == r[i] || cMax[c[i]] == r[i]);
		if (d1Count[r[i] + c[i]] > 1) num += 2 - (d1Min[r[i] + c[i]] == r[i] - c[i] + n - 1 || d1Max[r[i] + c[i]] == r[i] - c[i] + n - 1);
		if (d2Count[r[i] - c[i] + n - 1] > 1) num += 2 - (d2Min[r[i] - c[i] + n - 1] == r[i] + c[i] || d2Max[r[i] - c[i] + n - 1] == r[i] + c[i]);
		count[num]++;
	}
	for (int i = 0; i < 9; i++) printf("%d ", count[i]);
	return 0;
}