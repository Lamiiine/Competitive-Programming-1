#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	string line;
	while(getline(cin, line))
	{
		for (int i = 0; i < line.length(); ++i)
			line[i] = line[i] - 7;
		cout << line << '\n';
		line = "";
	}
	return 0;
}

