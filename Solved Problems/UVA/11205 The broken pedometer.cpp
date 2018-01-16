#include<stdio.h>
#include<string.h>
#include<limits.h>
#define MAX 105
#include<algorithm>
#define LSOne(s) (s & (-s))
using namespace std;
int p, n;
inline int count_ones(int i){
	int ans = 0;
	while(i)
		++ans, i -= LSOne(i);
	return ans;
}
int a[MAX];
int temp_a[MAX];
inline void init(void){
	memset(a, 0, sizeof a);
}
bool valid(int mask){
	memcpy(temp_a, a, sizeof a);
	for (int i = 0; i < n; ++i)
		temp_a[i] &= mask;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (temp_a[i] == temp_a[j]) return false;
	return true;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	while(TC--){
		init();
		scanf("%d%d", &p, &n);
		for (int i = 0; i < n; ++i){
			int temp = 0; int flag;
			for (int j = 0; j < p; ++j){
				scanf("%d", &flag);
				if (flag) temp |= (1 << j);
			}
			a[i] = temp;
		}
		int ans = INT_MAX;
		for (int i = 0; i < (1 << p); ++i)
			if (valid(i)) ans = min(ans, count_ones(i));
		printf("%d\n", ans);
	}
}

