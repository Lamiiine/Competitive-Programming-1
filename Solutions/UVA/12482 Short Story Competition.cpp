#include<stdio.h>
#include<string.h>
#define MAX 1005
using namespace std;
int a[MAX];
int n, l, c;
int main(void){
	// freopen("Input.txt", "r", stdin);
	char s[75];
	while(scanf("%d%d%d", &n, &l, &c) != EOF){
		for (int i = 0; i < n; ++i)
			scanf("%s", s), a[i] = strlen(s);
		int ans = 0;
		for (int i = 0; i < n;){
			++ans;	// take an extra line!
			int temp = c;
			while(temp >= a[i])temp -= (a[i++] + 1);
		}
		printf("%d\n", (ans + l - 1)/l);	// number of pages
	}
	return 0;
}

