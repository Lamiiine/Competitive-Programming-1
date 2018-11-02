#include <bits/stdc++.h>
using namespace std;
string s;
inline string solve()
{
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '0')
		{
			return s.substr(0, i) + s.substr(i + 1);
		}
	}
	return string(s.length() - 1, '1');
}
int main()
{
	cin >> s;
	cout << solve();
	return 0;
}
