#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi A[3];
int n, m;
inline void init(void){
	for (int i = 0; i < 3; ++i)
		A[i].clear();
	vi & v = A[0];
	for (int i = n; i >= 1; --i)
		v.push_back(i);
}
inline void print(int i){
	printf("%c=>", (char)'A' + i);
	vi & v = A[i];
	if (!v.empty()) printf("  ");
	for (int j = 0; j < v.size(); ++j)
		printf(" %d", v[j]);
	printf("\n");
}
inline void print(void){
	for (int i = 0; i < 3; ++i)
		print(i);
	printf("\n");
}
inline void move(int n, int S, int T){
	if (!m) return;
	if (n != 1){
		int Aux = 3 - (T + S);
		move(n-1, S, Aux);
		move(1, S, T);
		move(n-1, Aux, T);
	}
	else{
		m--;
		vi & source = A[S];
		vi & destination = A[T];
		int x = source.back();
		source.pop_back();
		destination.push_back(x);
		print();
	}
}
int main(void){
	for(int tc = 1; scanf("%d%d", &n, &m), n || m; ++tc){
		printf("Problem #%d\n\n", tc);
		init();
		print();
		move(n, 0, 2);
	}
	return 0;
}

