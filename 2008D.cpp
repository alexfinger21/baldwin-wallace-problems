#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        vector<int> f(n);

        for (int i = 0; i<n; ++i) {
            cin >> p[i];
            --p[i];
        }

        string s;
        cin >> s;

        set<int> covered; 

        for (int i = 0; i<n; ++i) {
            if (!covered.count(i)) {
                int ps = i;
                set<int> covered2;
                covered2.insert(ps);
                int c = s[ps] == '0' ? 1 : 0;
                ps = p[ps];

                while (!covered2.count(ps)) {
                    //cout << "hello " << ps << ' ' << s[ps] << '\n';
                    if (s[ps] == '0') {
                        ++c;
                    }
                    covered2.insert(ps);
                    ps = p[ps];
                }

                for (auto x : covered2) {
                    covered.insert(x);
                    f[x] = c;
                }
            }

            cout << f[i] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
