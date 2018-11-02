#include <iostream>
#include <string.h>

using namespace std;

int main(){
	long long n;
	cin >> n;
	long long i = 1;
	while (i*(i+1LL)/2LL < n) i++;
	i--;
	cout << n - i*(i + 1LL) / 2LL;
	return 0;
}