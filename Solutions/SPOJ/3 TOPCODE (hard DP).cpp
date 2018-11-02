/* You have handled the corner case in the middle of the sentence
 * What if it occurs at the end?
 * */
#include<bits/stdc++.h>
#define MAX 105
#define INF 1000000
using namespace std;
int n;
char s[MAX];
int memo[MAX][MAX];
/* Maximum n umber of words starting at index j
 * knowing that the last word started at i
 * */
int dp(const int i, const int j){
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	int a , b;
	for (a = i, b = j; a < j && b < n && s[a] == s[b]; ++a, ++b);
	// failed to get a word in lexicographical order
	if (b == n || (a < j && s[a] > s[b]))
		/*
		 * The corner cases that got you WA are:
		 * - Ending a word with only one character left (You have handled this case in the middle, but not at the end)
		 * - comparing s[a] to s[b] without checking that a < j
		*/
		return ret = -INF;
	// k is a valid ending index of my current string which starts at j
	int ans = 0;
	// b has to make at least 2 steps ahead of j
	for (b = max(b + 1, j + 2);b < n; ++b)
		// n - 1 is not a valid starting index!
		// That's one way of handling the corner case at the end of the string
		ans = max(ans, dp(j, b));
	return ret = 1 + ans;
}
int count_memo[MAX][MAX];
int count_dp(const int i, const int j){
	int & ret = count_memo[i][j];
	if (ret != -1) return ret;
	const int level = dp(i, j) - 1;
	int a, b;
	for (a = i, b = j; a < j && b < n && s[a] == s[b]; ++a, ++b);
	if (b == n || (a < j && s[a] > s[b]))
		return ret = 0;
	int ans = 0;
	for (b = max(b + 1, j + 2); b <= n; ++b)
		if (dp(j, b) == level)
			ans += count_dp(j, b);
	return ret = ans;
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	memset(count_memo, 0xFF, sizeof count_memo);
	n = strlen(s);
	for (int i = 0; i < MAX; ++i){
		// It's a very good idea to handle corner cases in the init_memory() procedure
		// That is the other way of handling the corner case at the end of the string
		memo[i][n] = 0;
		memo[i][n-1] = -INF;
		count_memo[i][n] = 1;
		count_memo[i][n-1] = 0;
	}
}
inline void print(const int i, const int j){
	const int level = dp(i, j) - 1;
	int a, b;
	for (a = i, b = j; a < j && b < n && s[a] == s[b]; ++a, ++b);
	for (b = max(b + 1, j + 2);b <= n; ++b)
		if (dp(j, b) == level){
			const char temp = s[b];
			s[b] = 0;
			printf("%s", s + j);
			s[b] = temp;
			if (b == n){
				printf("\n");
			}
			else {
				printf(" ");
				print(j, b);
			}
			return;
		}
}
int main(void){
	string str;
	while(getline(cin, str), str.length() > 1){
		strcpy(s, str.c_str());
		init();
		printf("%d %d\n", dp(0, 0), count_dp(0, 0));
		print(0, 0);
	}
}

/*
hnqlvyrqsbjpgsvquflrzfbhxdkebiyjvqutomjhpuyvptojbzcaefhcisikcgvxzpqpdcwvwvqlqewrfyr
a
*/

