#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n); //0, 1, 2
        vector<string> b(n);

        for (int i = 0; i<n; ++i) {
            a[i] = vector<int>(m);
            for (int j = 0; j<m; ++j) {
                char c;
                cin >> c;
                b[i] += c;

                if (c == 'B') {
                    a[i][j] = 0;
                } else {
                    a[i][j] = 1;
                }
            }
        }


        for (int i = 1; i<m; ++i) {
            bool found = false;
            if (a[0][i] != a[0][0]) {
                found = true;
                for (int j = 1; j<n; ++j) {
                    if (a[j][0] != a[0][0]) {
                        a[0][0] = 2;
                        break;
                    }
                }

                if (found) {
                    break;
                }
            }
        } 

        for (int i = 1; i<m; ++i) {
            bool found = false;
            if (a[0][i] != a[0][m-1]) {
                found = true;
                for (int j = 1; j<n; ++j) {
                    if (a[j][m-1] != a[0][m-1]) {
                        a[0][m-1] = 2;
                        break;
                    }
                }

                if (found) {
                    break;
                }
            }
        } 

        for (int i = 0; i<m; ++i) {
            bool found = false;
            if (a[n-1][i] != a[n-1][0]) {
                found = true;
                for (int j = 0; j<n; ++j) {
                    if (a[j][0] != a[n-1][0]) {
                        a[n-1][0] = 2;
                        break;
                    }
                }

                if (found) {
                    break;
                }
            }
        } 

        for (int i = 0; i<m; ++i) {
            bool found = false;
            if (a[n-1][i] != a[n-1][m-1]) {
                found = true;
                for (int j = 0; j<n; ++j) {
                    if (a[j][m-1] != a[n-1][m-1]) {
                        a[n-1][m-1] = 2;
                        break;
                    }
                }

                if (found) {
                    break;
                }
            }
        } 

        if ((a[0][0] == 2 || a[0][m-1] == 2 || a[n-1][0] == 2 || a[n-1][m-1] == 2) || a[0][0] == a[n-1][m-1] || a[0][m-1] == a[n-1][0]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

    return 0;
}
