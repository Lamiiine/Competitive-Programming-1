#include<stdio.h>
#define MAX 105
using namespace std;
char s[MAX];
int n;
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		int ans = 0;
		scanf("%d%s", &n, s);
		for (int i = 0; i < n;){
			// you need to cover i
			if (s[i] == '#'){++i; continue;}
			// cover it with the one after
			++ans;
			i += 3;
		}
		printf("Case %d: %d\n", tc, ans);
	}
	return 0;
}

