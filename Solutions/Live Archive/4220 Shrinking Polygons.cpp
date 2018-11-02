#include<bits/stdc++.h>
#define MAX 10005
using namespace std;
int mask[1 << 19];
int circum;
// is there a polygon starting at index 'start' with side length 'len'?
inline bool is_found(int i){
	return mask[i >> 5] & (1 << (i & 0x1F));
}
inline void found(int i){
	mask[i >> 5] |= (1 << (i & 0x1F));
}
inline bool valid(const int start, const int len) {
	int j;
	for (j = start; j < circum; j += len)
		if (!is_found(j)) return false;
	return (j % circum) == start;
}
int main(void) {
	// freopen("Input.txt", "r", stdin);
	for (int k; scanf("%d", &k), k; ) {
		memset(mask, 0, sizeof mask);
		found(circum = 0);
		for (int i = 0, x; i < k; ++i)
			scanf("%d", &x), found(circum += x);
		bool flag = false;
		// Bind your limits as much as possible!
		for (int len = 1; len <= (circum/3) && !flag; ++len)
			// Only test on the divisors!
			if (circum % len == 0)
				for (int i = 0; i < len && !flag; ++i)
					if (valid(i, len))
						flag = true, printf("%d\n", k - circum/len);
		if (!flag)
			printf("-1\n");
	}
	return 0;
}

