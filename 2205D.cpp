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

        vector<int> peaks;
        map<int, int> peak_idx;
        map<int, int> sorted_peak_idx;
        vector<int> smaller_left(n);
        vector<int> smaller_right(n);

        for (int i = 0; i<n; ++i) {
            if (i > 0 && i < n-1 && a[i-1] < a[i] && a[i+1] < a[i]) {
                peaks.push_back(a[i]);
                peak_idx[a[i]] = i;
            }
        }


        sort(peaks.begin(), peaks.end());

        for (int i = 0; i<peaks.size(); ++i) {
            sorted_peak_idx[peaks[i]] = i;
        }


        vector<int> min_peak(peaks.size());

        for (int i = 0; i<peaks.size(); ++i) {
            int t = peaks[i];
            int l_count = 0;
            int r_count = 0;
            int l = 0;
            int r = 0;

            if (indices[t] != -1) {
                // // cout << "peak: " << t << endl;
                int j = indices[t] - 1;
                int prev_peak = -1;

                while (j >= 0) {
                    if (a[j] > t) {
                        break;
                    }

                    if (peak_idx.count(a[j]) && sorted_peak_idx[a[j]] >= prev_peak) {
                        if (prev_peak != -1) {
                            r -= min_peak[sorted_peak_idx[prev_peak]];
                        }
                        prev_peak = sorted_peak_idx[a[j]];
                        r += min_peak[sorted_peak_idx[a[j]]];
                        // cout << "MIN PEAK L: " <<min_peak[sorted_peak_idx[a[j]]] << ' ' << a[j] << endl; 
                    } 


                    ++l_count;
                    ++l;

                    --j;
                }


                j = indices[t] + 1;
                prev_peak = -1;

                while (j < n) {
                    if (a[j] > t) {
                        break;
                    }

                    if (peak_idx.count(a[j]) && sorted_peak_idx[a[j]] >= prev_peak) {
                        if (prev_peak != -1) {
                            r -= min_peak[sorted_peak_idx[prev_peak]];
                        }
                        prev_peak = sorted_peak_idx[a[j]];
                        l += min_peak[sorted_peak_idx[a[j]]];
                        // cout << "MIN PEAK R: " <<min_peak[sorted_peak_idx[a[j]]] << endl; 
                    } 

                    ++r;
                    ++r_count;

                    ++j;
                }

                // // cout << l_count << ' ' << r_count << endl;

                for (int j = peak_idx[peaks[i]] - l_count; j<=peak_idx[peaks[i]] + r_count; ++j) {
                    indices[a[j]] = -1;
                }

                min_peak[i] = min(l, r);
                // cout << t << ' ' << min_peak[i] << endl;
            }
        }

        cout << (peaks.size() ? (min_peak[peaks.size()-1]) : 0) << '\n';
    }

    return 0;
}
