#include<stdio.h>
#include<string.h>
#define MAX 1024005
#define left(s) (s << 1)
#define right(s) ((s << 1) + 1)
#define avg(a, b) ((a + b) >> 1)
using namespace std;
int st[MAX << 2];
char a[MAX];	// my array of zeros and ones
enum operation :char{ N = 0, F = 1, S = 2, R = 3 }lazy[MAX << 2];	// nothing, set, reset, flip
// S ^ 1 = R; R ^ 1 = S;
int counter;
void flip(operation & op){
	switch (op){
	case N: op = F; break;
	case F: op = N; break;
	case S: op = R; break;
	case R: op = S; break;
	}
}
void propagate(int p, int l, int r){
	// update value of st[p] and lazy[p]
	operation o = lazy[p];
	switch (o){
	case N: return;
	case S:st[p] = r - l + 1; break;
	case R:st[p] = 0; break;
	case F:st[p] = r - l + 1 - st[p]; break;
	}
	// if you have children
	if (l != r){
		if (o == F)
			flip(lazy[left(p)]), flip(lazy[right(p)]);
		else
			lazy[left(p)] = lazy[right(p)] = o;
	}
	// your node doesn't need updating
	lazy[p] = N;
}
void build(int p, int l, int r){
	lazy[p] = N;
	if (l == r){
		st[p] = int(a[l] == '1');
		return;
	}
	build(left(p), l, avg(l, r));
	build(right(p), avg(l, r) + 1, r);
	st[p] = st[left(p)] + st[right(p)];
}
int i, j;		// boundaries of my range
operation o;	// update operation
void update(int p, int l, int r){
	// get correct value of your node
	// propagate the laziness to your children
	propagate(p, l, r);
	// if all outside your query range
	if (r < i || j < l)
		return;	// do nothing
	if (l == r){
		switch (o){
		case F: st[p] ^= 1; break;
		case R: st[p] = 0; break;
		case S: st[p] = 1; break;
		}
		return;
	}
	// if all inside my query range
	if (l >= i && r <= j){
		switch (o){
		case S: st[p] = (r + 1) - l; lazy[left(p)] = lazy[right(p)] = S; break;
		case R: st[p] = 0; lazy[left(p)] = lazy[right(p)] = R; break;
		case F: st[p] = (r + 1) - l - st[p]; flip(lazy[left(p)]); flip(lazy[right(p)]); break;
		}
		return;
	}
	update(left(p), l, avg(l, r));
	update(right(p), avg(l, r) + 1, r);
	st[p] = st[left(p)] + st[right(p)];
}
int rsq(int p, int l, int r){
	// if all outside your query range
	if (r < i || j < l)
		return -1;	// return an invalid value
	// get correct value of your node
	// propagate the laziness to your children
	propagate(p, l, r);
	// if all inside your query range
	if (l >= i && r <= j)
		// return value of current tree node
		// you know it has obtained its true value because propagate() has been called
		return st[p];
	// query left subtree, which has correct value since laziness has been propagated to it
	int p1 = rsq(left(p), l, avg(l, r));
	// query right subtree, which has correct value since laziness has been propagated to it
	int p2 = rsq(right(p), avg(l, r) + 1, r);
	if (p1 == -1) return p2;
	if (p2 == -1) return p1;
	return p1 + p2;
}
int main(void){
	int TC;
	scanf("%d", &TC);
	for (int tc = 1; tc <= TC; ++tc){
		printf("Case %d:\n", tc);
		counter = 0;
		int q; scanf("%d", &q);	// read number of segments
		while (q--){
			int x;
			scanf("%d", &x);	// read number of times segment should be repeated
			int init = counter;	// starting index of first repition of current segment
			scanf("%s", a + init);
			int len = strlen(a + init);	// length of segment
			counter += len;
			while (--x){
				memcpy(a + counter, a + init, len);
				counter += len;
			}
		}
		a[counter] = 0;
		build(1, 0, counter - 1);
		char s[2];
		scanf("%d", &q); 	// number of queries
		int Q = 0;
		while (q--){
			scanf("%s%d%d", s, &i, &j);
			switch (*s){
			case 'F':o = S; update(1, 0, counter - 1); break;
			case 'I':o = F; update(1, 0, counter - 1); break;
			case 'E':o = R; update(1, 0, counter - 1); break;
			case 'S':printf("Q%d: %d\n", ++Q, rsq(1, 0, counter - 1)); break;
			}
		}
	}
	return 0;
}

