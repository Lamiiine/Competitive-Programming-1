#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
map<string, int> dic;
string word[10100];
int n, q;
char s[32];
int main(void)
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", s);
		word[i] = s;
		dic[word[i]] = i;
	}
	scanf("%d", &q);
	while(q--)
	{
		scanf("%s", s);
		printf("%s is ", s);
		const string cur(s);
		if (dic.find(cur) != dic.end())
		{
			printf("correct");
		}
		else
		{
			int ans = INF;
			for (int i = 0; i < cur.length() && ans; ++i)
			{
				string temp;
				// try swapping
				if (i)
				{
					temp = cur;
					swap(temp[i], temp[i - 1]);
					if (dic.find(temp) != dic.end())
						ans = min(ans, dic[temp]);
				}

				temp = cur.substr(0, i) + cur.substr(i + 1);
				if (dic.find(temp) != dic.end())
					ans = min(ans, dic[temp]);

				temp = cur;
				for (char j = 'a'; j <= 'z'; ++j)
				{
					temp[i] = j;
					if (dic.find(temp) != dic.end())
						ans = min(ans, dic[temp]);
				}

				for (char j = 'a'; j <= 'z'; ++j)
				{
					temp = cur.substr(0, i) + string(1, j) + cur.substr(i);
					if (dic.find(temp) != dic.end())
						ans = min(ans, dic[temp]);
				}
			}
			for (char j = 'a'; j <= 'z'; ++j)
			{
				string temp = cur + string(1, j);
				if (dic.find(temp) != dic.end())
					ans = min(ans, dic[temp]);
			}
			if (ans == INF)
			{
				printf("unknown");
			}
			else
			{
				printf("a misspelling of %s", word[ans].c_str());
			}
		}
		printf("\n");
	}
}

