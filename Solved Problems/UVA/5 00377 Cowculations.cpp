#include<bits/stdc++.h>
using namespace std;
const char symbol[4] = {'V', 'U', 'C', 'D'};
int val[128];
inline void init_val(void){
	for (int i = 0; i < 4; ++i)
		val[symbol[i]] = i;
}
inline int parse(char * s){
	int ans = 0;
	for (char * c = s; *c; ++c)
		ans = (ans << 2) + val[*c];
	return ans;
}
char s[15];
int num1, num2;
inline void read(void){
	scanf("%s", s);
	num1 = parse(s);
	scanf("%s", s);
	num2 = parse(s);
}
inline void solve(void){
	for (int iter = 0; iter < 3; ++iter){
		scanf("%s", s);
		switch(*s){
		case 'A':
			num2 = num1 + num2;
			break;
		case 'R':
			num2 >>= 2;
			break;
		case 'L':
			num2 <<= 2;
			break;
		}
	}
}
int main(void){
	init_val();
	int TC; scanf("%d", &TC);
	printf("COWCULATIONS OUTPUT\n");
	while(TC--){
		read();
		solve();
		scanf("%s", s);
		printf("%s\n", num2 == parse(s) ? "YES" : "NO");
	}
	printf("END OF OUTPUT\n");
	return 0;
}

