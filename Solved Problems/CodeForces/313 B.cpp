#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);

	char s[100005];
	scanf("%s", s);

	int num[100005];
	num[0] = 0;
	int i;
	for (i = 1; s[i]; i++){
		num[i] = num[i - 1] + (s[i] == s[i-1]);
	}
	int m, r, l;
	scanf("%d", &m);
	while (m--){
		scanf("%d%d", &l, &r);
		printf("%d\n", num[--r]-num[--l]);
	}
	return 0;
}