
#include<bits/stdc++.h>
using namespace std;
char s[20];
inline int parse(){
	int ans = 0;
	for (int i = strlen(s) - 1, j = 0; i >= 0; --i, ++j)
		if (s[i] == '1')
			ans |= (1 << j);
	return ans;
}
typedef pair<int, int> ii;
vector<int>v;
vector<ii>u;
inline void init(void){
	v.clear();
	u.clear();
}
inline bool cmp(const ii & a, const ii & b){
	return a.first < b.first;
}
int main(void){
	s[0] = '1';
	for(int tc = 1; ~scanf("%s", s + 1); ++tc){
		init();
		v.push_back(parse());
		while(1){
			scanf("%s", s + 1);
			if (!strcmp(s, "19")) break;
			v.push_back(parse());
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i)
			for(int k = v[i] >> 1;k != 1; k >>= 1)
				u.push_back(ii(k, i));
		sort(u.begin(), u.end());
		bool flag = true;
		for (int i = 0; i < v.size() && flag; ++i)
		{
			vector<ii>::iterator start = lower_bound(u.begin(), u.end(), ii(v[i], 0), cmp);
			vector<ii>::iterator end = upper_bound(u.begin(), u.end(), ii(v[i], 0), cmp);
			for (; start != end; ++start)
				if (start->second != i) flag = false;
		}
		printf("Set %d is %simmediately decodable\n", tc, flag ? "" : "not ");
	}
	return 0;
}


