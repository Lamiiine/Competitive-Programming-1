#include<bits/stdc++.h>
#define code 131071
using namespace std;
char s[100000];
int main(void){
	while(scanf("%s", s) != EOF){
		int len = strlen(s);
		while(s[len - 1] != '#')
			scanf("%s", s + len), len = strlen(s);
		int rem = 0;
		for (int pow = 1, i = len - 2; i >= 0; --i){
			if (s[i] == '1')
				rem = (rem + pow) % code;
			pow = (pow << 1)%code;
		}
		printf("%s\n", rem ? "NO" : "YES");
	}
	return 0;
}

