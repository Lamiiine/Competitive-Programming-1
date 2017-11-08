#include<bits/stdc++.h>
#define MAX 100
using namespace std;
char a[MAX], b[MAX];
int n, m;
int memo[MAX][MAX];
inline int dp(int i, int j)
{
	int & ret = memo[i][j];
	if (ret != -1) return ret;
	if (i == n) return ret = m - j;	// need to insert m-j elements to the back of a
	if (j == m) return ret = n - i;	// need to delete n-i elements from the back of a
	if (a[i] == b[j]) return ret = dp(i + 1, j + 1);	// no need for changes
	return ret = 1 + min(	// 1 change
			dp(i + 1, j + 1), min(	// replace a[i] with b[j]
			dp(i, j + 1),			// insert b[j] into a[i]
			dp(i + 1, j)));			// delete a[i]
}
int cur_length;
inline void init(void){
	cur_length = 0;
	memset(memo, 0xFF, sizeof memo);
}
// you need to match strings starting at i, j
inline void path(int i, int j, int counter){
	int ans = dp(i, j);
	if (!ans)
		// done
		return;
	if (i == n){
		for (;j < m; ++j, ++counter)
			printf("%d Insert %d,%c\n", counter, i++ + 1 + cur_length, b[j]);
		return;
	}
	if (j == m){
		for (;i < n; ++i, ++counter)
			printf("%d Delete %d\n", counter, i + 1 + cur_length--);
		return;
	}
	if (a[i] == b[j]) {
		// no changes required
		path(i + 1, j + 1, counter);
		return;
	}
	--ans;
	if (dp(i + 1, j + 1) == ans){
		printf("%d Replace %d,%c\n", counter, i + 1 + cur_length, b[j]);
		// length hasn't changed
		path(i + 1, j + 1, counter + 1);
		return;
	}
	if (dp(i, j + 1) == ans){
		printf("%d Insert %d,%c\n", counter, i + 1  + cur_length, b[j]);
		++cur_length;
		path(i, j + 1, counter + 1);
		return;
	}
	if (dp(i + 1, j) == ans){
		printf("%d Delete %d\n", counter, i + 1 + cur_length);
		--cur_length;
		path(i + 1, j, counter + 1);
		return;
	}
}
inline bool read(void){
	*a = *b = 0;
	fgets(a, INT_MAX, stdin);
	fgets(b, INT_MAX, stdin);
	if (*a == 0 || *b == 0) return false;
	n = strlen(a); if (a[n-1] == '\n')a[--n] = 0;
	m = strlen(b); if (b[m-1] == '\n') b[--m] = 0;
	return true;
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	bool first_case = true;
	while(read())
	{
		if (!first_case) printf("\n");
		first_case = false;
		init();
		printf("%d\n", dp(0, 0));
		path(0, 0, 1);
	}
	return 0;
}

