#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    vector<string> a(n);
    set<char> uniq;

    for (int i = 0; i<n; ++i) {
        cin >> a[i];
    }

    ll res = 1e9;

    bool fnd = false;
    for (int i = 0; i<a[0].size(); ++i) {
        ll rs = 0;
        if (fnd) {
            break;
        }
        for (auto s : a) {
            if (s == a[0]) {
                rs += i;
            } else {
                int f = s.find(a[0][i]);
                int lr = -1;
                while (f != string::npos) {
                    int j;
                    for (j = 1; j<a[0].size(); ++j) {
                        if (a[0][(i+j)%a[0].size()] != s[(f+j)%a[0].size()]) {
                            break;
                        }
                    }

                    if (j == a[0].size()) {
                        lr = lr != -1 ? min(lr, f) : f;
                        break;
                    }
                    f = s.find(a[0][i], f+1);
                }
                if (lr == -1) {
                    fnd = true;
                    break;
                }
                rs += lr;
            }
        }
        res = min(res, rs);
    }

    if (!fnd) {
        cout << res << '\n';
    } else {
        cout << "-1\n";
    }
    
   
    return 0;
}
