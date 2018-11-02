#include<bits/stdc++.h>
using namespace std;
set<string> s;
inline void init()
{
	s.clear();
}
int n;
inline void read(void)
{
	scanf("%d", &n);
	char name[100];
	for (int i = 0; i < 2 * n - 1; ++i)
	{
		scanf("%s", name);
		if (s.find(name) == s.end())
		{
			s.insert(name);
		}
		else s.erase(name);
	}
}
int main(void)
{
	freopen("joy.in", "r", stdin);
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		init();
		read();
		printf("%s\n", (*s.begin()).c_str());
	}
	return 0;
}
