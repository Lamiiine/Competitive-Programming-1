#include<stdio.h>
#include<string.h>
#define MAX 15
using namespace std;
char s[MAX];
char sub[MAX];
char ans[MAX];
int n;
void generate_sub(int x) {
	int counter = 0;
	for (int i = 0; i < n; ++i)
		// take character i
		if (x & (1 << i))
			sub[counter++] = s[i];
	sub[counter] = 0;
}
bool pal() {
	int i = 0, j = strlen(sub) - 1;
	while (i <= j) {
		if (sub[i] != sub[j])
			return false;
		++i;
		--j;
	}
	return true;
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	scanf("%s", s);
	n = strlen(s);
	ans[0] = 0;
	for (int i = 0; i < (1 << n); ++i) {
		generate_sub(i);
		if (!pal())
			continue;
		if (strcmp(ans, sub) < 0)
			strcpy(ans, sub);
	}
	printf("%s", ans);
	return 0;
}

