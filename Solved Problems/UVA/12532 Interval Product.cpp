#include<stdio.h>
#include<string.h>
#define MAX 100005
#define LSOne(s) (s & (-s))
using namespace std;
int n, k;
int neg[MAX];
int zero[MAX];
int b[MAX];	// my array
void init(void){
	// Fenwick trees for number of zeros and negatives respectively
	memset(zero, 0, (n+2)*sizeof zero[0]);
	memset(neg, 0, (n + 2)*sizeof neg[0]);
}
inline int rsq(int * a, int i){	// range sum query from 1 to i on array a
	int sum = 0;
	for (;i; i -= LSOne(i))
		sum += a[i];
	return sum;
}
// add v to a[i]
inline void update(int * a, int i, int v){
	// YOUR ONLY BUG WAS WRITING 'LSOne(k)' INSTEAD OF 'LSOne(i)'
	for (; i <= n; i += LSOne(i))
		a[i] += v;
}
inline void change(int i, int v){
	int temp = b[i];
	b[i] = v;
	bool zero_prev = (temp == 0);
	bool zero_cur = (v == 0);
	bool neg_prev = (temp < 0);
	bool neg_cur = (v < 0);
	if (zero_prev ^ zero_cur)
		update(zero, i, zero_cur ? 1 : -1);
	if (neg_prev ^ neg_cur)
		update(neg, i, neg_cur ? 1 : -1);
}
inline int rsq(int * a, int i, int j){
	return rsq(a, j) - rsq(a, i - 1);
}
int main(void){
	// freopen("Input.txt", "r", stdin);
	while(scanf("%d%d", &n, &k) != EOF){
		init();
		for (int i = 1, x; i <= n; ++i)
		{
			scanf("%d", &x);
			b[i] = x;
			if (!x) update(zero, i, 1);
			else if (x < 0) update(neg, i, 1);
		}
		int i, j; char s[2];
		while(k--){
			scanf("%s%d%d", s, &i, &j);
			if (*s == 'C') change(i, j);
			else {
				printf("%c", rsq(zero, i, j) ? '0' : (rsq(neg, i, j) & 1) ? '-' : '+');
			}
		}
		printf("\n");
	}
	return 0;
}

