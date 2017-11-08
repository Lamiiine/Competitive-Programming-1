#include<bits/stdc++.h>
using namespace std;
bool found[128] = { 0 };
bool temp[128];
string line, ans1, ans2;
inline string solve()
{
	string ans = "";
	for (int i = 32; i <= 122;)
	{
		if (!temp[i])
		{
			++i; continue;
		}
		int j = i + 1;
		while(j <= 122 && temp[j]) ++j;
		if (j - i > 2)
		{
			ans += string(1, char(i));
			ans += string(1, '-');
			ans += string(1, char(j - 1));
		}
		else for (int k = i; k < j; ++k)
		{
			ans += string(1, char(k));
		}

		i = j;
	}
	return ans;
}
inline bool lex_less(const string & a, const string & b)
{
	if (a.length() < b.length())
		return true;
	if (b.length() < a.length())
		return false;
	return strcmp(a.c_str(), b.c_str()) < 0;
}
inline void normalize(void)
{
	if (temp['A'] && temp['B'] && temp['C'])
		for (int i = 'A' - 1; i >= ':'; --i)
			temp[i] = true;
	if (temp['a'] && temp['b'] && temp['c'])
		for (int i = 'a' - 1; i >= '['; --i)
			temp[i] = true;
	if (temp['0'] && temp['1'] && temp['2'])
		for (int i = '0' - 1; i >= '!'; --i)
			temp[i] = true;
}
inline bool all_taken(void)
{
	for (int i = '0'; i <= '9'; ++i)
		if (!found[i]) return false;
	for (int i = 'a'; i <= 'z'; ++i)
		if (!found[i]) return false;
	for (int i = 'A'; i <= 'Z'; ++i)
		if (!found[i]) return false;
	if (!found[' ']) return false;
	return true;
}
int main(void)
{
	getline(cin, line);
	for (int i = 0; i < line.length(); ++i)
		found[line[i]] = true;
	if (all_taken())
	{
		cout << "%[ -z]";
		return 0;
	}
	memcpy(temp, found, sizeof found);
	normalize();
	ans1 = solve();

	memcpy(temp, found, sizeof found);
	for (int i = '0'; i <= '9'; ++i)
		temp[i] = !temp[i];
	for (int i = 'a'; i <= 'z'; ++i)
		temp[i] = !temp[i];
	for (int i = 'A'; i <= 'Z'; ++i)
		temp[i] = !temp[i];
	temp[' '] = !temp[' '];
	normalize();

	ans2 = string(1, '^') + solve();
	cout << "%[";
	if (lex_less(ans1, ans2))
		cout << ans1;
	else cout << ans2;
	cout << "]";
	return 0;
}

