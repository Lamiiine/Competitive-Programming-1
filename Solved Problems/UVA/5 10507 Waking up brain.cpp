#include<bits/stdc++.h>
#define MAX 128
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n;
bool used[MAX];
bool wake[MAX];
bool conn[MAX][MAX];
int year_count;
inline void init(void){
	memset(conn, 0, sizeof conn);
	memset(used, 0, sizeof used);
	year_count = 0;
	memset(wake, 0, sizeof wake);
}
inline int wake_degree(int i){
	int ans = 0;
	for (int j = 0; j < MAX; ++j)
		ans += (used[j] && wake[j] && conn[i][j]);
	return ans;
}
int m;
inline void read(void){
	scanf("%d", &m);
	char s[10];
	scanf("%s", s);
	for (char * c = s; *c; ++c)
		wake[*c] = used[*c] = true;
	for (int i = 0; i < m; ++i){
		scanf("%s", s);
		int a = s[0], b = s[1];
		used[a] = used[b] = true;
		conn[a][b] = conn[b][a] = true;
	}
}
inline void simulate(void){
	for(vi to_wake;; to_wake.clear()){
		for (int i = 0; i < MAX; ++i)
			if (used[i] && !wake[i] && wake_degree(i) >= 3)
				to_wake.push_back(i);
		if (to_wake.empty()) break;
		++year_count;
		for (int i = 0; i < to_wake.size(); ++i)
			wake[to_wake[i]] = true;
	}
}
inline int used_count(void){
	int ans = 0;
	for (int i = 0; i < MAX; ++i)
		ans += used[i];
	return ans;
}
inline bool all_awake(void){
	for (int i = 0; i < MAX; ++i)
		if (used[i] && !wake[i]) return false;
	return true;
}
int main(void){
	while(scanf("%d", &n) != EOF){
		init();
		read();
		simulate();
		if (!all_awake() || used_count() != n) printf("THIS BRAIN NEVER WAKES UP\n");
		else printf("WAKE UP IN, %d, YEARS\n", year_count);
	}
	return 0;
}

