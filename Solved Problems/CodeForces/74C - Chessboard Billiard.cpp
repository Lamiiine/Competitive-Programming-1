#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000100;
bool leftTaken[MAX + MAX];
bool rightTaken[MAX + MAX];
int num;
int n, m;
void dfs(int i)
{
	vector<int> left;
	vector<int> right;
	left.push_back(i);
	while (!left.empty() || !right.empty())
	{
		if (!left.empty())
		{
			i = left.back();
			left.pop_back();
			if (i < 0 || i >= num || leftTaken[i])
			{
				continue;
			}
			leftTaken[i] = true;
			// the right diagonals you will touch have the index x - y
			right.push_back(-i);
			right.push_back(i);
			right.push_back(2 * m - 2 - i);
			right.push_back(i - 2 * n + 2);
		}
		if (!right.empty())
		{
			i = right.back();
			right.pop_back();
			if (i < 1 - n || i > m - 1 || rightTaken[i + MAX])
			{
				continue;
			}
			rightTaken[i + MAX] = true;
			left.push_back(-i);
			left.push_back(i);
			left.push_back(2 * m - 2 - i);
			left.push_back(i + 2 * n - 2);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	num = n + m - 1;
	int ans = 0;
	for (int i = 0; i < num; ++i)
	{
		if (!leftTaken[i])
		{
			++ans;
			dfs(i);
		}
	}
	printf("%d", ans);
	return 0;
}

