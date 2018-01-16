#include<bits/stdc++.h>
#define MAX 102
#define INF 1000000000
using namespace std;
int cost[MAX];
vector<int> sub[MAX];
int n, s, ok, m;
vector<int> init_state;
int init_cost;
int memo[MAX][6600];
inline int compress(const vector<int> & v)
{
	int ans = 0;
	for (int i = s - 1; i >= 0; --i)
	{
		ans = ans * 3 + v[i];
	}
	return ans;
}
inline vector<int> interpret(int mask)
{
	vector<int> ans;
	for(int i = 0; i < s; ++i)
	{
		ans.push_back(mask % 3);
		mask /= 3;
	}
	return ans;
}
inline int dp(const int i, const int mask)
{
	// memory
	int & ret = memo[i][mask];
	if (ret != -1)
	{
		return ret;
	}
	// base case
	if (mask == ok)
	{
		return ret = 0;
	}

	if (i == n)
	{
		return ret = INF;
	}

	vector<int> cur_state = interpret(mask);
	const vector<int> & my_subjects = sub[i];
	for (int j = 0; j < my_subjects.size(); ++j)
	{
		const int cur_subject = my_subjects[j];
		cur_state[cur_subject] = min(2, cur_state[cur_subject] + 1);
	}

	return ret = min(cost[i] + dp(i + 1, compress(cur_state)), dp(i + 1, mask));
}
char line[1000];
const char space[6] = " \n\t\v";
inline void read(void)
{
	for (int i = 0; i < m; ++i)
	{
		fgets(line, INF, stdin);
		for (char * c = strtok(line, space); c; c = strtok(0, space))
		{
			int x; sscanf(c, "%d", &x);
			if (c == line)
			{
				init_cost += x;
			}
			else
			{
				--x;
				init_state[x] = min(init_state[x] + 1, 2);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		fgets(line, INF, stdin);
		for (char * c = strtok(line, space); c; c = strtok(0, space))
		{
			int x; sscanf(c, "%d", &x);
			if (c == line)
			{
				cost[i] = x;
			}
			else
			{
				--x;
				sub[i].push_back(x);
			}
		}
	}

	ok = 0;
	for (int i = 0; i < s; ++i)
	{
		ok = 3 * ok + 2;
	}
}
inline void init(void)
{
	memset(memo, -1, sizeof memo);
	init_cost = 0;
	init_state.clear();
	init_state.resize(s);
	for (int i = 0; i < MAX; ++i)
	{
		sub[i].clear();
	}
}
int main(void)
{
	while(scanf("%d%d%d", &s, &m, &n), s || m || n)
	{
		fgets(line, INF, stdin);
		init();
		read();
		printf("%d\n", init_cost + dp(0, compress(init_state)));
	}

	return 0;
}

