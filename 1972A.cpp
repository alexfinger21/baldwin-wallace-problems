#include <iostream>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int len;
        cin >> len;

        int a[len];
        int b[len];

        int res = 0;

        for (int i = 0; i<len; ++i) {
            int n;
            cin >> n;

            a[i] = n;
        }

        int idx = 0;

        for (int i = 0; i<len; ++i) {
            int n;
            cin >> n;

            b[i] = n;

            if (n < a[idx]) {
                ++res;
            } else {
                ++idx;
            }
        }
        
        cout << res << '\n';

    }

    return 0;
}
