#include<stdio.h>
#include<string.h>
#define MAX 10001
using namespace std;
typedef signed short int s;
s adj[MAX];	// 10KB
s n, w;
void read(){
	memset(adj, 0, sizeof adj);
	s a[MAX], b[MAX];
	for (s i = 0; i < n; ++i)
		scanf("%hd", a + i);
	for (s i = 0; i < n; ++i)
		scanf("%hd", b + i);
	for (s i = 0; i < n; i += 2)
	{
		if (a[i] + a[(i + 1)%n] <= w) adj[i] |= 1;
		if (a[i] + a[(i - 1 + n)%n] <= w) adj[i] |= 2;
		if (a[i] + b[i] <= w) adj[i] |= 4;
	}
	for (s i = 1; i < n; i += 2)
	{
		if (b[i] + b[(i + 1)%n] <= w) adj[i] |= 1;
		if (b[i] + b[(i - 1 + n)%n] <= w) adj[i] |= 2;
		if (b[i] + a[i] <= w) adj[i] |= 4;
	}
}
s neighbor(const s i, const s j){
	switch(j){
	case 0: return (i + 1)%n;
	case 1: return (i - 1 + n)%n;
	case 2: return i;
	}
	return 0;
}
s match[MAX];	// 20KB
bool vis[MAX];	// 10KB - my visitation array
bool aug(s x){
	if (vis[x]) return 0;
	vis[x] = 1;
	for (char j = 0; j < 3; ++j){
		if (!(adj[x] & (1 << j))) continue;
		s y = neighbor(x, j);
		s k = match[y];
		if (k == -1 || aug(k)){
			match[y] = x;
			return 1;
		}
	}
	return 0;
}
int solve(){
	memset(match, 0xFF, sizeof match);
	int ans = 0;
	for (int i = 0; i < n; ++i)
		memset(vis, 0, sizeof vis), ans += aug(i);
	return ans;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%hd%hd", &n, &w), n || w){
		read();
		// for (int i = 0; i < n; ++i) printf("%hd\n", adj[i]);
		printf("%hd\n", (n << 1) - solve());
	}
	return 0;
}
