#include<bits/stdc++.h>
#define MAX 13
#define lsone(s) ((s) & (-s))
using namespace std;
int memo[1 << MAX];
int arr[MAX][5];
inline int count_ones(int i) {
	int ans = 0;
	while (i) {
		i -= lsone(i);
		++ans;
	}
	return ans;
}

inline void init_memo(void) {
	memset(memo, -1, sizeof memo);
	memo[(1 << MAX) - 1] = 0;
}

inline int max_kind(const int cur_ind) {
	int counter[7] = { 0 };
	for (int i = 0; i < 5; ++i) {
		++counter[arr[cur_ind][i]];
	}
	int ans = 0;
	for (int i = 1; i <= 6; ++i) {
		ans = max(ans, counter[i]);
	}
	return ans;
}
inline int sum(const int cur_ind) {
	int ans = 0;
	for (int i = 0; i < 5; ++i) {
		ans += arr[cur_ind][i];
	}
	return ans;
}
inline bool short_straight(const int cur_ind) {
	int counter[7] = { 0 };
	for (int i = 0; i < 5; ++i) {
		++counter[arr[cur_ind][i]];
	}
	for (int i = 1; i <= 3; ++i) {
		if (counter[i] && counter[i + 1] && counter[i + 2] && counter[i + 3]) {
			return true;
		}
	}
	return false;
}
inline bool long_straight(const int cur_ind) {
	int counter[7] = { 0 };
	for (int i = 0; i < 5; ++i) {
		++counter[arr[cur_ind][i]];
	}
	bool flag = false;
	for (int i = 1; i <= 2; ++i) {
		if (counter[i] && counter[i + 1] && counter[i + 2] && counter[i + 3]
				&& counter[i + 4]) {
			flag = true;
			break;
		}
	}
	return flag;
}
inline bool full_house(const int cur_ind) {
	int counter[7] = { 0 };
	for (int i = 0; i < 5; ++i) {
		++counter[arr[cur_ind][i]];
	}
	set<int> s;
	for (int i = 1; i <= 6; ++i) {
		s.insert(counter[i]);
	}
	return (s.find(2) != s.end() && s.find(3) != s.end());
}
inline int sum_of_kind(const int idx, const int kind) {
	int ans = 0;
	for (int j = 0; j < 5; ++j) {
		ans += ((arr[idx][j] == kind) ? kind : 0);
	}

	return ans;
}
inline int get_score(const int category_id, const int round_id)
{
	switch (category_id)
	{
	case 0: return sum_of_kind(round_id, 1);
	case 1: return sum_of_kind(round_id, 2);
	case 2: return sum_of_kind(round_id, 3);
	case 3: return sum_of_kind(round_id, 4);
	case 4: return sum_of_kind(round_id, 5);
	case 5: return sum_of_kind(round_id, 6);
	case 6: return sum(round_id);
	case 7: return max_kind(round_id) >= 3 ? sum(round_id) : 0;
	case 8: return max_kind(round_id) >= 4 ? sum(round_id) : 0;
	case 9: return max_kind(round_id) >= 5 ? 50 : 0;
	case 10: return short_straight(round_id) ? 25 : 0;
	case 11: return long_straight(round_id) ? 35 : 0;
	case 12: return full_house(round_id) ? 40 : 0;
	}

	return -1000000;
}
/*
 * having the rounds that are marked out in mask as available,
 * return the maximum possible gain
 * */
inline int dp(const int mask) {
	int & ret = memo[mask];
	if (ret != -1) {
		return ret;
	}

	ret = 0;
	const int category_id = 12 - count_ones(mask);
	for (int i = 0; i < 13; ++i)
	{
		if (!(mask & (1 << i)))
		{
			// you can use round #i for this score category
			ret = max(ret, get_score(category_id, i) + ((category_id == 6 && dp(mask | (1 << i)) >= 63) ? 35 : 0) + dp(mask | (1 << i)));
		}
	}
	return ret;
}
int scores[13];
inline void getPath(const int mask)
{
	const int category_id = 12 - count_ones(mask);
	if (category_id == -1) return;
	for (int i = 0; i < 13; ++i) {
		if (!(mask & (1 << i)) && get_score(category_id, i) + ((category_id == 6 && dp(mask | (1 << i)) >= 63) ? 35 : 0) + dp(mask | (1 << i)) == dp(mask))
		{
			scores[category_id] = get_score(category_id, i);
			getPath(mask | (1 << i));
			return;
		}
	}
}
int main(void) {
	while (~scanf("%d%d%d%d%d", arr[0], arr[0] + 1, arr[0] + 2, arr[0] + 3,
			arr[0] + 4)) {
		for (int i = 1; i < 13; ++i) {
			for (int j = 0; j < 5; ++j) {
				scanf("%d", arr[i] + j);
			}
		}
		init_memo();
		getPath(0);
		for (int i = 0; i < 13; ++i)
		{
			printf("%d ", scores[i]);
		}
		int sum_first_six = 0;
		for (int i = 0; i < 6; ++i)
			sum_first_six += scores[i];
		printf("%d ", sum_first_six >= 63 ? 35 : 0);
		printf("%d\n", dp(0));
	}
	return 0;
}
/*
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 2 3 4 5
 1 1 1 1 1
 6 6 6 6 6
 6 6 6 1 1
 1 1 1 2 2
 1 1 1 2 3
 1 2 3 4 5
 1 2 3 4 6
 6 1 2 6 6
 1 4 5 5 5
 5 5 5 5 6
 4 4 4 5 6
 3 1 3 6 3
 2 2 2 4 6
 */

