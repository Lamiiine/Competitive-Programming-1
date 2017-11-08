#include<bits/stdc++.h>
using namespace std;
vector<int> occ[26];
char s[1000100];
int len;
inline void init_occ(void)
{
	for (int i = 0; i < 26; ++i)
	{
		occ[i].clear();
	}

	char c;
	for (int i = 0; ; ++i)
	{
		c = s[i];
		if (c == 0)
		{
			len = i;
			break;
		}

		occ[c - 'a'].push_back(i);
	}
}
inline bool found(void)
{
	int last = 0;
	for (int i = 0; ; ++i)
	{
		char c = s[i];
		if (c == 0)
		{
			return true;
		}
		c -= 'a';
		const int nxt = lower_bound(occ[c].begin(), occ[c].end(), last) - occ[c].begin();
		if (nxt == occ[c].size())
		{
			return false;
		}

		last = occ[c][nxt] + 1;
	}

	return false;
}
int main(void)
{
	freopen("delete.in", "r", stdin);
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%s", s);
		init_occ();
		int num_words; scanf("%d", &num_words);
		int ans = 0;
		while(num_words--)
		{
			scanf("%s", s);
			ans += found();
		}
		printf("%d\n", ans);
	}
	return 0;
}

