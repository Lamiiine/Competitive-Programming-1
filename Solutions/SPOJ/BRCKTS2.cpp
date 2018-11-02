#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define MAX 350010
using namespace std;
typedef long long int ll;
// root is zero
int p[MAX >> 1];
int head[MAX >> 1];
int nxt[MAX >> 1];
// YOU shifted right 2 bits instead of 1
int to[MAX >> 1];
int en;
int counter;
inline void addEdge(const int x, const int y){
	nxt[en] = head[x];
	head[x] = en;
	to[en++] = y;
}
/*
inline int height(const int i){
	int ans = 1;
	int Max = 0;
	for (int j = head[i]; j != -1; j = nxt[j]) Max = max(Max, height(to[j]));
	return ans + Max;
}
inline int width(const int i){
	int ans = 1;
	for (int j = head[i]; j != -1; j = nxt[j])
		ans += (width(to[j]) + 1);
	return ans;
}
*/

// return value is area of this child
// also, it passes back height and width of child in the given variables
inline ll area(const int i, ll & h, ll &w){
	if (head[i] == -1) return w = h = 1;
	ll tempW, tempH;
	ll myW = 1, myH = 1;
	ll ans = 0;	// summation of areas of children
	for (int j = head[i]; j != -1; j = nxt[j])
	{
		ans += area(to[j], tempH, tempW);
		myH = max(myH, tempH);
		myW += (tempW + 1);
	}
	return (w = myW)*(h = myH + 1) - ans;
}
void init(){
	en = counter = 0;
	memset(head, 0xFF, sizeof head);
}
/*void dfs(const int i){
	printf("%d:", i);
	for (int j = head[i]; j != -1; j = nxt[j]) printf(" %d", to[j]);
	printf("\n");
	for (int j = head[i]; j != -1; j = nxt[j]) dfs(to[j]);
}*/
int main() {
	freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	char s[MAX];
	while (TC--){
		init();
		scanf("%s", s);
		int cur = 0;
		char c; int i;
		for (c = s[i = 0]; c; c = s[++i]){
			if (c == '('){
				addEdge(cur, ++counter);
				p[counter] = cur;
				cur = counter;
			}
			else {
				cur = p[cur];
			}
		}
		// YOU SHOULD USE long long
		ll ans = 0, x, y;
		for (int j = head[0]; j != -1; j = nxt[j]) ans += area(to[j], x, y);
		printf("%lld\n", ans);
	}
	return 0;
}
