#include<bits/stdc++.h>
using namespace std;
inline bool win(int a, int b){
	if (!a || !b) return false;
	if (a < b) swap(a, b);
	// a should be greater than or equal to b
	for (int c = a % b; c < a; c += b)
		if (!win(c, b)) return true;
	return false;
}
int main(void){
	for (int x, y; scanf("%d%d", &x, &y), x || y; )
		printf("%s wins\n", win(x, y) ? "Stan" : "Ollie");
	return 0;
}

