#include<stdio.h>
#include<string.h>
#define MAX 85
using namespace std;
char s[8][MAX];
char ans[MAX];
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	char c;
	scanf("%c", &c);	// ignore \n
	while(TC--){
		scanf("%s", s[0]);	// ignore first line
		for (int i = 0; i < 8; ++i) scanf("%s", s[i]);
		int len = strlen(s[0]) - 2;
		memset(ans, 0, sizeof ans);
		for (int i = 0; i < 8; ++i)
			for (int j = 1; j <= len; ++j)
				ans[j-1] |= (int(s[i][j] == '\\')) << i;		// char j-1
		printf("%s\n", ans);
		scanf("%s", s[0]);		// ignore last line
		scanf("%c%c", &c, &c);	// ignore 2 \n
	}
	return 0;
}

