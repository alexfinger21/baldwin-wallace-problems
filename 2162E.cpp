#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, k;

        cin >> n >> k;
        vector<int> a(n);
        set<int> elems;
        vector<int> uniq;
        for (int i = 0; i<n; ++i) {
            cin >> a[i];
            elems.insert(a[i]);
        }

        if (elems.size() == n) {
            for (int i = 0; i<k; ++i) {
                cout << a[i] << ' ';
            }
            cout << '\n';
        } else {
            for (int i = 1; i<=n; ++i) {
                if (!elems.count(i)) {
                    uniq.push_back(i);
                }
            }

            if (uniq.size() == 1) {
                cout << uniq[0] << ' ';
                int ltr = 0;
                for (int i = 0; i<k-1; ++i) {
                    if (ltr > 0 && a[ltr] == a[ltr-1]) {
                        ++ltr;
                    }
                    cout << a[ltr] << ' ';
                    ++ltr;
                }
                cout << '\n';
            } else {
                for (int i = 0; i<k && i<uniq.size(); ++i) {
                    cout << uniq[i] << ' ';
                }

                for (int i = 0; i<k-uniq.size(); ++i) {
                    if (find(uniq.begin(), uniq.end(), i+1) != uniq.end()) {
                        ++k;
                    } else {
                        cout << i+1 << ' ';
                    }
                }
                cout << '\n';
            }
        }

    }
    return 0;
}
