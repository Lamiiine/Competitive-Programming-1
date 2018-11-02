#include<bits/stdc++.h>
#define MAX 150
using namespace std;
char a[150], b[150];
int n, m;
int memo[150][150];
inline int dp(int i, int j){
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	if (i == n || j == m) return ret = 0;
	if (a[i] == b[j])	// you can visit this city!
		return ret = 1 + dp(i + 1, j + 1);
	return ret = max(dp(i + 1, j), dp(i, j + 1));
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
}
inline bool read(char * s, int & len){
	fgets(s, INT_MAX, stdin);
	len = strlen(s);
	s[--len] = 0;
	return strcmp(s, "#");
}
inline bool read(void){
	if (!read(a, n)) return false;
	read(b, m);
	return true;
}
int main(void){
	for(int tc = 1; read(); ++tc)
		init(),
		printf("Case #%d: you can visit at most %d cities.\n", tc, dp(0, 0));
	return 0;
}

