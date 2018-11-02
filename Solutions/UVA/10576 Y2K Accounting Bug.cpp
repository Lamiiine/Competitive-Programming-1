#include<stdio.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int s, d;
int gain[12];
int sum(){
	int ans = 0;
	for (int i = 0; i < 12; ++i)
		ans += gain[i];
	return ans;
}
int sum(int i){
	int ans = 0, counter = 0;
	for (int j = i; counter < 5; --j, ++counter)
		ans += gain[j];
	return ans;
}
int recurse(int i){
	if (i == 12) return sum();
	gain[i] = d;	// post a deficit
	int temp = sum(i);
	if (temp >= 0) return INT_MIN;
	int ans = recurse(i + 1);
	gain[i] = s;	// post a surplus
	temp = sum(i);
	if (temp >= 0) return ans;
	return max(ans, recurse(i + 1));
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d%d", &s, &d) != EOF){
		d = -d;
		int ans = INT_MIN;
		for (int i = 0; i < 16; ++i){
			// generate the first four months
			int temp = i;
			for (int j = 0; j < 4; ++j){
				if (temp & 1)gain[j] = s;
				else gain[j] = d;
				temp >>= 1;
			}
			ans = max(ans, recurse(4));
		}
		if (ans < 0) printf("Deficit\n");
		else printf("%d\n", ans);
	}
	return 0;
}

