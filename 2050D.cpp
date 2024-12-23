#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        for (int i = 1; i<s.size(); ++i) {
            int n = s[i] - '0';
            int j;
            for (j = i-1; j>=0; --j) {
                if (n - i+j > s[j] - '0') {
                    s[j+1] ^= s[j];
                    s[j] ^= s[j+1];
                    s[j+1] ^= s[j];
                } else {
                    break;
                }
            }

            s[j+1] = n - i + j + 1 + '0';
        }

        cout << s << '\n';
    }

    return 0;
}
