#include<bits/stdc++.h>
#define MAX 203
#define INF 1000000000000000LL
using namespace std;
typedef long long int ll;
int sz[MAX];
bool is_child[MAX];
ll memo[MAX][MAX];
ll val[MAX];
map<string, int>country;
vector<int>adj[MAX];
int n, m;
vector<int>top;
inline int top_sort(const int i){
	int my_size = 1;
	const vector<int> & v = adj[i];
	for (int j = 0; j < v.size(); ++j)
		my_size += top_sort(v[j]);
	top.push_back(i);
	return sz[i] = my_size;
}
inline void init(void){
	memset(memo, 0xFF, sizeof memo);
	memset(is_child, 0, sizeof is_child);
	top.clear();
	country.clear();
	for (int i = 0; i < MAX; ++i)
		adj[i].clear();
}
inline ll dp(const int i, const int j){
	if (j <= 0) return 0LL;
	if (i == -1) return INF;
	ll & ret = memo[i][j];
	if (ret != -1LL) return ret;
	return ret = min(val[i] + dp(i - sz[i], j - sz[i]), dp(i - 1, j));
}
char s[200];
const char space[3] = " \n";
inline int get_index(const char * c){
	string name(c);
	if (country.find(name) != country.end()) return country[name];
	int ans = country.size();
	return country[name] = ans;
}
inline void read(void){
	sscanf(s, "%d%d", &n, &m);
	for (int i = 0; i < n; ++i){
		fgets(s, INT_MAX, stdin);
		int counter = 0;
		int cur_country = 0;
		for (char * c = strtok(s, space); c; c = strtok(0, space), ++counter){
			if (counter == 0)cur_country = get_index(c);
			else if (counter == 1)sscanf(c, "%lld", val + cur_country);
			else {
				int k = get_index(c);
				adj[cur_country].push_back(k);
				is_child[k] = true;
			}
		}
	}
}
inline void top_sort(void){
	for (int i = 0; i < n; ++i)
		if (!is_child[i]) top_sort(i);
}
int main(void){
	while(fgets(s, INT_MAX, stdin), *s != '#'){
		init();
		read();
		top_sort();
		printf("%lld\n", dp(n - 1, m));
	}
	return 0;
}


