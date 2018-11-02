#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <limits.h>
#define MAX 5005
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int n;
int w, h;
int counter;
iii seq[MAX];
short memo[MAX][MAX];	// use short instead of int to save some memory
short dp(int i, int j){	// your last choice was i; now you are at j;
	if (memo[i][j] != -1) return memo[i][j];
	if (j >= counter) return memo[i][j] = 0;
	if (seq[j].first == seq[i].first || seq[j].second.first <= seq[i].second.first) return memo[i][j] = dp(i, j+1);
	return memo[i][j] = max(short(1 + dp(j, j + 1)), dp(i, j+1));
}
int lvl;
void printPath(){
	int last = 0;
	int cur = 1;
	while (lvl){
		for (;;++cur)
		if (dp(last, cur) == lvl && dp(last, cur + 1) != lvl){
			last = cur;
			printf("%d", seq[cur].second.second);
			if (lvl != 1) printf(" ");
			--lvl;
			break;
		}
	}
}
int main(){
	freopen("Input.txt", "r", stdin);
	memset(memo, 0xFF, sizeof memo);
	scanf("%d%d%d", &n, &w, &h);
	counter = 0;
	seq[counter++] = iii(INT_MIN, ii(INT_MIN, INT_MIN));
	int x, y;
	for (int i = 1; i <= n; ++i){
		scanf("%d%d", &x, &y);
		if (x <= w || y <= h) continue;
		seq[counter++] = iii(x, ii(y, i));
	}	// we have a dummy element
	for (int i = 0; i <= counter; ++i) memo[i][counter] = 0;
	sort(seq, seq + counter);
	printf("%d\n", lvl = dp(0, 1));
	printPath();
	return 0;
}