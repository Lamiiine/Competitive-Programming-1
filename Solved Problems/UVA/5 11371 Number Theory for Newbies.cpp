#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char s[15];
char r[15];
bool reverse_cmp(const char a, const char b){
	return b < a;
}
inline void normalize(void){
	char * c = r;
	while(*c == '0') ++c;
	if (c != r) swap(*r, *c);
}
ll diff(){
	ll x, y;
	sscanf(s, "%lld", &x);	// larger
	sscanf(r, "%lld", &y);	// smaller
	return x - y;
}
int main(void){
	while(scanf("%s", s) != EOF){
		int n = strlen(s);
		sort(s, s + n, reverse_cmp);
		reverse_copy(s, s + n, r);r[n] = 0;
		normalize();
		ll k = diff();
		printf("%s - %s = %lld = 9 * %lld\n", s, r, k, k/9);
	}
	return 0;
}

