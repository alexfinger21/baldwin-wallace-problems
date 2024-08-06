#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        string t;

        cin >> s >> t;

        ll start = 0;

        vector<int> indices;

        for (int i = 0; i<s.size(); ++i) {
            if (s[i] == t[start] || s[i] == '?') {
                indices.push_back(i);
                ++start;

                if (start == t.size()) {
                    break;
                }
            }
        }

        if (indices.size() == t.size()) {
            cout << "YES\n";

            start = 0;

            for (int i = 0; i<s.size(); ++i) {
                if (i != indices[start]) {
                    if (s[i] == '?') {
                        s[i] = 'a';
                    }
                } else {
                    s[i] = t[start];
                    ++start;
                }
            }

            cout << s << '\n';
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
