#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <map>
using namespace std;
int main(){
	char p[80];
	// scanf("%s", p); // causes problems
	char d;
	for (int i = 0; i < 80; ++i) scanf("%c", &p[i]);
	scanf("%c", &d);	// skip
	map<int, int> M;
	int x;
	for (int i = 0; i < 10; ++i){
		x = 0;
		for (int j = 0; j < 10; ++j) {
			scanf("%c", &d);
			x += (d == '1') << j;
		}
		M[x] = i;
		scanf("%c", &d);	// skip
	}
	int answer = 0;
	int ten = 1e7;
	for (int i = 0; i < 8; ++i){
		x = 0;
		for (int j = 0; j < 10; ++j)
			x += (p[j + i*10] == '1') << j;
		answer += M[x]*ten;
		ten /= 10;
	}
	// a string is not an integer
	// printf("%d", answer);	// wrong when left most digit is zero
	cout << setfill('0') << setw(8) << answer;
	return 0;
}