/*
// this solution is more complicated
// it also can not get the bonus part right!
#include<bits/stdc++.h>
#define MAX 13
#define lsone(s) ((s) & (-s))
using namespace std;
int memo[1 << MAX];
int arr[MAX][5];
inline int count_ones(int i)
{
	int ans = 0;
	while(i)
	{
		i -= lsone(i);
		++ans;
	}
	return ans;
}
inline void init_memo(void)
{
	memset(memo, -1, sizeof memo);
	memo[(1 << MAX) - 1] = 0;
}
inline int max_kind(const int cur_ind)
{
	int counter[7] = { 0 };
	for (int i = 0; i < 5; ++i)
	{
		++counter[arr[cur_ind][i]];
	}
	int ans = 0;
	for (int i = 1; i <= 6; ++i)
	{
		ans = max(ans, counter[i]);
	}
	return ans;
}
inline int sum(const int cur_ind)
{
	int ans = 0;
	for (int i = 0; i < 5; ++i)
	{
		ans += arr[cur_ind][i];
	}
	return ans;
}
inline bool short_straight(const int cur_ind)
{
	int counter[7] = { 0 };
	for (int i = 0; i < 5; ++i)
	{
		++counter[arr[cur_ind][i]];
	}
	bool flag = false;
	for (int i = 1; i <= 3; ++i)
	{
		if (counter[i] && counter[i + 1] && counter[i + 2] && counter[i + 3])
		{
			flag = true;
			break;
		}
	}
	return flag;
}
inline bool long_straight(const int cur_ind)
{
	int counter[7] = { 0 };
	for (int i = 0; i < 5; ++i)
	{
		++counter[arr[cur_ind][i]];
	}
	bool flag = false;
	for (int i = 1; i <= 2; ++i)
	{
		if (counter[i] && counter[i + 1] && counter[i + 2] && counter[i + 3] && counter[i + 4])
		{
			flag = true;
			break;
		}
	}
	return flag;
}
inline bool full_house(const int cur_ind)
{
	int counter[7] = { 0 };
	for (int i = 0; i < 5; ++i)
	{
		++counter[arr[cur_ind][i]];
	}
	set<int>s;
	for (int i = 1; i <= 6; ++i)
	{
		s.insert(counter[i]);
	}
	return (s.find(2) != s.end() && s.find(3) != s.end());
}
inline int dp(const int mask)
{
	int & ret = memo[mask];
	if (ret != -1.0)
	{
		return ret;
	}
	const int cur_ind = count_ones(mask);
	ret = 0;
	if (!(mask & (1 << 0)))
	{
		int cur_gain = 0;
		for (int i = 0; i < 5; ++i)
		{
			cur_gain += ((arr[cur_ind][i] == 1) ? 1 : 0);
		}
		ret = max(ret, cur_gain + dp(mask | (1 << 0)));
	}
	if (!(mask & (1 << 1)))
	{
		int cur_gain = 0;
		for (int i = 0; i < 5; ++i)
		{
			cur_gain += ((arr[cur_ind][i] == 2) ? 2 : 0);
		}
		ret = max(ret, cur_gain + dp(mask | (1 << 1)));
	}
	if (!(mask & (1 << 2)))
	{
		int cur_gain = 0;
		for (int i = 0; i < 5; ++i)
		{
			cur_gain += ((arr[cur_ind][i] == 3) ? 3 : 0);
		}
		ret = max(ret, cur_gain + dp(mask | (1 << 2)));
	}
	if (!(mask & (1 << 3)))
	{
		int cur_gain = 0;
		for (int i = 0; i < 5; ++i)
		{
			cur_gain += (arr[cur_ind][i] == 4) ? 4 : 0;
		}
		ret = max(ret, cur_gain + dp(mask | (1 << 3)));
	}
	if (!(mask & (1 << 4)))
	{
		int cur_gain = 0;
		for (int i = 0; i < 5; ++i)
		{
			cur_gain += (arr[cur_ind][i] == 5) ? 5 : 0;
		}
		ret = max(ret, cur_gain + dp(mask | (1 << 4)));
	}
	if (!(mask & (1 << 5)))
	{
		int cur_gain = 0;
		for (int i = 0; i < 5; ++i)
		{
			cur_gain += (arr[cur_ind][i] == 6) ? 6 : 0;
		}
		ret = max(ret, cur_gain + dp(mask | (1 << 5)));
	}
	if (!(mask & (1 << 6)))
	{
		ret = max(ret, sum(cur_ind) + dp(mask | (1 << 6)));
	}
	if (!(mask & (1 << 7)) && max_kind(cur_ind) >= 3)
	{
		ret = max(ret, sum(cur_ind) + dp(mask | (1 << 7)));
	}
	if (!(mask & (1 << 8)) && max_kind(cur_ind) >= 4)
	{
		ret = max(ret, sum(cur_ind) + dp(mask | (1 << 8)));
	}
	if (!(mask & (1 << 9)) && max_kind(cur_ind) >= 5)
	{
		ret = max(ret, 50 + dp(mask | (1 << 9)));
	}
	if (!(mask & (1 << 10)) && short_straight(cur_ind))
	{
		ret = max(ret, 25 + dp(mask | (1 << 10)));
	}
	if (!(mask & (1 << 11)) && long_straight(cur_ind))
	{
		ret = max(ret, 35 + dp(mask | (1 << 11)));
	}
	if (!(mask & (1 << 12)) && full_house(cur_ind))
	{
		ret = max(ret, 40 + dp(mask | (1 << 12)));
	}
	return ret;
}
int main(void)
{
	while(~scanf("%d%d%d%d%d", arr[0], arr[0] + 1, arr[0] + 2, arr[0] + 3, arr[0] + 4))
	{
		for (int i = 1; i < 13; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				scanf("%d", arr[i] + j);
			}
		}
		init_memo();
		printf("%d\n", dp(0));
	}
	return 0;
}
*/
