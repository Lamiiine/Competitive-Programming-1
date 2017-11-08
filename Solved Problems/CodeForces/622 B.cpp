#include <stdio.h>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int h, m, a;
	scanf("%d:%d\n%d", &h, &m, &a);
	h += (a / 60);
	m += (a % 60);
	h += (m >= 60);
	h %= 24;
	m %= 60;
	cout << setfill('0') << setw(2) << h << ':' << setw(2) << m;
	return 0;
}