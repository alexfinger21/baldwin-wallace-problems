#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int len;
        string s;

        cin >> len >> s;

        int c1 = 0, c0 = 0;
        bool found = false;

        for (int i = 0; i<len; ++i) {
            if (s[i] == '0') {
                c1 = c1-1;
                c0 = 1;

                int c = 0;
                for (int j = 0; j<len; j += c1) {
                    if (s[j] == '1') {
                        ++c;
                    } else {
                        break;
                    }
                }

                if (c == c1) {
                    c1 = 1;
                } else {
                    c1 = 0;
                }
                break;
            } else if (!c0) {
                ++c1;
            }
        }

        if (c1 == 1 || (c1 == 4)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
