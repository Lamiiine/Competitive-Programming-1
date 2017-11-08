#include<bits/stdc++.h>
using namespace std;
char s[60];
char p[60][60];
inline void init(void){
	memset(p, ' ', sizeof p);
	memset(p[0], '-', sizeof p[0]);
	p[0][0] = '+';
	for (int i = 1; i < 60; ++i)
		p[i][0] = '|';
}
inline void end_at(const int j){
	for (int i = 0; i < 60; ++i)
		p[i][j] = 0;
	/* You got a WA because you forgot to remove extra trailing spaces
	 * even though the problem statement explicitly said there should
	 * be no trailing spaces
	 * */
	for (int i = 0; i < 60; ++i){
		char * cur = p[i];
		int k = j - 1;
		while(cur[k] == ' ')cur[k--] = 0;
	}
}
inline void print(int j){
	for (int i = j; i >= 0; --i)
		printf("%s\n", p[i]);
	printf("\n");
}
int find_min_y(){
	int ans = 0;
	int cur = 0;
	for (int i = 0; s[i]; ++i){
		switch(s[i]){
		case 'R':++cur;break;
		case 'F':--cur;break;
		default:break;
		}
		ans = min(ans, cur);
	}
	return ans;
}
inline void process(){
	int max_j = 0;
	int cur_j = 1 - find_min_y();
	for (int i = 0; s[i]; ++i){
		switch(s[i]){
		case 'R':
			p[cur_j][i + 2] = '/';
			max_j = max(max_j, cur_j);
			++cur_j;
			break;
		case 'F':
			--cur_j;
			p[cur_j][i + 2] = '\\';
			max_j = max(max_j, cur_j);
			break;
		case 'C':
			p[cur_j][i + 2] = '__';
			max_j = max(max_j, cur_j);
			break;
		}
	}
	end_at(3 + strlen(s));
	print(max_j);
}
int main(void) {
	int TC; scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		init();
		scanf("%s", s);
		printf("Case #%d:\n", tc);
		process();
	}
	return 0;
}

