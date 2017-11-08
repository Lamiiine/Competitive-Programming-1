#include<bits/stdc++.h>
using namespace std;
char s[1010];
int n;
int sum;
int num;
inline void normalize(void){
	for (int i = 0; i < n; ++i)
		s[i] -= '0';
}
inline int get_sum(void){
	int ans = 0;
	for (int i = 0; i < n; ++i)
		ans += s[i];
	return ans;
}
inline int get_count_divisible_by_3(void){
	int ans = 0;
	for (char * c = s; *c; ++c)
		ans += (*c % 3 == 0);
	return ans;
}
inline bool can_make_first_move(void){
	int x = sum % 3;
	for (int i = 0; i < n; ++i)
		if (s[i] % 3 == x) return true;
	return false;
}
inline void read(void){
	scanf("%s", s);
	n = strlen(s);
	normalize();
	sum = get_sum();
	num = get_count_divisible_by_3();
}
int main(void){
	int TC; scanf("%d", &TC);
	for(int tc = 1; tc <= TC; ++tc){
		read();
		bool flag;
		if (!can_make_first_move())flag = false;
		else  if (sum % 3) flag = !(num & 1);
		else flag = num & 1;
		printf("Case %d: %c\n", tc, flag ? 'S' : 'T');
	}
	return 0;
}

