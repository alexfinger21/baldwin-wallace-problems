#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m;

        cin >> n >> m;

        int a[n][m];
        int b[n][m];


        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<m; ++j) {
                char num;
                cin >> num;

                a[i][j] = num - '0';
            }
        }

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<m; ++j) {
                char num;
                cin >> num;

                b[i][j] = num - '0';
            }
        }

        bool found = false;

        for (int i = 0; i<n; ++i) {
            int s1 = 0;
            int s2 = 0;

            for (int j = 0; j<m; ++j) {
                s1 += a[i][j];
                s2 += b[i][j];
            }

            if ((s1 % 3) == (s2 % 3)) {

            } else {
                found = true;
                break;
            }
        }

        if (!found) {
            for (int j = 0; j<m; ++j) {
                int s1 = 0;
                int s2 = 0;

                for (int i = 0; i<n; ++i) {
                    s1 += a[i][j];
                    s2 += b[i][j];
                }

                if ((s1 % 3) == (s2 % 3)) {

                } else {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}
