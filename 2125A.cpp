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

        string res = "";
        
        int nc = 0, tc = 0, fc = 0; 

        for (int i = 0; i<s.size(); ++i) {
            if (s[i] != 'F' && s[i] != 'T' && s[i] != 'N') {
                res += s[i];
            } else {
                if (s[i] == 'F') {
                    ++fc;
                }
                if (s[i] == 'N') {
                    ++nc;
                }
                if (s[i] == 'T') {
                    ++tc;
                }
            }
        }

        for (int i = 0; i<tc; ++i) {
            res += 'T';
        }

        for (int i = 0; i<nc; ++i) {
            res += 'N';
        }
        
        for (int i = 0; i<fc; ++i) {
            res += 'F';
        }

        cout << res << '\n';
    }

    return 0;
}
