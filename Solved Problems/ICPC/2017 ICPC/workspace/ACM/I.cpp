#include<bits/stdc++.h>
using namespace std;
/*
#define MAX 26
// all matrices must have dimension MAX * MAX
inline void mul(bool x[][MAX], bool y[][MAX], bool z[][MAX])
{
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{

		}
	}
}
bool temp[MAX][MAX];

// raise x to power, storing the result in y
inline void raise(bool x[][MAX], bool y[][MAX], int power)
{
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			y[i][j] = (i == j);
		}
	}

	for (; power; power >>= 1, mul(temp, temp, temp))
	{
		if (power & 1)
		{
			mul(y, y, temp);
		}
	}
	memcpy(y, temp, sizeof temp);
}
*/

bool adj[26][26];

void proccess(){
	for(int k = 0; k < 26; k++)
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < 26; j++)
					adj[i][j] |= (adj[i][k] & adj[k][j]);
}
void init(){
	memset(adj, 0, sizeof adj);
	for(int i = 'a'; i <= 'z'; i++)
		adj[i-'a'][i-'a'] = true;
}
bool check(string s1, string s2){
	if(s1.size() != s2.size()) return false;

	for(int i = 0; i < s1.size(); i++)
		if(s1[i] != s2[i] && !adj[s1[i]-'a'][s2[i]-'a'])
			return false;

	return true;
}
int main()
{
	int m, n; cin >> m >> n;
	while(m--){
		char a, b;
		cin >> a >> b;
		adj[a-'a'][b-'a'] = true;
	}
	proccess();
	while(n--){
		string s1, s2;
		cin >> s1 >> s2;
		if(check(s1, s2)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}
