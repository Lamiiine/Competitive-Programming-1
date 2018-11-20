#include <stdio.h>
#include <limits.h>
#include <algorithm>
#define MAX 500005
using namespace std;
int n, k;
int lvl;
char s[MAX];
int memo[MAX][26];
int dp(int i, char a){	// minimum # changes required to normalize the string starting starting at i given that with s[i] = 'A' + a
	if (memo[i][a] != -1) return memo[i][a];
	if (i >= n) return memo[i][a] = 0;
	int ans = INT_MAX;
	for (int j = 0; j < k; ++j)
	if (j != a) ans = min(ans, dp(i + 1, j));
	return memo[i][a] = ans + (s[i] - 'A' != a);
}
void printPath(){
	int counter = 0;
	while (counter < n){
		int i = 0;
		for (;; i++){
			// You had a with this path-printing function
			if (dp(counter, i) == lvl)
			{
				// After checking that the dp function returns an appropriate value, check if it's compatiable with the value before
				if (counter > 0 && s[counter - 1] - 'A' == i) continue;
				if (s[counter] - 'A' != i)--lvl;
				s[counter] = 'A' + i;
				++counter;
				break;
			}
		}
	}
	printf("%s", s);
}
int main(){
	freopen("Input.txt", "r", stdin);
	memset(memo, 0xFF, sizeof memo);
	char c;
	scanf("%d%d%d", &n, &k, &c);
	scanf("%s", s);
	int ans = INT_MAX;
	for (int i = 0; i < k; ++i) ans = min(ans, dp(0, i));
	printf("%d\n", lvl = ans);
	printPath();
	return 0;
}