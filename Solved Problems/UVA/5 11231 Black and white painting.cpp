#include<bits/stdc++.h>
using namespace std;
inline int get_num(int n, int m)
{
	return max((n >> 1) - 3, 0) * max((m >> 1) - 3, 0);
}
inline int solve(int n, int m, int c){
	return c ? get_num(n, m) + get_num(n-1, m-1) : get_num(n, m - 1) + get_num(n - 1, m);
}
int main(void){
	for (int n, m, c; scanf("%d%d%d", &n, &m, &c), n || m || c; printf("%d\n", solve(n, m, c)));
	return 0;
}

