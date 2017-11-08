#include<bits/stdc++.h>
#define MAX 64
using namespace std;
char not_acceptable[16] = "NOT ACCEPTABLE";
char s[64];
int n;
string ans;
inline bool contains_zeros(void)
{
	for (int i = 0; i < n; ++i)
		if (s[i] == '0')
			return true;
	return false;
}
inline string get(const int i)
{
	if (i >= n) return "-1";
	if (s[i] == '2')
		return (i != n - 1) ? string(s + i + 1) : "-1";
	if (s[i] == '3')
	{
		const string t = get(i + 1);
		if (t == "-1") return t;
		return t + "2" + t;
	}
	return "-1";
}
int main(void)
{
	while(scanf("%s", s), strcmp(s, "0"))
	{
		n = strlen(s);
		if (contains_zeros())
		{
			printf("%s\n", not_acceptable);
		}
		else
		{
			const string ans = get(0);
			printf("%s\n", strcmp(ans.c_str(), "-1") ? get(0).c_str() : not_acceptable);
		}
	}
	return 0;
}

