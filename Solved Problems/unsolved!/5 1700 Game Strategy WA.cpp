#include<bits/stdc++.h>
#define MAX 27
#define INF 100000000
using namespace std;
inline int bob(const int);
inline int alice(const char);
int n;	// number of positions
int option_counter;
int s[MAX], e[MAX];
char option[1000100][MAX];
char alice_start_position;
/*
 * minimum number of rounds required for Ms. Alice to go to her initial position
 * if she is currently at position p
 */
int alice_memo[MAX];
inline int alice(const char p)
{
	int & ret = alice_memo[p];
	if (ret != -1)
	{
		return ret;
	}

	// base case!
	if (p == alice_start_position)
	{
		return ret = 0;
	}

	ret = INF;
	for (int i = s[p]; i < e[p]; ++i)
	{
		ret = min(ret, 1 + bob(i));
	}

	return ret;
}
/*
 * maximum number of operations required for Ms. Alice to go to her initial position
 * if bob can send her to any position in option[option_index]
 */
int bob_memo[MAX];
inline int bob(const int option_index)
{
	// memory
	int & ret = bob_memo[option_index];
	if (ret != -1)
	{
		return ret;
	}
	// recurse
	ret = 0;
	for (char * c = option[option_index]; *c; ++c)
	{
		ret = max(ret, alice(*c - 'a'));
	}

	return ret;
}

inline void read(void)
{
	for (int i = 0; i < n; ++i)
	{
		s[i] = option_counter;
		int m; scanf("%d", &m);
		while(m--)
		{
			scanf("%s", option[option_counter++]);
		}

		e[i] = option_counter;
	}
}

int main(void)
{
	while(~scanf("%d", &n))
	{
		option_counter = 0;
		read();
		for (char p = 0; p < n; ++p)
		{
			for (char q = 0; q < n; ++q)
			{
				memset(alice_memo, -1, sizeof alice_memo);
				memset(bob_memo, -1, sizeof bob_memo);
				alice_start_position = q;
				printf("%d%c", alice(p) >= INF ? -1 : alice_memo[p], q == n - 1 ? '\n' : ' ');
			}
		}
	}

	return 0;
}
/*
2
2 ab b
1 b
3
1 b
2 b a
2 ab ac

number of operations = 25 * 25 * ((25 * 25) + (25 * ))
 */

