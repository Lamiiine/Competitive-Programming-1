#include<bits/stdc++.h>
#define MAX 105
#define avg(a, b) ((a + b) >> 1)
using namespace std;
typedef pair<int, int> ii;
int n, m;
char s[MAX][55];	// for printing
char tmp[MAX][55];	// for sorting
int inv_ind[55];
inline void read(void){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%s", s[i]);
	memcpy(tmp, s, sizeof s);
}
inline int merge_sort(char * c, int l, int r){
	if (l == r) return 0;
	int m = avg(l, r);
	int inversion_index = merge_sort(c, l, m) + merge_sort(c, m + 1, r);
	vector<char>v;
	v.reserve(r - l + 1);
	int j = l, k = m + 1;
	while(j <= m && k <= r)
		if (c[j] <= c[k]) v.push_back(c[j++]);
		else inversion_index += (m - j + 1), v.push_back(c[k++]);
	while (j <= m)
		v.push_back(c[j++]);
	while(k <= r)
		v.push_back(c[k++]);
	memcpy(c + l, &v[0], v.size()*sizeof v[0]);
	return inversion_index;
}
inline void solve(void){
	for (int i = 0; i < m; ++i)
		inv_ind[i] = merge_sort(tmp[i], 0, n-1);
	set<int>inv_set;
	for (int i = 0; i < m; ++i)
		inv_set.insert(inv_ind[i]);
	for (set<int>::iterator iter = inv_set.begin(); iter != inv_set.end(); ++iter)
		for (int i = 0; i < m; ++i)
			if (inv_ind[i] == *iter)printf("%s\n", s[i]);
}
inline void init(void){
	memset(inv_ind, 0, sizeof inv_ind);
}
int main(void){
	int TC; scanf("%d", &TC);
	for(bool first_case = true; TC--; first_case = false){
		if (!first_case) printf("\n");
		first_case = false;
		init();
		read();
		solve();
	}
	return 0;
}

