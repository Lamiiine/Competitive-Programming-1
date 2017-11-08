#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long int ll;
char a[MAX], b[MAX];
int val(char c){
	return isdigit(c) ? c - '0' : 10 + c - 'A';
}
ll parse(char * s, ll base){
	ll ans = 0;
	for (;*s; ++s)
		ans = ans*base + val(*s);
	return ans;
}
int base_a, base_b;
inline bool solve(){
	int min_a = 2, min_b = 2;
	for (char * s = a; *s; ++s)
		min_a = max(min_a, val(*s) + 1);
	for (char * s = b; *s; ++s)
		min_b = max(min_b, val(*s) + 1);
	for (int i = min_a; i <= 36; ++i)
		for (int j = min_b; j <= 36; ++j)
			if (parse(a, i) == parse(b, j)){
				base_a = i, base_b = j;
				return true;
			}
	return false;
}
int main(void){
	while(scanf("%s%s", a, b) != EOF){
		if (solve())
			printf("%s (base %d) = %s (base %d)\n", a, base_a, b, base_b);
		else printf("%s is not equal to %s in any base 2..36\n", a, b);
	}
	return 0;
}

