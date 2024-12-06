#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() < 2 || s2.size() < 2) {
        cout << "-1\n";
        return 0;
    }

    string abbr = "";
    int l = 1e9;

    set<char> uniq;

    for (int i = 1; i<s1.size(); ++i) {
        if (!uniq.count(s1[i])) {
            uniq.insert(s1[i]);
            int findR = s2.rfind(s1[i], s2.size() - 2);

            if (findR != string::npos && l > (max(2, i+1) + s2.size() - findR-1)) {
                l = max(2,i+1) + s2.size() - findR - 1;
                //cout << i << ' ' << findR << endl;
                abbr = s1.substr(0, max(2, i+1)) + s2.substr(findR+1, s2.size() - findR);
            }
            findR = s2.rfind(s1[i], findR+1);
        }
    }

    if (l != 1e9) {
        cout << abbr << '\n';
    } else {
        cout << "-1\n";
    }

    return 0;
}
