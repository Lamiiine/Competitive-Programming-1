#include<bits/stdc++.h>
#define MAX 25500
using namespace std;
int a, b;	// we need to go from a to b
int n;
string s[MAX];
map<string, int> m;
char line[50];
inline bool empty_line(void)
{
	for (char * c = line; *c; ++c)
		if (!isspace(*c)) return false;
	return true;
}
typedef pair<int, int> ii;
int p[MAX];
inline void print(void)
{
	vector<int> ans;
	while(b != INT_MIN)
	{
		ans.push_back(b);
		b = p[b];
	}
	for (int i = ans.size() - 1; i >= 0; --i)
		printf("%s\n", s[ans[i]].c_str());
}
inline void bfs(void)
{
	memset(p, -1, sizeof p);
	queue<int> q;
	q.push(a);
	p[a] = INT_MIN;
	while(!q.empty())
	{
		const int i = q.front();
		q.pop();
		const string & cur = s[i];
		string temp = cur;
		for (int j = 0; j < cur.length(); ++j)
		{
			for (char c = 'a'; c <= 'z'; ++c)
			{
				if (cur[j] != c)
				{
					temp[j] = c;
					if (m.find(temp) != m.end())
					{
						const int k = m[temp];
						if (k == b)
						{
							p[k] = i;
							print();
							return;
						}
						if (p[k] == -1)
						{
							p[k] = i;
							q.push(k);
						}
					}
				}
			}
		}
	}

	printf("No solution.\n");
}
inline void read(void)
{
	n = 0;
	while(true)
	{
		fgets(line, INT_MAX, stdin);
		if (empty_line()) break;
		line[strlen(line) - 1] = 0;
		m[s[n] = line] = n;
		++n;
	}
}
int main(void)
{
	read();
	for (int tc = 0; ; ++tc)
	{
		fgets(line, INT_MAX, stdin);
		line[strlen(line) - 1] = 0;
		if (empty_line()) break;
		if (tc) printf("\n");
		int s_index = 0;
		while(line[s_index] != ' ') ++s_index;
		line[s_index++] = 0;
		if (m.find(line) == m.end() || m.find(line + s_index) == m.end())
		{
			printf("No solution.\n");
			continue;
		}
		a = m[line];
		b = m[line + s_index];
		bfs();
	}
	return 0;
}
/*
booster
rooster
roaster
coasted
roasted
coastal
postal

booster roasted
coastal postal
 */

