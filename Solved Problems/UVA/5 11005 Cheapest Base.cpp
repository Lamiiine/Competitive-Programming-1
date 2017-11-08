#include<stdio.h>
#include<limits.h>
#include<vector>
using namespace std;
int cost[36];
int price(int x, int b){	// number and base
	int ans = 0;
	while (x){
		ans += cost[x % b];
		x /= b;
	}
	return ans;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	bool first = true;
	for (int tc = 1; tc <= TC; ++tc){
		if (!first) printf("\n");
		first = false;
		printf("Case %d:\n", tc);
		for (int i = 0; i < 36; ++i)
			scanf("%d", cost + i);
		int q, x;
		scanf("%d", &q);
		while (q--){
			scanf("%d", &x);
			vector<int>bases;
			int ans = INT_MAX;
			for (int i = 2; i <= 36; ++i)
			{
				int temp = price(x, i);
				if (temp < ans){
					ans = temp;
					bases.clear();
					bases.push_back(i);
				}
				else if (temp == ans)
					bases.push_back(i);
			}
			printf("Cheapest base(s) for number %d: %d", x, bases[0]);
			for (int i = 1; i < bases.size(); ++i)
				printf(" %d", bases[i]);
			printf("\n");
		}
	}
}