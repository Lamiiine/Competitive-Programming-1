#include<bits/stdc++.h>
using namespace std;
const int MAX = (1e9 + 1.0);
vector<int>lose;
inline void preprocess(void)
{
	lose.push_back(1);
	while(lose.back() < MAX)
	{
		lose.push_back((lose.back() << 1)+ 1);
	}
}
int main(void)
{
	preprocess();
	for (int n; scanf("%d", &n), n;)
	{
		printf("%s\n", binary_search(lose.begin(), lose.end(), n) ? "Bob" : "Alice");
	}
	return 0;
}

