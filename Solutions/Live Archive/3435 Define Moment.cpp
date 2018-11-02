#include<bits/stdc++.h>
using namespace std;
string pre;
string suf;
string word;
void handle_pre(){
	if (!strncmp(word.c_str(), "anti", 4)){
		pre = "against ";
		word = word.substr(4);
	}
	if (!strncmp(word.c_str(), "post", 4)){
		pre = "after ";
		word = word.substr(4);
	}
	if (!strncmp(word.c_str(), "pre", 3)){
		pre = "before ";
		word = word.substr(3);
	}
	if (!strncmp(word.c_str(), "re", 2)){
		suf = " again";
		word = word.substr(2);
	}
	if (!strncmp(word.c_str(), "un", 2)){
		pre = "not ";
		word = word.substr(2);
	}
}
void handle_suf(){
	int n = word.length();
	if (!strncmp(word.c_str() + n - 2, "er", 2)){
		pre += "one who ";
		suf = "s" + suf;
		word = word.substr(0, n-2);
	}
	if (!strncmp(word.c_str() + n - 3, "ing", 3)){
		pre += "to actively ";
		word = word.substr(0, n-3);
	}
	if (!strncmp(word.c_str() + n - 3, "ize", 3)){
		pre += "change into ";
		word = word.substr(0, n-3);
	}
	if (!strncmp(word.c_str() + n - 1, "s", 1)){
		pre += "multiple instances of ";
		word = word.substr(0, n-1);
	}
	if (!strncmp(word.c_str() + n - 4, "tion", 4)){
		pre += "the process of ";
		word = word.substr(0, n-4);
		suf = "ing" + suf;
	}
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	while(n--){
		pre = suf = "";
		cin >> word;
		handle_pre();
		handle_suf();
		printf("%s%s%s\n", pre.c_str(), word.c_str(), suf.c_str());
	}
	return 0;
}

