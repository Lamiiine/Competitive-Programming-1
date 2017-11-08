#include <bits/stdc++.h>
using namespace std;
char ans[1 << 22];
int idx = 0;
int arr[200010];
bool taken[200010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	bool first = true;
	for (int i = 0; i < n; ++i) {
		if (!taken[i]) {
			if (!first)
				ans[idx++] = ',';
			first = false;
			int j = i;
			while (j + 1 < n && !taken[j + 1] && arr[j + 1] - arr[j] == 1) {
				++j;
			}
			if (j != i) {
				sprintf(ans + idx, "%d", arr[i]);
				while(ans[idx]) {
					++idx;
				}
				ans[idx++] = '-';
				sprintf(ans + idx, "%d", arr[j]);
				while(ans[idx]) {
					++idx;
				}
				for (int k = i; k <= j; ++k)
					taken[k] = true;
			}
			else {
				while ((j + 1 < n && !taken[j + 1] && arr[j + 1] - arr[j] == 2) || (j + 2 < n && !taken[j + 2] && arr[j + 2] - arr[j] == 2)) {
					if (j + 1 < n && !taken[j + 1] && arr[j + 1] - arr[j] == 2)
						++j;
					else
						j += 2;
				}
				if (j != i) {
					sprintf(ans + idx, "%d", arr[i]);
					while(ans[idx]) {
						++idx;
					}
					ans[idx++] = arr[i] & 1 ? '#' : '%';
					sprintf(ans + idx, "%d", arr[j]);
					while(ans[idx]) {
						++idx;
					}
					for (int k = i; k <= j;) {
						taken[k] = true;
						if (!taken[k + 1] && arr[k + 1] - arr[k] == 2)
							++k;
						else
							k += 2;
					}
				}
				else {
					sprintf(ans + idx, "%d", arr[i]);
					while(ans[idx]) {
						++idx;
					}
				}
			}
		}
	}
	printf("%s\n", ans);
	return 0;
}

