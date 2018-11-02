#include<bits/stdc++.h>
using namespace std;
inline bool valid(int l, int c, int r){
	r <<= 1;
	return l >= r && c >= r;
}
inline int sqrdst(int dx, int dy){
	return dx*dx + dy*dy;
}
int main(void){
	for (int l, c, r1, r2; scanf("%d%d%d%d", &l, &c, &r1, &r2), l | c | r1 | r2;){
		int sum = r1 + r2;
		bool flag =valid(l, c, r1) && valid(l, c, r2) && sqrdst(l - sum, c - sum) >= sum*sum;
		printf("%c\n", flag ? 'S' : 'N');
	}
	return 0;
}

