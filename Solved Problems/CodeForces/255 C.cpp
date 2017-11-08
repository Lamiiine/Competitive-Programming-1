// vectors are nice; they are not very slow;
// integer includes zero
#include <stdio.h>
#include <vector>
#include <string.h>
#include <set>
#include <algorithm>
#define MAX 4005
using namespace std;
vector<int> v[1000005];
int dp(int x, int y){
	int i = 0;
	int j = 0;
	int last = -1;
	int counter = 0;
	bool flag = true;
	while (flag){
		for (; flag = (i < v[x].size()); ++i){
			if (v[x][i] > last) {
				++counter;
				last = v[x][i];
				++i;	// don't forget to add i++ when you break before incrementing and you actually want to increment
				break;	// also, don't forget to write it before break;
			}
		}
		// if (i >= v[x].size()) return counter;	// this flag is needed so you won't continue after reaching the end
		// this flag is wrong because you might increment before reaching the end
		swap(x, y);
		swap(i, j);
	}
	return counter;
}
int main(){
	// freopen("Input.txt", "r", stdin);
	int n;
	set<int> s;
	scanf("%d", &n);
	if (n == 1){ printf("1"); return 0; }
	int x;
	for (int i = 0; i < n; ++i){
		scanf("%d", &x);
		v[x].push_back(i);
		s.insert(x);
	}
	int ans = 2;
	for (auto iter1 = s.begin(); iter1 != s.end(); ++iter1)
	for (auto iter2 = s.begin(); iter2 != s.end(); ++iter2){
		ans = max(ans, dp(*iter1, *iter2));	// don't skip (iter1 == iter2)
		// saying two values differ by an integer includes when that integer is zero
	}
	printf("%d", ans);
	return 0;
}