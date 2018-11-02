#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1100000;

bool is_prime[MAX + 1];
int pr[MAX + 1];

int pr_siz = 0;

int solve(vector <long long> arr) {
    int res = 0;
    vector <long long> div;
    for (int j = 0; j < pr_siz; ++j) {
        int e = 0;
        for (int i = 0; i < arr.size(); ++i) {
            while (arr[i] % pr[j] == 0) {
                arr[i] /= pr[j];
                ++e;
            }
        }
        res = max(res, e);
    }
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] > 1) {
            long long beg = 1, end = arr[i];
            while (beg + 1 < end) {
                long long mid = (beg + end) / 2;
                if (mid <= arr[i] / mid)
                    beg = mid;
                else
                    end = mid;
            }
            if (beg + 1 < arr[i] && (long long) beg * beg == arr[i]) {
                div.push_back(beg);
            }
                div.push_back(arr[i]);
        }
    }

    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); ++j) {
            long long r = __gcd(arr[i], arr[j]);
            if (r > 1) {
                div.push_back(r);
            }
        }
    }

    for (vector <long long>::const_iterator it = div.begin(); it != div.end(); ++it) {
        long long r = *it;
        int e = 0;
        for (int i = 0; i < arr.size(); ++i) {
            long long n = arr[i];
            while (n % r == 0) {
                n /= r;
                ++e;
            }
        }
        res = max(res, e);
    }
    return res;

}

int main() {
    freopen("hope.in", "rt", stdin);
    memset(is_prime, -1, sizeof is_prime);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 0; i < MAX; ++i)
        if (is_prime[i])
            pr[pr_siz++] = i;

    int T;
    scanf("%d", &T);

    while (T-- > 0) {
        int n;
        vector <long long> arr;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            long long r;
            scanf("%lld", &r);
            arr.push_back(r);
        }
        printf("%d\n", solve(arr));
    }
}