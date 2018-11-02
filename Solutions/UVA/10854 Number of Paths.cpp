#include<bits/stdc++.h>
using namespace std;
char line[32];
vector<string> program;
inline void read(void)
{
	program.clear();
	for(scanf("%s", line); strcmp(line, "ENDPROGRAM"); scanf("%s", line))
		if (strcmp(line, "S"))
			program.push_back(line);
}
int i;
// count the number of paths inside this IF statement!
inline int solve()
{
	// this has to be an IF statement!
	++i;
	int ans_if = 1, ans_else = 1;
	while(!strcmp(program[i].c_str(), "IF"))
		ans_if *= solve();
	// this has to be an ELSE statement!
	++i;
	while(!strcmp(program[i].c_str(), "IF"))
		ans_else *= solve();
	// this has to be an END_IF statement!
	++i;
	return ans_if + ans_else;
}
int main(void)
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		int ans = 1;
		i = 0;
		while(i < program.size())
			ans *= solve();
		printf("%d\n", ans);
	}
	return 0;
}

