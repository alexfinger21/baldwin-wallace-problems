#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int a[k];

        for (int i = 0; i<k; ++i) {
            int num;
            cin >> num;
            a[i] = num;
        }

        int bk = 0;

        for (int i = 1; i<k; ++i) {
            if (a[i] > a[bk]) {
                bk = i;
            }
        }

        long long res = 0;

        for (int i = 0; i<k; ++i) {
            if (i != bk) {
                res += (long long)(2)*a[i] - 1;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
