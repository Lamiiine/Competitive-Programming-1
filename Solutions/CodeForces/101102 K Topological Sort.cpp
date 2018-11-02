#include<bits/stdc++.h>
#define MAX 100010
using namespace std;
vector<int> non_prereq[MAX];
priority_queue<int> q[MAX];
int n, m;
bool done[MAX];
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("Input.txt", "r", stdin);
#endif
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			done[i] = 0, non_prereq[i].clear();
		for (int a, b, i = 0; i < m; ++i)
			scanf("%d%d", &a, &b), non_prereq[b].push_back(a);
		for (int i = 1; i <= n; ++i)
			sort(non_prereq[i].begin(), non_prereq[i].end());
		for (int i = 1; i <= n; ++i)
		{
			const vector<int> & cur = non_prereq[i];
			int j = i - 1;
			int k = lower_bound(cur.begin(), cur.end(), j) - cur.begin();
			if (k < cur.size())
				while(k >= 0 && cur[k] == j) --k, --j;
			// j is the last prerequisite for i!
			q[j].push(i);
		}
		int counter = 0;
		vector<int> top_sort;
		for (int i = 0; i < n && counter < n; ++i)
		{
			while(!q[i].empty())
			{
				// v has no more prerequisites!
				const int v = q[i].top();
				q[i].pop();
				printf("%d%c", v, ++counter < n ? ' ' : '\n');
				done[v] = 1;
				// check for all elements in the queue of v!
				while(!q[v].empty())
				{
					const int u = q[v].top();
					q[v].pop();
					int j = v - 1;
					const vector<int> & cur = non_prereq[u];
					while(j > i)
					{
						while(j > i && done[j]) --j;
						int k = lower_bound(cur.begin(), cur.end(), j) - cur.begin();
						if (j > i && k < cur.size())
							while(j > i && k >= 0 && cur[k] == j) --k, --j;
						else break;
					}
					q[j].push(u);
				}
			}
		}
	}
}

