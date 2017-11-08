#include<bits/stdc++.h>
#define MAX 400
using namespace std;
char *p; int m;
int *f;
// Memoize this function in case of TLE :P
int get_f(int i, char c) {
	/* What index should you start matching at if you have found
	 * characters in 's' matching p[0, i] and you find a c at the
	 * index in 's' which is supposed to match p[i + 1]?
	 * - Notice that it returns (i + 1) if (c == p[i])
	 */
	while (i && c != p[i])
		i = f[i - 1];
	if (c == p[i])
		++i;
	return i;
}
void preprocess(){
	f[0] = 0;	// failure at index 1 gets you back to 0
	for (int i = 1; i < m; ++i)
		f[i] = get_f(f[i - 1], p[i]);
}
void match(){
	int j = 0;
	int i = 0;
	for (char c; scanf("%c", &c), !isspace(c); ++i)
		if ((j = get_f(j, c)) == m)
			printf("%d\n", i - m + 1), j = f[j-1];
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d", &m) != EOF){
		p = new char[m + 5];
		f = new int[m + 5];
		scanf("%s", p);
		{char c; scanf("%c", &c);}
		preprocess();
		match();
		printf("\n");
		delete p;
		delete f;
	}
	return 0;
}

