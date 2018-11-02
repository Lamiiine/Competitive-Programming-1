#include<string>
#include<vector>
#include<map>
#include<string.h>
#include<queue>
#define MAX 12
#define BASE 26LL

using namespace std;
typedef long long int ll;
int n;
map<ll, int> dist;
char sub[MAX][2][MAX];
char gamma[MAX], delta[MAX];
int d_len;
inline ll hash_string(const char * s)
{
	ll ans = 0LL;
	for (; *s; ++s)
	{
		ans = (ll) ans * BASE + (ll) *s;
	}

	return ans;
}
inline void init()
{
	dist.clear();
}

inline void read()
{
	for (int i = 0; i < n; ++i)
	{
		scanf("%s%s", sub[i][0], sub[i][1]);
	}
	scanf("%s%s", gamma, delta);
	d_len = strlen(delta);
}

inline string substitute(const char * v, const char * a, const char * b)
{
	string ans = "";
	for (; *v; )
	{
		bool flag = true;
		for (int j = 0; a[j]; ++j)
		{
			if (v[j] != a[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			ans = ans + string(b);
			v += strlen(a);
		}
		else
		{
			ans = ans + string(1, *v++);
		}
	}

	return ans;
}
inline int bfs()
{
	queue<string> q;
	q.push(gamma);
	dist[hash_string(gamma)] = 0;
	while(!q.empty())
	{
		string v = q.front();
		q.pop();
		const int cur_dist = dist[hash_string(v.c_str())];
		for (int i = 0; i < n; ++i)
		{
			const string u = substitute(v.c_str(), sub[i][0], sub[i][1]);
			if (u.length() <= d_len)
			{
				if (dist.insert(make_pair(hash_string(u.c_str()), cur_dist + 1)).second)
				{
					q.push(u);
				}

				if (!strcmp(u.c_str(), delta))
				{
					return cur_dist + 1;
				}
			}
		}
	}

	return -1;
}

int main()
{
	while(scanf("%d", &n), n)
	{
		init();
		read();
		printf("%d\n", bfs());
	}

	return 0;
}
/*
2
a bb
b aa
a
bbbbbbbb
1
a aa
a
aaaaa
3
ab aab
abc aadc
ad dee
abc
deeeeeeeec
10
a abc
b bai
c acf
d bed
e abh
f fag
g abe
h bag
i aaj
j bbb
a
abacfaabe
0
 */

