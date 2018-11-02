#include<bits/stdc++.h>
using namespace std;
int n;
int counter[4];
char s[5];
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		memset(counter, 0, sizeof counter);
		scanf("%d", &n);
		while(n--){
			scanf("%s", s);
			if (!strcmp(s, "aa")) ++counter[0];
			else if (!strcmp(s, "ab")) ++counter[1];
			else if (!strcmp(s, "ba")) ++counter[2];
			else ++counter[3];
		}
		int aa = counter[0] >> 1, ab = min(counter[1], counter[2]), bb = counter[3];
		for (int i = 0; i < aa; ++i) printf("aa");
		for (int i = 0; i < ab; ++i) printf("ab");
		if (counter[0] & 1){
			for (int i = 0; i < (bb >> 1); ++i) printf("bb");
			printf("aa");
			for (int i = 0; i < (bb >> 1); ++i) printf("bb");
		}
		else for (int i = 0; i < bb; ++i) printf("bb");
		for (int i = 0; i < ab; ++i) printf("ba");
		for (int i = 0; i < aa; ++i) printf("aa");
		// if (!ab && !bb && (counter[0] & 1)) printf("aa"); else if (bb == 1 && (counter[0] & 1)) printf("aa");
		printf("\n");
	}
	return 0;
}

