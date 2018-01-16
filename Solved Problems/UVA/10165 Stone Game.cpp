#include<bits/stdc++.h>
using namespace std;
int main(void){
	for (int n; scanf("%d", &n), n; ){
		int ans = 0;
		for(int x; n--;){
			scanf("%d", &x);
			ans ^= x;
		}
		printf("%s\n", ans ? "Yes" : "No");
	}
	return 0;
}

