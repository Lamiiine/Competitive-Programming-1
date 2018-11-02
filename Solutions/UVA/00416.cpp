// a count-down sequence is not a decreasing subsequence
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int x[10];	// x stores the values from 9 to 0
int y[10];	// y stores input
int N;

bool valid(int j){	// is j a valid starting location in the given array?
	int burned = 0;
	for (int i = 0; i < N; i++){
		if ((y[i] | x[j + i]) != x[j + i]) return false;
		if (y[i] & burned) return false;
		burned |= (~y[i] & x[j+i]);
	}
	return true;
}

int func(string s){
	int x = 0;
	for (int i = 0; i < 7; i++) if (s[6 - i] == 'Y') x |= (1 << i);
	return x;
}

int main(){
	freopen("Input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
	string s;
	string strings[10] = { "YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY", "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY"};
	for (int i = 0; i < 10; i++)
		x[9-i] = func(strings[i]);
	bool flag;
	while (scanf("%d", &N), N){
		flag = false;
		for (int i = 0; i < N; i++) {
			cin >> s;
			y[i] = func(s);
		}
		for (int i = 0; i <= 10-N; i++) if (valid(i)) { printf("MATCH\n"); flag = true; break; }
		if (!flag) printf("MISMATCH\n");
	}
}