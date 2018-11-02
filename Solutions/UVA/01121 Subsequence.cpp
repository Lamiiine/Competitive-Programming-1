#include<bits/stdc++.h>
using namespace std;
int n, s;
int arr[100100];
inline int solve(void){
	bool flag = false;
	int i = 0, j = 0, cur = 0;
	int ans = 1000000;
	while(j < n || cur >= s)
	{
		while(j < n && cur < s)
			cur += arr[j++];
		if (cur >= s){
			flag = true;
			ans = min(ans, j - i);
			cur -= arr[i++];
		}
	}
	return flag ? ans : 0;
}
int main(void){
	while(~scanf("%d%d", &n, &s)){
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		printf("%d\n", solve());
	}
}

