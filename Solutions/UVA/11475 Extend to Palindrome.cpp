#include<bits/stdc++.h>
#define MAX 100010
using namespace std;
char s[MAX];
char r[MAX];
int f[MAX];
int n;
inline int get_f(int i, char c){
	while(i && c != r[i])
		i = f[i - 1];
	if (c == r[i]) ++i;
	return i;
}
inline void preprocess(void){
	reverse_copy(s, s + n, r);
	r[n] = 0;
	f[0] = 0;
	for (int i = 1; i < n; ++i)
		f[i] = get_f(f[i-1], r[i]);
}
int longest_suffix_palindrome(){
	for (int i = 0, j = 0; i < n; ++i)
	{
		j = get_f(j, s[i]);
		int k = i + j;
		if (k == n) return (j << 1) - 1;
		if (k == n-1) return (j << 1);
		if (k == n-2) return (j << 1) + 1;
	}
	return 0;
}
int main(void){
	while(scanf("%s", s) != EOF){
		n = strlen(s);
		preprocess();
		int ans = longest_suffix_palindrome();
		printf("%s%s\n", s, r + ans);
	}
	return 0;
}

