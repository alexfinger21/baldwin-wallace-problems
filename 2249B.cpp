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

        vector<int> a(n - 1);

        bool f_f{false};

        for (int i = 0; i<n-1; ++i) {
            cin >> a[i];

            if (a[i] == n) {
                f_f = true;
            }
        }

        if (f_f) {
            cout << "0\n";
            continue;
        }

        int prefix_idx = -1;
        int suff_idx = n-1;

        int prev = a[0];

        for (int i = 0; i<n-1; ++i) {
            if (prev <= a[i]) {
                prefix_idx = i;
                prev = a[i];
            } else {
                break;
            }
        }

        prev = a[n-2];

        for (int i = n-2; i>=0; --i) {
            if (prev <= a[i]) {
                suff_idx = i;
                prev = a[i];
            } else {
                break;
            }
        }

        int idx_a = 0;
        int idx_b = n - 2;
        int i = 0; 

        vector<bool> seen(n + 1, false);
        ll res = 1;

        while (idx_a <= prefix_idx || idx_b >= prefix_idx + 1) {
            int val;

            if (idx_a <= prefix_idx && (idx_b < prefix_idx + 1 || a[idx_a] <= a[idx_b])) {
                val = a[idx_a];
                idx_a++;
            } else {
                val = a[idx_b];
                idx_b--; 
            }

            if (seen[val]) {
                ll choices = val - i;
                if (choices <= 0) {
                    res = 0;
                    break;
                }
                res = (res * choices) % 998244353;
            } else {
                seen[val] = true;
            }

            i++; 
        }

        int overlap_count = 0;
        ll total_occur = 0;

        vector<int> right_freq(n + 1, 0), left_freq(n + 1, 0);
        for (int x : a) {
            right_freq[x]++;
        }

        for (int c = 0; c <= n - 1; ++c) {
            if (c >= suff_idx && c <= prefix_idx + 1) {
                bool valid = true;
                
                if (c > 0 && c < n - 1 && a[c - 1] == a[c]) {
                    valid = false;
                }
                if (overlap_count > 0) {
                    valid = false;
                }

                if (valid) {
                    total_occur++;
                }
            }

            if (c < n - 1) {
                int val = a[c];
                if (left_freq[val] > 0 && right_freq[val] > 0) overlap_count--;

                right_freq[val]--;
                left_freq[val]++;

                if (left_freq[val] > 0 && right_freq[val] > 0) overlap_count++;
            }
        }

        ll super_res = (total_occur % 998244353 * res) % 998244353;
        cout << super_res << '\n';
    }

    return 0;
}
