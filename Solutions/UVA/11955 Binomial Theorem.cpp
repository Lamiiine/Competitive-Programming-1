#include<stdio.h>
#include<string.h>
#define MAX 55
using namespace std;
typedef long long int ll;
ll memo[MAX][MAX];
inline void init(void) {
	const int upper_bound = 50;
	for (int i = 0; i <= upper_bound; ++i)
		memo[i][i] = memo[i][0] = 1;
	for (int i = 1; i <= upper_bound; ++i)
		for (int j = 1; j < i; ++j)
			memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	init();
	int TC;
	scanf("%d", &TC);
	char s[110];
	char a[100], b[100];
	int k;
	for (int tc = 1; tc <= TC; ++tc) {
		printf("Case %d: ", tc);
		scanf("%s", s);
		int i = 1, j = 0;
		while (s[i] != '+')
			a[j++] = s[i++];
		a[j] = 0;
		++i;
		j = 0;
		while (s[i] != ')')
			b[j++] = s[i++];
		b[j] = 0;
		i += 2;
		sscanf(s + i, "%d", &k);
		char temp[100];
		printf("%s", a);
		if (k != 1) printf("^%d", k);
		printf("+");
		for (int i = 1; i < k; ++i){
			if (memo[k][i] != 1LL)printf("%lld*", memo[k][i]);
			printf("%s", a);
			if (k - i != 1) printf("^%d", k- i);
			printf("*%s", b);
			if (i != 1) printf("^%d", i);
			printf("+");
		}
		printf("%s", b);
		if (k != 1) printf("^%d", k);
		printf("\n");
	}
	return 0;
}

