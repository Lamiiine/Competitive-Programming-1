#define numElements 1005
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
int counter;
pair<int, pair<int, int> > elephant[numElements];	// w, s, i

int state[numElements][numElements];

int LIS(int ind, int prevInd){
	if (ind >= counter) return 0;
	// check if computed
	if (state[ind][prevInd] != -1)
		return state[ind][prevInd];

	int res = LIS(ind + 1, prevInd);
	if (elephant[ind].first > elephant[prevInd].first && elephant[ind].second.first < elephant[prevInd].second.first)
	{
		state[ind][prevInd] = max(res, LIS(ind + 1, ind) + 1);
		return state[ind][prevInd];
	}
	state[ind][prevInd] = res;

	return state[ind][prevInd];
}

vector<int> res;
void getPath(int ind, int prevInd, int val)
{
	if (ind >= counter) return;
	if (LIS(ind + 1, prevInd) == val)
	{
		getPath(ind + 1, prevInd, val);
	}
	// remove else if you want to get all the paths, then store each path in a vector of vectors
	else if (LIS(ind + 1, ind) + 1 == val)
	{
		res.push_back(elephant[ind].second.second);
		getPath(ind + 1, ind, val-1);
	}
}

int main(){
	// freopen("Input.txt", "r", stdin);
	// freopen("Output.txt", "w", stdout);
	
	memset(state, 0xFF, sizeof state);
	
	counter = 0;
	elephant[counter++] = make_pair(0, make_pair(0x7FFF, 0));
	int w, s;
	while (cin >> w >> s){
		elephant[counter] = make_pair(w, make_pair(s, counter));
		counter++;
	}
	sort(elephant, elephant + counter);
	int fin = LIS(1, 0);

	getPath(1, 0, fin);

	cout << fin << endl;
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
}
