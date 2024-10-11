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
        
        vector<int> a(n);
        vector<int> b(n);
        map<int, int> uniq;

        int uniqC = 0;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
            
            if (uniq.count(a[i]) && uniq[a[i]] != 2) {
                //cout << uniq[a[i]] << endl;
                ++uniqC;
                uniq[a[i]] = 2;
            } else if (uniq[a[i]] != 2) {
                uniq[a[i]] = 1;
            }
        }

        //cout << uniqC << endl;

        if (uniqC > 1) {
            int cs = 1;
            for (int i = 0; i<n; ++i) {
                if (uniq[a[i]] == 2 && cs <= 2) {
                    uniq[a[i]] = -1;
                    b[i] = cs;
                    ++cs;
                } else {
                    b[i] = 3;
                }
            }
            for (auto x : b) {
                cout << x << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
