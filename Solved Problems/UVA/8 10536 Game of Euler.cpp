#include<bits/stdc++.h>
using namespace std;
int memo[1 << 16];
inline bool free(const int k, const int i, const int j){
	return !(k & ((1 << (i << 2)) << j));
}
inline int occ(const int k, const int i, const int j){
	return k | ((1 << (i << 2)) << j);
}
inline int dp(const int k){
	int & ret = memo[k];
	if (ret != -1) return ret;
	// try inserting a pin of length 1
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (free(k, i, j) && !dp(occ(k, i, j))) return ret = 1;
	// try inserting a pin of length 2
	for (int i = 0; i < 4; ++i)
		if (free(k, i, 0) && free(k, i,1) && !dp(occ(occ(k, i, 0), i, 1))) return ret = 1;
	for (int i = 0; i < 4; ++i)
			if (free(k, i, 3) && free(k, i, 2) && !dp(occ(occ(k, i, 3), i, 2))) return ret = 1;
	for (int j = 0; j < 4; ++j)
		if (free(k, 0, j) && free(k, 1, j) && !dp(occ(occ(k, 0, j), 1, j))) return ret = 1;
	for (int j = 0; j < 4; ++j)
		if (free(k, 3, j) && free(k, 2, j) && !dp(occ(occ(k, 3, j), 2, j))) return ret = 1;
	// try inserting a pin of length 3
	for (int i = 0; i < 4; ++i)
		if (free(k, i, 0) && free(k, i, 1) && free(k, i, 2)&& !dp(occ(occ(occ(k, i, 0), i, 1), i, 2))) return ret = 1;
	for (int i = 0; i < 4; ++i)
		if (free(k, i, 3) && free(k, i, 2) && free(k, i, 1)&& !dp(occ(occ(occ(k, i, 3), i, 2), i, 1))) return ret = 1;
	for (int j = 0; j < 4; ++j)
		if (free(k, 0, j) && free(k, 1, j) && free(k, 2, j) && !dp(occ(occ(occ(k, 0, j), 1, j), 2, j))) return ret = 1;
	for (int j = 0; j < 4; ++j)
		if (free(k, 3, j) && free(k, 2, j) && free(k, 1, j) && !dp(occ(occ(occ(k, 3, j), 2, j), 1, j))) return ret = 1;
	return ret = 0;
}
#define lsone(i) ((i) & (-i))
#define count_free(i) (16 - count_ones(i))
inline int count_ones(int i){
	int ans = 0;
	while(i) ++ans, i -= lsone(i);
	return ans;
}
inline void init_memo(void){
	memset(memo, 0xFF, sizeof memo);
	memo[(1 << 16) - 1] = 1;
	for (int i = 0, x; i < (1 << 16); ++i){
		x = count_free(i);
		if (x == 1) memo[i] = 0;
		else if (x == 2) memo[i] = 1;
	}
}
char a[6][6];
inline int read(void){
	int k = 0;
	for (int i = 0; i < 4; ++i)
		scanf("%s", a[i]);
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (a[i][j] == 'X')
				k |= ((1 << (i << 2)) << j);
	return k;
}
int main(void){
	init_memo();
	int TC; scanf("%d", &TC);
	while(TC--)
		printf("%s\n", dp(read()) ? "WINNING" : "LOSING");
	return 0;
}

