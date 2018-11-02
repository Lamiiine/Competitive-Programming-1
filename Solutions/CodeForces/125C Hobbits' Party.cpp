#include<bits/stdc++.h>
using namespace std;
vector<int>adj[150];
inline void construct_graph(const int size){
	int counter = 1;
	for (int i = 1; i <= size; ++i)
		for (int j = i + 1; j <= size; ++j)
			adj[i].push_back(counter), adj[j].push_back(counter), ++counter;
}
int main(void){
	vector<int>v;
	v.push_back(3);
	for (int i = 4; v.back() < 10000; ++i)
		v.push_back(i*(i-1)/2);
	int n;
	scanf("%d", &n);
	int ind = upper_bound(v.begin(), v.end(), n) - v.begin();
	ind += 2;
	printf("%d\n", ind);
	construct_graph(ind);
	for (int i = 1; i <= ind; ++i)
	{
		vector<int>&v = adj[i];
		for (int j = 0; j < v.size(); ++j)
			printf("%d%c", v[j], j == v.size() - 1 ? '\n' : ' ');
	}
	return 0;
}

