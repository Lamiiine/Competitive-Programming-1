#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string>
#define MAX 10000005
using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
ii memo[MAX];
void init(void) {
	int counter = 1;
	int start = 1;
	for (int i = 1; counter < MAX; ++i) {
		if (start)
			for (int j = i; j >= 1 && counter < MAX; --j)
				memo[counter++] = ii(j, i - j + 1);
		else
			for (int j = 1; j <= i && counter < MAX; ++j)
				memo[counter++] = ii(j, i - j + 1);
		start ^= 1;
	}
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	init();
	int x;
	while(scanf("%d", &x) != EOF)
		printf("TERM %d IS %d/%d\n", x, memo[x].first, memo[x].second);
}

