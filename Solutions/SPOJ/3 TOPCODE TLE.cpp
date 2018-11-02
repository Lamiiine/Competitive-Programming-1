// Most maximization, minimization and counting problems are solvable with DP
#include<stdio.h>
#include<limits.h>
#include<set>
#include<string>
#include<string.h>
#include<bits/stdc++.h>
#include<map>
#define MAX 105
using namespace std;
vector<string>t;	// my top
vector<string>w;	// my words
char s[MAX];
int ans;
int n;
int num;
// int memo[MAX][MAX];
// That's a recursive backtracking algorithm, not a DP solution
// That's definitely going to give a TLE
void dp(int i, int j){	// index of current character; number of existing words
	// printf("%d %d\n", i, j);
	// YOU CONFUSED 'MAX' with 'Max'
	if (j + n - i < ans) return;	// not enough characters!
	if (i == n){
		if (j > ans){
			ans = j;
			t = w;
			num = 1;
		}
		else if (j == ans) ++num;
		return;
	}
	char temp[MAX];
	int counter = 1;
	temp[0] = s[i++];
	temp[1] = 0;
	for (; i < n; ++i){
		temp[counter++] = s[i];
		temp[counter] = 0;
		if (w.empty() || strcmp(temp, w.back().c_str()) > 0) {	// a new word
			w.push_back(temp);
			dp(i + 1, j + 1);
			w.pop_back();
		}
	}
}
int main(){
	// freopen("Input.txt", "r", stdin);
	fgets(s, INT_MAX, stdin); while(!s[0]) fgets(s, INT_MAX, stdin);
	s[n = strlen(s) - 1] = 0;
	while(s[1]){
		ans = INT_MIN;
		num = 0;
		// printf("%s\n", s);
		dp(0, 0);
		printf("%d %d\n%s", ans, num, t[0].c_str());
		for (int i = 1; i < t.size(); ++i) printf(" %s", t[i].c_str());
		printf("\n");
		fgets(s, INT_MAX, stdin); while(!s[0]) fgets(s, INT_MAX, stdin);
		s[n= strlen(s) - 1] = 0;
	}
	return 0;
}
