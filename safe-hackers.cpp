#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    int tc = t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> a(n, vector<int>(n));

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                cin >> a[i][j];
            }
        }

        int c;
        cin >> c;

        bool flag = false;

        for (int i = 0; i<c; ++i) {
            vector<int> vals;

            string ch = "";
            cin >> ch;

            int c1 = -1, c2 = -1;


            while (!(ch == "*" || ch == "+" || ch == "-" || ch == "/")) {
                if (c1 == -1) {
                    c1 = stoi(ch);
                } else {
                    c2 = stoi(ch);
                    vals.push_back(a[c1][c2]);
                    c1 = -1;
                    c2 = -1;
                }


                cin >> ch;
            }

            int res;
            cin >> res;

            if (ch == "*") {
                int tres = 1;

                for (auto x : vals) {
                    tres *= x;
                }

                if (tres != res) {
                    flag = true;
                }
            } else if (ch == "/") {
                int mn = min(vals[0], vals[1]);
                int mx = max(vals[1], vals[0]);

                if ((mx / mn) != res) {
                    flag = true;
                }
            } else if (ch == "-") {
                int mn = min(vals[0], vals[1]);
                int mx = max(vals[1], vals[0]);

                if ((mx - mn) != res) {
                    flag = true;
                }
            } else if (ch == "+") {
                int tres = 0;

                for (auto x : vals) {
                    tres += x;
                }

                if (tres != res) {
                    flag = true;
                }
            } 
        }

        cout << "Case " << tc - t << ": ";
        if (flag) {
            out << "Solution is incorrect.\n"; 
        } else {
            out << "Solution is correct.\n"; 
        }
    }

    return 0;
}
