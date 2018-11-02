// P4 - Aibohphobia
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

char s[6100];
int memo[6100][6100];
int str(int start, int end){
	if (memo[start][end] != -1) return memo[start][end];
	if (start == end) return memo[start][end] = 0;
	if (end - start == 1) return memo[start][end] = (s[start] != s[end]);
	if (s[start] == s[end]) return memo[start][end] = str(start + 1, end - 1);
	return memo[start][end] = 1 + min(str(start + 1, end), str(start, end - 1));
}
int main() {
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	int start = 0, end;
	int TC;
	scanf("%d\n", &TC);
	while (TC--){
		scanf("%s", s);
		end = start;
		while (s[end]) end++;
		for (int i = 0; i < end; i++)
		for (int j = i; j < end; j++) memo[i][j] = -1;
		end--;
		printf("%d\n", str(0, end));
	}
	return 0;
}