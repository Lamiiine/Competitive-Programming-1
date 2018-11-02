#include <bits/stdc++.h>
using namespace std;

pair<long long, int> maxRow[100];
long long maxCol[100], countt, m, n, arr[100][100], currCount;
bool used[100];

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] > maxRow[i].first) {
				maxRow[i].first = arr[i][j];
				maxRow[i].second = j;
			}
			maxCol[j] = max(maxCol[j], arr[i][j]);
			countt += arr[i][j];
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[i][j] != 0) {
				currCount++;
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		if (maxRow[i].first == 0)
			continue;
		bool placed = false;
		for (int j = 0; j < n; ++j) {
			if (maxRow[i].first == maxCol[j] && !used[j] && arr[i][j] != 0) {
				currCount += (maxCol[j] - 1);
				placed = true;
				used[j] = true;
				break;
			}
		}
		if (!placed) {
			currCount += (maxRow[i].first - 1);
		}
	}
	for (int j = 0; j < n; ++j) {
		if (!used[j] && maxCol[j] != 0) {
			currCount += (maxCol[j] - 1);
		}
	}
	cout << countt - currCount;
	return 0;
}
