// YOU SHOULD NOT COPY THE PATH-PRINTING FUNCTION FROM THE DP FUNCTION! IT DOESN'T ALWAYS WORK!
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 1000000000000000
#define MAX 505
using namespace std;
typedef long long ll;
int p[MAX];
int k, m;
ll memo[MAX][MAX];
/* starting at index i and onward, what is the minimum maximum
* number of pages that could be assigned to a scriber
* by dividing the remaining work among j scribers
*/
ll dp(int i, int j){
	if (memo[i][j] != -1) return memo[i][j];	// previously-visited state
	if (m - i < j) return memo[i][j] = INF;		// not enough books left
	ll ans = INF, acc = 0;
	// ans will be returned
	// acc stores accumulated sum
	// find the last index you will assign to this scriber
	for (int k = i; k <= m - j && acc < ans; ++k){
		// we break loop once k exceeds m - j, because this will leave too few books for the remaining scribers
		// we also break loop once the value of 'acc' exceeds that of 'ans', because we know 'ans' will never attain a smaller value afterwards
		acc += p[k];	// if scribe i keeps book k for himself as well?
		ans = min(ans, max(acc, dp(k + 1, j - 1)));
	}
	return memo[i][j] = ans;
}
void init(void){
	memset(memo, 0xFF, sizeof memo);
	ll acc = 0;
	for (int i = m - 1; i >= 0; --i){
		// if you have only one scriber left...
		acc += p[i];
		memo[i][1] = acc;
		memo[i][0] = INF;
		memo[m][i] = INF;
	}
	memo[m][0] = 0;
}
ll answer;
void print(int i, int j){
	// print the books copied by j scribers
	// knowing that the first of them starts at index i
	if (j == 1){
		if (j != k)printf(" / ");
		for (int k = i; k < m; ++k)
			printf("%d%c", p[k], " \n"[k == m-1]);
		return;
	}
	// unless you are the first scriber ever, print a separation sign
	if (j != k)printf(" / ");
	printf("%d", p[i]);
	int ind = i;
	ll acc = 0;
	for (int k = i;; ++k){
		acc += p[k];
		if (max(acc, dp(k + 1, j - 1)) <= answer){
			ind = k; break;
		}
	}
	// you have taken up to ind
	for (int k = i + 1; k <= ind; ++k)
		printf(" %d", p[k]);
	print(ind + 1, j - 1);
}
int main(void){
	int TC;
	scanf("%d", &TC);
	while (TC--){
		// YOU CALLED 'init()' BEFORE READING INPUT!!!!!!!!!!!!!!!!!!!
		// YOU EVEN USED A DEBUGGER TO FIND THIS BUG!!!!!!!!!!!!!!!!!!
		scanf("%d%d", &m, &k);
		for (int i = 0; i < m; ++i)
			scanf("%d", p + i);
		init();
		// printf("ans = %lld\n", dp(0, k));
		answer = dp(0, k);
		print(0, k);
	}
	return 0;
}

