#include<stdio.h>
#include<algorithm>
#define MAX 100005
using namespace std;
int x[MAX];
int n, c;
inline bool can(int dist){
	int end = x[0];
	int i = 0;
	for (int j = 0; j < c && i < n; ++j)
	{
		while (x[i] - end < dist && i < n) ++i;
		end = x[i];
	}
	return i < n;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while (TC--){
		scanf("%d%d", &n, &c);
		for (int i = 0; i < n; ++i)
			scanf("%d", x + i);
		// IF YOU NEED TO PLACE 'c' COWS, YOU WILL ALWAYS PLACE ONE AT INDEX '0'
		// DON'T FORGET TO DECREMENT 'c'
		--c;
		sort(x, x + n);
		x[n] = 0;
		int low = 0, high = 1000000000;
		while (low != high){
			int mid = max((low + high) >> 1, low + 1);
			if (can(mid))
				low = mid;
			else high = mid - 1;
		}
		printf("%d\n", low);
	}
}