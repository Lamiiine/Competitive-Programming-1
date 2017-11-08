#include<bits/stdc++.h>
#define MAX 153
using namespace std;
int memo[MAX][MAX][2];
char abb[MAX], line[MAX];
int n, m;	// length of abbreviation and line
/*
 * number of ways of forming the abbreviation starting at index i in the abbreviation,
 * j in the line, knowing that k ? you have already taken a letter in that word : you didn't
 */
inline int dp(const int i, const int j, const int k)
{
	// memorization
	int & ret = memo[i][j][k];
	if (ret != -1) return ret;
	// base cases
	if (i == n)	// done forming abbreviation
	{
		return ret = (k && !strchr(line + j, ' '));
	}
	if (j == m)	// not done forming abbreviation, but ran out of characters
		return ret = 0;
	if (line[j] == ' ')
	{
		if (!k)
			// finished a word without selecting a character in that word
			return ret = 0;
		else return ret = dp(i, j + 1, 0);
	}
	ret = dp(i, j + 1, k);
	if (line[j] == abb[i])
		ret += dp(i + 1, j + 1, 1);
	return ret;
}
inline void init(void)
{
	memset(memo, -1, sizeof memo);
}
int num_insig;
char insig[MAX][MAX];
inline bool is_insig(const char * c)
{
	for (int i = 0; i < num_insig; ++i)
		if (!strcmp(c, insig[i]))
			return 1;
	return 0;
}
char temp[MAX];
const char space[6] = " \n\t";
int main(void)
{
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	while(scanf("%d", &num_insig), num_insig)
	{
		for (int i = 0; i < num_insig; ++i)
			scanf("%s", insig[i]);
		fgets(temp, INT_MAX, stdin);
		while(fgets(temp, INT_MAX, stdin), strcmp(temp, "LAST CASE\n"))
		{
			*line = 0;
			for (char * c = strtok(temp, space); c; c = strtok(0, space))
			{
				if (c == temp)
					strcpy(abb, c);
				else if (!is_insig(c))
					strcat(line, c), strcat(line, " ");
			}

			init();
			n = strlen(abb), m = strlen(line);
			line[--m] = 0;
			for (int i = 0; i < m; ++i)
				line[i] = toupper(line[i]);
			for (int i = 0; i < n; ++i)
				abb[i] = toupper(abb[i]);
			const int ans = dp(0, 0, 0);
			if (ans) printf("%s can be formed in %d ways\n", abb, ans);
			else printf("%s is not a valid abbreviation\n", abb);
		}
	}
	return 0;
}

