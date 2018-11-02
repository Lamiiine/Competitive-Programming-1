#include<bits/stdc++.h>
#define MAX 1000005
using namespace std;
char p[MAX]; int m;	// pattern and its length
int f[MAX]; // what index should you start matching at if you fail at index (i + 1)?
int get_f(int i, char c) {
	/* What index should you start matching at if you have found
	 * characters in 's' matching p[0, i] and you find a c at the
	 * index in 's' which is supposed to match p[i + 1]?
	 * - Notice that it returns (i + 1) if (c == p[i])
	 * - Memorize this function if you get a TLE :P
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
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%s", p), strcmp(p, ".")){
		m = strlen(p);
		preprocess();
		printf("%d\n", m/(m - f[m-1]));
	}
	return 0;
}

