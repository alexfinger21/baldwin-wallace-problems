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

        map<char, int> occurs;

        string s;
        cin >> s;

        for (int i = 0; i<s.size(); ++i) {
            if (occurs.count(s[i])) {
                ++occurs[s[i]];
            } else {
                occurs[s[i]] = 1;
            }
        }

        string res = "";

        for (int i = 0; i<n; ++i) {
            for (auto j = occurs.begin(); j!=occurs.end(); ++j) {
                if (j->second > 0) {
                    --(*j).second;
                    res += j->first;
                    ++i;
                }
            }
            --i;
        }

        cout << res << '\n';
    }

    return 0;
}
