#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; scanf("%d", &t);
	while(t--){
		int n, m, x;
		scanf("%d %d %d", &n, &m, &x);
//		if(n % m == 0){
//			if(x == m){
//				printf("YES\n");
//			}
//			else{
//				printf("NO\n");
//			}
//		}
//		else{
//			if(x == n % m){
//				printf("YES\n");
//			}
//			else{
//				printf("NO\n");
//			}
//		}
		int winner = (n % m == 0) ? m : n % m;
		if(winner == x){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
}

