#include<bits/stdc++.h>
#define MAX 105
using namespace std;
char s[MAX][MAX];
int f[MAX][MAX];
int n;	// number of words
int k;	// length of each word
inline int get_f(int i, char c, char * str, int * fail){
	while(i && c != str[i])
		i = fail[i - 1];
	if (c == str[i]) ++i;
	return i;
}
inline void preprocess(void){
	for (int j = 0; j < n; ++j)
	{
		int * fail = f[j];
		char * str = s[j];
		fail[0] = 0;
		for (int i = 1; i < k; ++i)
			fail[i] = get_f(fail[i - 1], str[i], str, fail);
	}
}
inline void read_input(void){
	scanf("%d%d", &k, &n);
	for (int i = 0; i < n; ++i)
		scanf("%s", s[i]);
}
inline int solve(void){
	int ans = k;
	// the last string has to be all taken
	for (int j = n - 2; j >= 0; --j)
	{
		char * str = s[j], * ptrn = s[j + 1];
		int * fail = f[j + 1];
		// try to find the string after you in you
		int len = 0;
		for (int i = 0; i < k; ++i)
			len = get_f(len, str[i], ptrn, fail);
		ans += (k - len);
	}
	return ans;
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		read_input();
		preprocess();
		printf("%d\n", solve());
	}
	return 0;
}

