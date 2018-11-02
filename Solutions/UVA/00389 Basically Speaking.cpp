#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
typedef long long int ll;
char a[MAX];
int char_to_int(char c){
	return isdigit(c) ? c - '0' : 10 + c - 'A';
}
char int_to_char(int x){
	if (x < 10) return x + '0';
	return x - 10 + 'A';
}
bool successful_parsing;
ll parse(char * s, ll base){
	successful_parsing = true;
	ll ans = 0;
	for (;*s; ++s){
		ans = ans*base + char_to_int(*s);
		if ((ll) ans > INT_MAX) {successful_parsing = false; break;}
	}
	return ans;
}
string convert(ll num, ll base){
	if (!num) return "0";
	string ans("");
	for(;num;num /= base){
		ans = string(1, int_to_char(num % base)) + ans;
	}
	return ans;
}
int main(void){
	for(int from, to; scanf("%s%d%d", a, &from, &to) != EOF;){
		ll num = parse(a, from);
		string ans = convert(num, to);
		printf("%7s\n", ans.size() > 7 || !successful_parsing ? "ERROR" : ans.c_str());
	}
	return 0;
}

