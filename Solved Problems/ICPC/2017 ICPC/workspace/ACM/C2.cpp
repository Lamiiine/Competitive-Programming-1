#include <bits/stdc++.h>
using namespace std;

#define N 105

vector<int>adj[2*N];
int rgt[2*N], lft[2*N];
bool was[2*N];
bool match(int u){
	// for(int v : adj[u])
	for (int i = 0; i < adj[u].size(); ++i)
	{
		int v = adj[u][i];
		if(was[v]) continue;
		was[v] = 1;
		if(lft[v] == -1 || match(lft[v])){
			lft[v] = u;
			rgt[u]=v;
			return true;
		}
	}
	return false;
}
int runMatching(){
	int cc = 0;
	memset(rgt, -1, sizeof rgt);
	memset(lft, -1, sizeof lft);
	for(int u = 0; u < N; ++u) {
		memset(was, 0, sizeof was);
		if(match(u)) cc++;
	}
	return cc;
}

long long arr[N][N], maxRow[N], maxCol[N];
bool usedCol[N];

int main() {
	int r, c;
	cin >> r >> c;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++){
			cin >> arr[i][j];
			maxRow[i] = max(maxRow[i], arr[i][j]);
			maxCol[j] = max(maxCol[j], arr[i][j]);
		}
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			if(arr[i][j] && maxRow[i] == maxCol[j]){
				adj[i].push_back(j+N);
				adj[N+j].push_back(i);
			}
	runMatching();

	long long tot = 0;
	long long count = 0;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++){
			if(arr[i][j])
				count++;
			tot += arr[i][j];
		}

	for(int i = 0; i < r; i++){
		if(maxRow[i])
			count += maxRow[i]-1;
		if(rgt[i] != -1)
			usedCol[rgt[i]-N] = true;
	}
	for(int j = 0 ; j < c; j++){
		if(usedCol[j]) continue;
		if(maxCol[j])
			count += maxCol[j]-1;
	}
	cout << tot - count << endl;
	return 0;
}
