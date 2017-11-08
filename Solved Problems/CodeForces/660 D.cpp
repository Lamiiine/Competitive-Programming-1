// VERY INTERESTING GEOMETRIC PROBLEM
#include<stdio.h>
#include<iostream>
#include<algorithm>
#define MAX 2005
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
ii p[MAX];
ii d[MAX*MAX];
int main(){
	// freopen("Input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	// 'n' BEING <= 3 IS A CORNER CASE
	if (n <= 3){
		printf("0"); return 0;
	}
	for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].first, &p[i].second);
	int counter = 0;
	for (int i = 0; i < n; ++i)
	for (int j = i + 1; j < n; ++j){
		int dx = p[j].first - p[i].first;
		int dy = p[j].second - p[i].second;
		if (dx < 0) dx = -dx, dy = -dy;
		d[counter++] = ii(dx, dy);
	}
	sort(d, d + counter);
	long long ans = 0;
	// YOU HAVE 'counter' PAIRS, NOT 'n' PAIRS
	for (int i = 0; i < counter;){
		int num = 0;
		while (d[i + num] == d[i] && num < counter) ++num;
		// if (num > 1) printf("%d: %d %d\n", num, d[i].first, d[i].second);
		ans += ll(ll(num)*ll(num - 1)) / 2LL;
		i += num;
	}
	cout << (ans >> 1);
	return 0;
}