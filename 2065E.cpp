#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        if (k > (max(n, m)) || k < abs(n - m)) {
            cout << "-1\n";
            continue;
        }

        string res = "";
        

        if (n > m) {
            for (int i = 0; i<k; ++i) {
                res += '0';
                --n;
            }

            while (m > 0 || n > 0) {
                if (m > 0) {
                    res += "1";
                    --m;
                }

                if (n > 0) {
                    res += '0';
                    --n;
                }
            }
        } else {
            for (int i = 0; i<k; ++i) {
                res += '1';
                --m;
            }

            while (m > 0 || n > 0) {
                if (n > 0) {
                    res += '0';
                    --n;
                }
                if (m > 0) {
                    res += "1";
                    --m;
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}
