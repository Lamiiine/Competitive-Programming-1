#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const char space[5] = " \n\t\v";
vector<int>v;
vector<int>stk;	// my stack
int cur;
bool flag;
inline ll value(){
	// printf("%d\n", cur);
	ll my_value = 0LL;
	int x = -v[cur++];
	while(v[cur] != x)
		my_value += value();
	++cur;
	if (my_value >= x){flag = false; return 0LL; }
	return x;
}
inline bool correct(){
	stk.clear();
	for (int i = 0; i < v.size(); ++i){
		int x = v[i];
		if (x > 0){
			if (stk.empty() || stk.back() != -x) return false;
			stk.pop_back();
		}
		else stk.push_back(x);
	}
	return stk.empty();
}
int main() {
	for (string s; getline(cin, s); v.clear()){
		for (char * c = strtok(const_cast<char*>(s.c_str()), space); c; c = strtok(0, space))
			v.push_back(atoi(c));
		if (v.empty()) flag = true;
		else
		if (!correct())
			flag = false;
		else {
			flag = true;
			cur = 0;
			value();
		}
		printf("%s\n", flag ? ":-) Matrioshka!" : ":-( Try again.");
	}
	return 0;
}
