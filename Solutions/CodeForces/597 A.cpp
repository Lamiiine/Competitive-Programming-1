#include <iostream>
using namespace std;
int main(){
	long long k, a, b;
	cin >> k >> a >> b;
	if (a>0 && a%k)a = a / k + 1;
	else a /= k;
	if (b<0 && b%k) b = b/ k - 1;
	else b /= k;
	cout << b-a+1;
	return 0;
}