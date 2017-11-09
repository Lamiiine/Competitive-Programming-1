#include <bits/stdc++.h>
#define MAX 105
using namespace std;
string s;
int count_lower, count_upper;
int main()
{
	cin >> s;
	for (const char * c = s.c_str(); *c; ++c)
	{
		if (islower(*c))
			++count_lower;
		else ++count_upper;
	}
	if (count_upper > count_lower)
	{
		for (char * c = const_cast<char *>(s.c_str()); *c; ++c)
		{
			if (islower(*c))
			{
				*c = toupper(*c);
			}
		}
	}
	else
	{
		for (char * c = const_cast<char *>(s.c_str()); *c; ++c)
		{
			if (isupper(*c))
			{
				*c = tolower(*c);
			}
		}
	}
	cout << s;
	return 0;
}
