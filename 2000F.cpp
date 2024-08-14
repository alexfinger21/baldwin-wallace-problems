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

        vector<pair<int, int>> rows;
        int rcsum = 0;

        for (int i = 0; i<n; ++i) {
            int w, h;
            cin >> w >> h;

            rcsum+=w+h;
            rows.push_back(make_pair(w, h));
        }

        if (rcsum < k) {
            cout << "-1\n";
            continue;
        }

        sort(rows.begin(), rows.end(), [](auto &left, auto &right) {
            return min(left.second, left.first) < min(right.first, right.second);
        });

        int ops = 0;
        int colored = 0;
        for (int i = 0; i<rows.size(); ++i) {
            if (colored < k) {
                auto pr = rows[i];
                cout << pr.first << ' ' << pr.second << endl;
                int small = min(pr.first, pr.second);
                int big = max(pr.first, pr.second);

                int diff = big-small;

                ops += min(k-colored, diff+1)*small;
                colored += min(k-colored, diff+1);
                cout << colored << endl;

                if (colored < k) {
                    for (int j = small-1; j>0; --j) {
                        ops += j*min(k-colored, 2);
                        colored += min(k-colored, 2);
                        if (j == 1) {
                            ++colored;
                        }
                        cout << ops << endl;
                        if (colored > k) {
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
        }

        cout << ops << endl;
    }

    return 0;
}
