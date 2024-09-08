#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int m, n;
        cin >> n >> m;

        string s1;
        string s2;

        cin >> s1 >> s2;

        int c = 0;

        int sInd = 0;
        for (int i = 0; i<s2.size(); ++i) {
            if (sInd < s1.size() && s1[sInd] == s2[i]) {
                ++c;
                ++sInd;
            }
        }

        cout << c << '\n';
    }

    return 0;
}
