#include<bits/stdc++.h>
#define left(i) (i << 1)
#define right(i) ((i << 1) + 1)
using namespace std;
char vowel[6] = "aeiou";
char mapping[128][128];
vector<char>s[1 << 18];
inline bool salah(int i);
inline bool marzo(int i);
inline void gen_right(int i){
	const vector<char> & v = s[i];
	vector<char> & u = s[right(i)];
	int len = v.size();
	u.reserve((len >> 1) + (len & 1));
	for (int j = len - 1; j >= 1; j -= 2)
		u.push_back(mapping[v[j - 1]][v[j]]);
	if (len & 1)
		u.push_back(v[0]);
}
inline void gen_left(int i){
	const vector<char>&v = s[i];
	int len = v.size();
	vector<char> & u = s[left(i)];
	u.reserve((len >> 1) + (len & 1));
	for (int j = 0; j < len - 1; j += 2)
		u.push_back(mapping[v[j]][v[j + 1]]);
	if (len & 1)
		u.push_back(v[len - 1]);
}
inline void generate(int i)
{
	if (s[i].size() != 1){
		gen_left(i);
		gen_right(i);
		generate(left(i));
		generate(right(i));
	}
}
inline void read_input(void){
	for (int i = 0; i < (1 << 18); ++i)
		s[i].clear();
	for (char i = 'a'; i <= 'z'; ++i)
		scanf("%s", mapping[i] + 'a');
	static char temp[10010];
	scanf("%s", temp);
	vector<char> & v = s[1];
	for (char * c = temp; *c; ++c)
		v.push_back(*c);
}
int main(void){
	int TC; scanf("%d", &TC);
	while(TC--){
		read_input();
		generate(1);
		printf("%s\n", salah(1) ? "Salah" : "Marzo");
	}
	return 0;
}
inline bool marzo(int i){
	if (s[i].size() == 1)
		return !binary_search(vowel, vowel + 5, s[i][0]);
	return !(salah(left(i)) && salah(right(i)));
}
inline bool salah(int i){
	if (s[i].size() == 1) return binary_search(vowel, vowel + 5, s[i][0]);
	return !(marzo(left(i)) && marzo(right(i)));
}

