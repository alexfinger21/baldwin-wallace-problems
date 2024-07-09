#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int len;
        cin >> len;

        string r = "";
        string enc;
        string res = "";

        cin >> enc;

        set<char> uniq;

        for (int i = 0; i<enc.size(); ++i) {
            uniq.insert(enc[i]);
        }

        for (auto x : uniq) {
            r += x;
        }

        for (int i = 0; i<enc.size(); ++i) {
            int pos = r.find(enc[i]);
            res += r[r.size()-pos-1];
        }

        cout << res << '\n';
    }

    return 0;
}
