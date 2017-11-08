// YOU HAD INDEXING PROBLEMS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define MAX 20
using namespace std;
typedef long long ll;
int n;
char s[MAX];
inline int index(char s) {
	// YOU WROTE '10' INSTEAD OF 9
	return isdigit(s) ? s - '1' : 9 + s - 'A';
}
// given that the position of the previous queen is j, count number of ways of placing queen i
ll memo[MAX][MAX];
int main(void) {
	// freopen("Input.txt", "r", stdin);
	while (scanf("%s", s) != EOF) {
		memset(memo, 0, sizeof memo);
		n = strlen(s);
		for (int i = 0; i < n; ++i) {
			char temp = s[i];
			if (temp != '?') {
				int pos = index(temp);
				if (!i)
					memo[i][pos] = 1LL;
				else {
					ll& ref = memo[i][pos];
					for (int j = 0; j < n; ++j)
						if (abs(j - pos) > 1)
							ref += memo[i - 1][j];
				}
			} else {
				if (!i)
					for (int j = 0; j < n; ++j)
						memo[0][j] = 1LL;
				else {
					for (int k = 0; k < n; ++k) {
						ll & ref = memo[i][k];
						for (int j = 0; j < n; ++j)
							if (abs(k - j) > 1)
								ref += memo[i - 1][j];
					}
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			ans += memo[n - 1][i];
		printf("%lld\n", ans);
	}
	return 0;
}

