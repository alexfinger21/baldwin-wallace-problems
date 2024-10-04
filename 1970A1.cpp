#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;

    vector<vector<char>> m(s.size());


    int prio = 0;
    for (int i = 0; i<s.size(); ++i) {
        m[prio].push_back(s[i]);
        if (s[i] == '(') {
            ++prio;
        } else {
            --prio;
        }
    }

    string res = "";

    for (auto x : m) {
        for (auto si = x.rbegin(); si != x.rend(); ++si) {
            res += *si;
        }
    }

    cout << res << '\n';

    return 0;
}
