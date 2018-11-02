#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	char s[300000 + 5];
	long long n = 0;
	scanf("%s", s);
	for (int i = 1; s[i] != '\0'; i++){
		if (!(s[i]-48 & 3))
			n++;
		if (!(((s[i-1] - 48)*10 + (s[i] - 48) )&3))
			n += i;
	}
	if (!(s[0]&3))n++;
	cout << n;
	return 0;
}