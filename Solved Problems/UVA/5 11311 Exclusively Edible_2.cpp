#include<bits/stdc++.h>
using namespace std;
inline bool win(const int a, const int b, const int c, const int d){
	return a ^ b ^ c ^ d;
}
int main(void){
	int TC; scanf("%d", &TC);
	for(int m, n, r, c; TC--; printf("%s\n", win(r, c, m - 1 - r, n - 1 - c) ? "Gretel" : "Hansel"))
		scanf("%d%d%d%d", &m, &n, &r, &c);
}

