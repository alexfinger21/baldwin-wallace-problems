#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int l, n;
        cin >> l >> n;

        vector<vector<int>> schedules(n);

        vector<int> res(1440);

        for (int i = 0; i<n; ++i) {
            int sch;
            cin >> sch;

            for (int j = 0; j<sch; ++j) {
                int start;
                int end;

                cin >> start >> end;

                if (res[end]) {
                    end = res[end] - 1;
                } 

                if (res[start]) {
                    start = res[start] - 1;
                }

                int k = start;

                while (k <= end && res[k] <= end) {
                    int new_k = k;

                    if ((res[k] == k + 1) || !res[k]) {
                        new_k = k + 1;
                    } else {
                        new_k = res[k] - 1;
                    }

                    res[k] = end + 1;

                    k = new_k;
                }
            }
        }

        int window_cnt = 0;
        bool found = false;

        for (int i = 0; i<res.size(); ++i) {
            if (!res[i]) {
                ++window_cnt;
            } else {
                // cout << i << endl;
                // cout << "res " << res[i] - 1 << endl;
                window_cnt = 0;

                if (i != res[i] - 1) {
                    i = res[i] - 2;
                }
            }

            if (window_cnt == l) {
                found = true;
                break;
            }
        }

        for (int i = 0; i<res.size(); ++i) {
            cout << res[i];
        }
        cout << endl;

        if (found) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}
