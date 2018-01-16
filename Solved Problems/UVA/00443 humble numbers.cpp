#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAX 2000000000LL
using namespace std;
typedef long long int ll;
vector<int> ans;
void init(void){
	ans.reserve(5843);
	for (ll i = 1; i <= MAX; i *= 2LL)
		for (ll j = i; j <= MAX; j *= 3LL)
			for (ll k = j; k <= MAX; k *= 5LL)
				for (ll l = k; l <= MAX; l *= 7LL)
					ans.push_back((int)l);
	sort(ans.begin(), ans.end());
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	init();
	int x;
	while(scanf("%d", &x), x)
		printf("The %d%s humble number is %d.\n", x, x % 100 >= 11 && x % 100 <= 13 ? "th" : x % 10 == 1 ? "st" : x % 10 == 2? "nd" : x % 10 == 3 ? "rd" : "th", ans[x - 1]);
	return 0;
}

