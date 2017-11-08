#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX 27
using namespace std;
long long memo[MAX][230];
char s[MAX];
long long dp(int i, int sum){
	if (memo[i][sum] != -1) return memo[i][sum];
	int cur = s[i];
	int j = i+1;	// j should start from i + 1, not from i
	while (cur < sum && s[j] != 'z') cur += s[j++];
	if (s[j] == 'z') return memo[i][sum] = (sum <= cur) ? 1 : 0;
	long long ans = 1;
	// I don't understand this!!!!!!!!!!!!!!! Why is ans initialized to 1?????????
	// Now, I do. This is the one time when you simply take all the characters until the end of the string. You are not considering this case in the following loop
	while (s[j] != 'z'){
		ans += dp(j, cur);
		cur += s[j++];
	}
	return memo[i][sum] = ans;
}
int main(){
	freopen("Input.txt", "r", stdin);
	int counter = 0;
	while (memset(s, 0, sizeof s), scanf("%s", s), s[0] != 'b'){
		int i = 0;
		while (s[i]) s[i++] -= '0';	// this will confuse the digit 0 with the null character
		while (i < MAX) s[i++] = 'z';
		memset(memo, 0xFF, sizeof memo);
		printf("%d. %lld\n", ++counter, dp(0, 0));
	}
	return 0;
}