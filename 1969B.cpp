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


        ll res = 0;
        ll ones = 0;
        ll zeroes = 0;
        for (ll i = 0; i<s.size(); ++i) {
            if (s[i] == '0') {
                ++zeroes;
                if (ones) {
                    res += (ones+1);
                }
                zeroes = 0;
            } else {
                ++ones;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
