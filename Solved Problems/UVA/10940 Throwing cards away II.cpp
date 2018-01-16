#include <iostream>
using namespace std;
inline int f(int n){
	if (n == 1) return 0;
	bool odd = n & 1;
	int x = f((n >> 1) + odd);
	if (odd)
		return x ? (x << 1) - 1 : n - 1;
	return (x << 1) + 1;
}
int main() {
	for (int n; scanf("%d", &n), n; printf("%d\n", f(n) + 1));
	return 0;
}