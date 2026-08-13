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

        int c_1 = 0, c_2 = 0, c_3 = 0;

        int stage = 0;
        bool appr = false;

        for (int i = 0; i<n; ++i) {
            cin >> a[i];

            if (a[i] == 1) {
                ++c_1;
            } else if (a[i] == 2)  {
                ++c_2;
            } else {
                ++c_3;
            }

            if (!appr) {
                if (!stage && i == 1) {
                    if (c_1) {
                        if (c_1 == c_3) {
                            ++stage;
                            c_1 = 0;
                            c_2 = 0;
                            c_3 = 0;
                        } else if (a[0] == 1) {
                            appr = true;
                            ++stage;
                        } else {
                            ++stage;
                            c_1 = 0;
                            c_2 = 0;
                            c_3 = 0;
                        }
                    }
                } else if (!stage) {
                    if (c_1 == (c_2+c_3)) {
                        ++stage;
                        c_1 = 0;
                        c_2 = 0;
                        c_3 = 0;
                    }
                } else {
                    if (c_3 <= (c_2+c_1)) {
                        appr = true;
                        c_1 = 0;
                        c_2 = 0;
                        c_3 = 0;
                    }
                }
            }
        }

        if (appr && (c_1 + c_2 + c_3) > 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
