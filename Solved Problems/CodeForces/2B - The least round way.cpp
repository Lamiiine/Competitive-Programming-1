#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<algorithm>
#include<map>
#define MAX 1005
using namespace std;
int memo_2[MAX][MAX];
int memo_5[MAX][MAX];
int count_2[MAX][MAX];
int count_5[MAX][MAX];
int n;
int dp_2(int i, int j) {
	if (memo_2[i][j] != -1) return memo_2[i][j];
	return memo_2[i][j] = count_2[i][j] + min(dp_2(i + 1, j), dp_2(i, j + 1));
}
int dp_5(int i, int j) {
	if (memo_5[i][j] != -1) return memo_5[i][j];
	return memo_5[i][j] = count_5[i][j] + min(dp_5(i + 1, j), dp_5(i, j + 1));
}
map<int, int> m;
int get_count_2(int x) {
	return m[(-x) & x];
}
int get_count_5(int x) {
	if (!x)
		return 0;	// no fives
	int ans = 0;
	while (!(x % 5))
		x /= 5, ++ans;
	return ans;
}
void init(void) {
	memset(memo_2, 0xFF, sizeof memo_2);
	memset(memo_5, 0xFF, sizeof memo_5);
	memo_2[n - 1][n - 1] = count_2[n - 1][n - 1];
	memo_5[n - 1][n - 1] = count_5[n - 1][n - 1];
	for (int i = 0; i <= n; ++i)
		memo_2[i][n] = memo_2[n][i] = memo_5[i][n] = memo_5[n][i] = 1000000000;
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	for (int i = 0; i < 32; ++i)
		m[1 << i] = i;
	scanf("%d", &n);
	int zi = -1, zj = -1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			int x;
			scanf("%d", &x);
			if (!x)
				zi = i, zj = j;
			count_2[i][j] = get_count_2(x);
			count_5[i][j] = get_count_5(x);
		}
	init();
	int ans_2 = dp_2(0, 0);
	int ans_5 = dp_5(0, 0);
	int ans = min(ans_2, ans_5);
	printf("%d\n", min(ans, zi != -1 ? 1 : INT_MAX));
	if (ans && zi != -1) {
		// take the path containing zero
		for (int i = 0; i < zi; ++i)
			printf("D");
		for (int j = 0; j < zj; ++j)
			printf("R");
		for (int i = zi; i < n - 1; ++i)
			printf("D");
		for (int j = zj; j < n - 1; ++j)
			printf("R");
		return 0;
	}
	n = (n - 1) << 1;
	int x = 0, y = 0;
	if (ans_2 < ans_5)
		// follow the 2's path
		while (n--) {
			int cur = dp_2(x, y) - count_2[x][y];
			if (dp_2(x + 1, y) == cur)
				++x, printf("D");
			else ++y, printf("R");
		}
	else
		// follow the 5's path
		while (n--) {
			int cur = dp_5(x, y) - count_5[x][y];
			if (dp_5(x + 1, y) == cur)
				++x, printf("D");
			else ++y, printf("R");
		}
	return 0;
}

