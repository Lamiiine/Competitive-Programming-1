#include<stdio.h>
#include<set>
#define MAX 500005
using namespace std;
int counter[1000005] = {0};
typedef long long ll;
int a[MAX];
int n, k;
int main(void){
	// freopen("Input.txt", "r", stdin);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	int ans_i = 0, ans_j = 0, ans = 0;
	set<int>cur;
	for (int i = 0, j = 0;j < n; ++j){
		int temp = a[j];
		counter[temp]++;
		cur.insert(temp);
		if (cur.size() > k){
			// if you exceed the allowed number of differences, fix it
			while(1){
				if (!--counter[temp = a[i++]]){
					cur.erase(temp);
					break;
				}
			}
		}
		if (ans < j - i)
			ans_i = i, ans_j = j, ans = j-i;
	}
	printf("%d %d", ans_i + 1, ans_j + 1);
	return 0;
}

