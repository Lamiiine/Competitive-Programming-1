#include<bits/stdc++.h>
using namespace std;
string line;
int i;
inline double solve()
{
	while(isspace(line[i])) ++i;
	double ans;
	if (line[i] == '(')
	{
		++i;
		// it's a double!
		sscanf(line.c_str() + i, "%lf", &ans);
		while(i < line.length() && (isdigit(line[i]) || line[i] == '.')) ++i;
		double x = solve();
		double y = solve();
		while(line[i] != ')') ++i;
		++i;
		return ans * (x + y) + (1.0 - ans) * (x - y);
	}
	else
	{
		sscanf(line.c_str() + i, "%lf", &ans);
		while(i < line.length() && (isdigit(line[i]) || line[i] == '-' || line[i] == '+'))
			++i;
		return ans;
	}
}
int main(void)
{
	while(getline(cin, line), strcmp(line.c_str(), "()"))
	{
		i = 0;
		printf("%.2lf\n", solve());
	}
}

