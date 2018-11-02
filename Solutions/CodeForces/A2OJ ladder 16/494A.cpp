#include <bits/stdc++.h>
#define MAX 100002
using namespace std;
string s;
string out;
int open_count = 0, close_count = 0, hash_count = 0;
const vector<int> invalid = { -1 };
inline bool is_balanced(const string & a)
{
	for (int i = 0, cur = 0; i < a.length(); ++i)
	{
		if (a[i] == '(')
			++cur;
		else
			--cur;
		if (cur < 0) return false;
	}
	return true;
}
inline vector<int> solve()
{
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '(')
			++open_count;
		else if (s[i] == ')')
			++close_count;
		else if (s[i] == '#')
			++hash_count;
		if (open_count < hash_count + close_count)
			return invalid;
	}
	vector<int> ans;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '#')
		{
			if (hash_count > 1)
			{
				++close_count;
				--hash_count;
				ans.push_back(1);
				out += string(1, ')');
			}
			else
			{
				ans.push_back(open_count - close_count);
				out += string(open_count - close_count, ')');
				hash_count = 0;
				close_count += (open_count - close_count);
			}
		}
		else
		{
			out += string(1, s[i]);
		}
	}
	if (is_balanced(out))
	return ans;
	else return invalid;
}
int main()
{
	cin >> s;
	vector<int> ans = solve();
	for (int a : ans)
		printf("%d\n", a);
	return 0;
}

