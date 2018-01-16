#include<bits/stdc++.h>
#define MAX (1 << 8)
using namespace std;
char s[MAX];
char stk[MAX];
int top;
inline char inverse(char t){
	return t == ')' ? '(' : '[';
}
inline bool correct(void){
	top = 0;
	for (char * c = s;; ++c){
		char t = *c;
		if (t == '\n') break;
		if (t == '(' || t == '[')
			stk[top++] = t;
		else if (!top || stk[--top] != inverse(t)) return false;
	}
	return !top;
}
int main(void){
	int TC; fgets(s, INT_MAX, stdin); sscanf(s, "%d", &TC);
	while(TC--){
		fgets(s, INT_MAX, stdin);
		printf("%s\n", correct() ? "Yes" : "No");
	}
	return 0;
}

