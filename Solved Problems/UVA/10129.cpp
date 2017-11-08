#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#define MAX 100005
using namespace std;
/*
I think the problem is that you have to check whether or not the graph is connected.
It might be the case that all degrees are even and everything is fine, but you still need to check whether you can traverse all the words with a single eulerian circuit
*/
bool adj[26][26];	// 'adj[i][j]': is there a word starting with i and ending with j
int num1[26];	// how many times character i occured at the beginning of a word
int num2[26];	// how many times character i occured at the end of a word
int p[26];	// disjoint sets
bool used[26];	// whether character i has occured or not
void init(){
	memset(num1, 0, sizeof num1);
	memset(num2, 0, sizeof num2);
	memset(used, 0, sizeof used);
	memset(adj, 0, sizeof adj);
	for (int i = 0; i < 26; ++i) p[i] = i;
}
int parent(int i){
	return p[i] == i?i:p[i]=parent(p[i]);
}
void unite(int i, int j){
	p[parent(i)] = parent(j);
}
// return true if graph is connected, false otherwise
bool conn(){
	for (int i = 0; i < 26; ++i)
	for (int j = 0; j < 26; ++j)
		if (adj[i][j]) unite(i, j);
	int ans = 0;
	int i = 0;
	while(!used[i])++i;
	ans = parent(i);
	for (++i; i < 26; ++i)
		if (used[i] && parent(i) != ans)
				return false;
	return true;
}
int n;
int main(){
	// freopen("Input.txt", "r", stdin);
	int TC;
	scanf("%d", &TC);
	char temp[1005];
	while(TC--){
		// DON'T FORGET TO INITIALIZE
		// IT'S A GOOD PRACTICE TO HAVE ALL INITIALIZATIONS REQUIRED IN ONE FUNCTION
		init();
		scanf("%d", &n);
		while(n--){
			scanf("%s", temp);
			char a = temp[0];
			char b = temp[strlen(temp)-1];
			a -= 'a';
			b -= 'a';
			adj[a][b] = true;
			used[a] = true;
			used[b] = true;
			++num1[a];	// num1 stores initial chars
			++num2[b];	// num2 stores last chars
		}
		bool flag = true;
		// bool flag: is there a valid tour?
		// bool end: have you found a character that must occur at the end of the tour?
		// bool begin: have you found a character that must occur at the beginning of the tour?
		bool end = false, begin = false;
		for (int i = 0; flag && i < 26; ++i) {
			int x=abs(num1[i] - num2[i]);
			if (x > 1) flag = false;
			if (x == 1) {
				if (num1[i] > num2[i]) {if (begin) flag = false; begin = true;}
				else {if (end) flag = false; end = true;}
			}
		}
		if (!flag || !conn()) printf("The door cannot be opened.\n");
		else printf("Ordering is possible.\n");
	}
	return 0;
}

