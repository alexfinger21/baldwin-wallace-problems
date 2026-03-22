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
        vector<int> indices(n+1);


        for (int i = 0; i<n; ++i) {
            cin >> a[i];

            indices[a[i]] = i;
        }

        vector<int> a_sorted(a);
        sort(a_sorted.begin(), a_sorted.end());

        priority_queue<int> peaks;
        vector<int> smaller_left(n);
        vector<int> smaller_right(n);

        for (int i = 0; i<n; ++i) {
            if (i > 0 && i < n-1 && a[i-1] < a[i] && a[i+1] < a[i]) {
                peaks.push(a[i]);
            }
        }

        int res = 0;

        while (!peaks.empty()) {
            int t = peaks.top();
            int l_count = 0;
            int r_count = 0;

            if (indices[t] != -1) {
                // cout << "peak: " << t << endl;
                for (int i = 0; i<n; ++i) {
                    if (a_sorted[i] == t) {
                        break;
                    }
                    
                    if (indices[a_sorted[i]] != -1) {
                        // cout << "found!" << endl;
                        if (indices[a_sorted[i]] < indices[t]) {
                            smaller_left[l_count] = a_sorted[i];
                            ++l_count;
                        } else {
                            smaller_right[r_count] = a_sorted[i];
                            ++r_count;
                        }
                    }
                }

                // cout << l_count << ' ' << r_count << endl;

                if (l_count < r_count) {
                    for (int i = 0; i<l_count; ++i) {
                        indices[smaller_left[i]] = -1;
                    }
                } else {
                    for (int i = 0; i<r_count; ++i) {
                        indices[smaller_right[i]] = -1;
                    }
                }

                res += min(r_count, l_count);
            }

            peaks.pop();
        }

        cout << res << '\n';
    }

    return 0;
}
