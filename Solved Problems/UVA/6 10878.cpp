#include<stdio.h>
#include<iostream>
using namespace std;
string s;
int main(){
	// freopen("Input.txt", "r", stdin);
	getline(cin, s);
	char c = s[0];
	while(getline(cin, s), s != ""){
		if (s[0] == c) break;
		char d = 0;
		int counter = 7;
		int i = 1;
		while(counter >= 0){
			if (s[i] != ' ' && s[i] != 'o') {++i; continue;}
			d |= (int(s[i++] == 'o')) << counter--;
		}
		printf("%c", d);
	}
	return 0;
}

