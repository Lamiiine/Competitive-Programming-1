#include<bits/stdc++.h>
#define MAX 1024
using namespace std;
struct pokemon
{
	int x, y, t;	// coordinates and type
	pokemon(int _x, int _y, int _t):x(_x), y(_y), t(_t){}
	pokemon(){}
};
struct pokemon_index
{
	int x, y, t, i;
	pokemon_index(){}
	pokemon_index(int _x, int _y, int _t, int _i):x(_x), y(_y), t(_t), i(_i){}
};



int n, k;
int counter[105];	// how many types of each pokemon have been found!
pokemon arr[MAX];
pokemon_index arr_y[MAX];
int mid;




inline bool cmp_x(const pokemon & a, const pokemon & b)
{
	return a.x < b.x;
}
inline bool cmp_y(const pokemon_index & a, const pokemon_index & b)
{
	return a.y < b.y;
}
inline void read()
{
	scanf("%d%d", &n, &k);
	for (int x, y, t, i = 0; i < n; ++i)
		scanf("%d%d%d", &x, &y, &t), arr[i] = pokemon(x, y, t), arr_y[i] = pokemon_index(x, y, t, i);
}
inline bool can(const int l, const int r)
{
	if (r - l < k)
		return false;
	memset(counter, 0, sizeof counter);
	int cur_count = 0;
	int i = 0, j = 0;
	while(i < n && j < n)
	{
		while(j < n && arr[j].y <= arr[i].y + mid)
		{
			// include j in your set
			if (arr_y[j].i >= l && arr_y[j].i < r)
				if (counter[arr_y[j].t]++ == 0)
					++cur_count;
			++j;
		}
		if (cur_count == k) return true;
		// exclude i from your set
		if (arr_y[i].i >= l && arr_y[i].i < r)
			if (--counter[arr_y[i].t] == 0)
				--cur_count;
		++i;
	}

	return false;
}
inline bool can()
{
	int i = 0, j = 0;
	while(i < n && j < n)
	{
		while(j < n && arr[j].x <= arr[i].x + mid)
			++j;
		if (can(i, j)) return true;
		++i;
	}

	return false;
}
inline int solve()
{
	int lo = 1, hi = 2000000000;
	while(lo != hi)
	{
		mid = lo + ((hi - lo) >> 1);
		if (can())
			hi = mid;
		else lo = mid + 1;
	}
	return lo;
}
int main()
{
	int TC; scanf("%d", &TC);
	while(TC--)
	{
		read();
		sort(arr, arr + n, cmp_x);
		sort(arr_y, arr_y + n, cmp_y);
		printf("%d\n", solve());
	}
	return 0;
}
/*
2
5 2
0 0 1
0 1 1
0 2 1
2 0 2
2 1 2
3 3
0 0 1
1 1 2
2 2 3
 */

