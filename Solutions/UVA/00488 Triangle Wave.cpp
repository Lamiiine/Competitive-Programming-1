#include<bits/stdc++.h>
using namespace std;
int main(void) {
	int TC;
	scanf("%d", &TC);
	for(int tc = 1; tc <= TC; ++tc) {
		int a, f;
		scanf("%d%d", &a, &f);
		for (int i = 1; i <= f; ++i) {
			for (int j = 1; j <= a; ++j) {
				for (int k = 0; k < j; ++k)
					printf("%d", j);
				printf("\n");
			}
			for (int j = a - 1; j > 0; --j) {
				for (int k = 0; k < j; ++k)
					printf("%d", j);
				printf("\n");
			}
			if (i != f || tc < TC)
				printf("\n");
		}
	}
	return 0;
}

