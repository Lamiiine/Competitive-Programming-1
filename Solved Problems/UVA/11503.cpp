#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>
#define MAX 100005
using namespace std;
int p[MAX];
int counter;
map<string, int> m;
int Count[MAX];

inline int parent(const int i){
	return (p[i] == i)?i:p[i] = parent(p[i]);
}
inline void unite(const int x, const int y){
	p[parent(x)] = parent(y);
}
inline int index(const char * s){
	if (m.find(s) != m.end()) return m[s];
	return m[s] = counter++;
}
int main(){
	int TC;
	scanf("%d", &TC);
	while(TC--){
		counter = 0;
		int n;
		scanf("%d", &n);
		int x, y;
		char a[30], b[30];
		for (int i = 0; i < MAX; ++i) p[i] = i, Count[i] = 1;
		int X, Y;
		while(n--){
			scanf("%s%s", a, b);
			x = index(a);
			y = index(b);
			if ((X = parent(x)) == (Y = parent(y))) printf("%d\n", Count[X]);
			else {
				printf("%d\n", Count[X]+= Count[Y]);
				p[Y] = X;
			}
		}
		m.clear();
	}
	return 0;
}