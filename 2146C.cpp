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

        string s;
        cin >> s;

        bool f = false;

        vector<int> good;
        int last = -1;
        vector<int> res(n);
        good.push_back(0);
        int tail = -3;

        for (int i = 0; i<n; ++i) {
            if (s[i] == '1') {
                if (i - last == 2) {
                    f = true;
                    break;
                }
                last = i;
                good.push_back(i+1);
                res[i] = i+1;
                tail = i;
            } 
        }

        if (f || (n-tail) == 2) {
            cout << "NO\n";
            continue;
        }

        good.push_back(n+1);
        for (int i = 0; i<good.size()-1; ++i) {
            int r = (good[i+1] - good[i]-1);
            for (int j = 0; j<r; ++j) {
                if (j == 0) {
                    res[good[i] + j] = good[i]+r;
                } else {
                    res[good[i] + j] = good[i]+j;
                }
            }
        }
        cout << "YES\n";

        for (auto x : res) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}
