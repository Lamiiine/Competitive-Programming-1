#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
char s[1000];
inline ii get_int(char * s){
	char tmp[10];
	int len;
	int ans = 0;
	tmp[0] = s[0];
	for (len = 1;isdigit(s[len]); ++len)
		tmp[len] = s[len];
	tmp[len] = 0;
	sscanf(tmp, "%d", &ans);
	return ii(ans, len);	// parsed number & length
}
inline bool correct(void){
	char * c = s;
	ii x = get_int(c); c += x.second;
	bool addition = (*c == '+');
	ii y = get_int(++c); c += y.second;
	if (*c == '?') return false;
	ii z = get_int(++c);
	if (addition)return (x.first + y.first == z.first);
	return (x.first - y.first == z.first);
}
int main(void){
	int ans = 0;
	while(scanf("%s", s) != EOF)
		ans += correct();
	printf("%d\n", ans);
	return 0;
}

