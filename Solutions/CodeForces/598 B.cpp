#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main(){
	string s, sub;
	cin >> s;
	int m;
	int l, r, k;
	scanf("%d\n", &m);
	m--;
	while (m--){
		scanf("%d %d %d\n", &l, &r, &k);
		l--;
		sub = s.substr(l, r - l);
		k %= sub.length();
		sub = sub.substr(sub.length() - k) + sub.substr(0, sub.length() - k);
		s.replace(l, r-l, sub);
	}
	scanf("%d %d %d", &l, &r, &k);
	l--;
	sub = s.substr(l, r - l);
	k %= sub.length();
	sub = sub.substr(sub.length() - k) + sub.substr(0, sub.length() - k);
	s.replace(l, r - l, sub);
	//
	cout << s;
	return 0;
}