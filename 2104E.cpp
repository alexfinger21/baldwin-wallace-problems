#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> dp(n);

    map<char, int> occur;

    for (int i = n-1; i>=0; --i) {

        if (occur.size() < k) {
            dp[i] = 0;
            for (auto &[k, v] : occur) {
                if (occur[k] != 0) {
                    occur[k] = 1;
                }
            }
        } else {
            int mn = n+1;
            for (auto &[k, v] : occur) {
                mn = min(mn, v);
            }
            dp[i] = mn;
            for (auto &[k, v] : occur) {
                if (occur[k] != mn) {
                    occur[k] = mn + 1;
                }
            }
        }

        if (!occur.count(s[i])) {
            occur[s[i]] = 1;
        } else {
            ++occur[s[i]];
        } 
    }

    map<char, int> first;


    for (int i = 0; i<n; ++i) {
        if (!first.count(s[i])) {
            first[s[i]] = i;
        } 
    }

    int q;
    cin >> q;

    map<int, map<char, int>> prevs;

    for (int i = 0; i<q; ++i) {
        string t;
        cin >> t;

        if (!first.count(t[0])) {
            cout << "0\n";
            continue;
        }
        int l_i = first[t[0]];
        bool f = false;

        for (int j = 1; j<t.size(); ++j) {
            int idx = !(prevs[l_i].count(t[j])) ? (l_i + 1) : prevs[l_i][t[j]];

            if (first[t[j]] >= idx) {
                idx = first[t[j]];
            } else if (idx == l_i + 1) {
                while (idx < n) {
                    if (s[idx] == t[j]) {
                        break;
                    }
                    ++idx;
                }
            }
            
            prevs[l_i][t[j]] = idx;

            if (idx != n) {
                l_i = idx; 
            } else {
                f = true;
                break;
            }
        } 

        if (f) {
            cout << "0\n";
            continue;
        }
        
        cout << (1 + dp[l_i]) << '\n';
    }

    return 0;
}
