#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#define MAX 205	// maximum number of cars that could be loaded
using namespace std;
int car[MAX];
int acc[MAX];			// acc[i] = sum from 0 to i - 1
int counter, length;	// number of cars, length of my fairy
int ans;				// answer
int memo[MAX][10005];	// maximum number of cars
int dp(int i, int j){	// index of next car & occupied length in first lane
	if (memo[i][j] != -1) return memo[i][j];
	if (i >= counter) return memo[i][j] = 0;
	int k = acc[i] - j;	// occupied length in the other lane
	int next = car[i];
	int j_free = length - j, k_free = length - k;
	if (next <= j_free && next <= k_free)
		return memo[i][j] = 1 + max(dp(i+1, j + next), dp(i + 1, j));
	if (next <= j_free)	// you only have space in first lane
		return memo[i][j] = 1 + dp(i + 1, j + next);
	if (next <= k_free)	// you only have space in second lane
		return memo[i][j] = 1 + dp(i + 1, j);
	return memo[i][j] = 0;
}
void init(void){
	counter = 0;
	memset(memo, 0xFF, sizeof memo);
	acc[0] = 0;
}
// print locations of cars # i and onward
// knowing that you have occupied meters j in your first lane
void print(int i, int j){
	/* ans is a global variable that stores the total number of cars
	that could be loaded it this is the last car, just print */
	if (i == ans) return;
	// get occupied length in the other lane using the accumulation array
	int k = acc[i] - j;
	// get free length in each lane
	int j_free = length - j, k_free = length - k;
	// get length of current car
	int next = car[i];
	/* get the answer (maximum number of cars that could be loaded
	starting at i knowing that you have j meters occupied in 1st lane*/
	int temp = dp(i, j);
	/* loc = 0 if you pick first lane (j) for car # i,
	false if you pick second lane (k) for it */
	bool loc = 0;	// assume first lane
	// if you don't have enough space on your first lane, take second
	if (j_free < next) loc = 1;
	/* else, if you have enough space on your second lane, call the DP
	function to know if taking second lane would still get you the
	required number of cars (which is temp - 1) */
	else if (k_free >= next && dp(i + 1, j) == temp - 1) loc = 1;
	if (loc){	// if you choose second lane
		// print port for current car
		printf("port\n");
		// print locations of cars # (i + 1) and onward
		// knowing that you have occupied meters j in your first lane
		// you have used the second lane for this car, so j doesn't change
		print(i + 1, j); }
	else {		// if you choose first lane
		// print starboard for current car
		printf("starboard\n");
		// print locations of cars # (i + 1) and onward
		// knowing that you have occupied meters j + next in your first lane
		print(i + 1, j + next); }
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	bool first = true;
	while(TC--){
		if (!first) printf("\n");
		first = false;
		// ETERNAL ERROR; YOU FORGOT TO CALL 'init()'
		init();
		scanf("%d", &length);
		length *= 100;	// length of my fairy
		int x;
		while(scanf("%d", &x), x && counter < 202){
			car[counter++] = x;
			acc[counter] = x + acc[counter - 1];
		}
		if (x) while(scanf("%d", &x), x);
		printf("%d\n", ans = dp(0, 0));
		print(0, 0);
	}
	return 0;
}

