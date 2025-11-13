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
                int num = 1;
                for (int i = 0; i<k-1; ++i) {
                    if (num > n) {
                        num = 1;
                    }

                    while ((i == 0 && a[n-1] == num) || (uniq[0] == num)) {
                        ++num;
                        if (num > n) {
                            num = 1;
                        }
                    }


                    cout << num << ' ';
                    ++num;
                }
                cout << '\n';
            } else {
                map<int, int> bad;
                for (int i = 0; i<k && i<uniq.size(); ++i) {
                    cout << uniq[i] << ' ';
                    bad[uniq[i]] = 1;
                }

                for (int i = 0; i<(k-(int)(uniq.size())); ++i) {
                    if (bad[i+1]) {
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
