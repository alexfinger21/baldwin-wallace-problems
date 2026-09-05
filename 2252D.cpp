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

        vector<ll> a(n);
        vector<ll> diff_array(n-1);

        for (int i = 0; i<n; ++i) {
             cin >> a[i];
        }

        int queue_idx = 0;
        vector<int> breaks;

        for (int i = 0; i<n-1; ++i) {
            diff_array[i] = a[i+1] - a[i];
            if (i > 0 && ((diff_array[i-1] & 1) != (diff_array[i] & 1))) {
                breaks.push_back(i-1);
            }
        }

        int last_idx = 0;
        for (int i = 0; i<breaks.size(); ++i) {
            sort(diff_array.begin() + last_idx, diff_array.begin() + breaks[i] + 1);

            last_idx = breaks[i] + 1;
        }

        sort(diff_array.begin() + last_idx, diff_array.end());

        ll curr_val = a[0];
        cout << a[0] << ' ';

        for (int i = 0; i<n-1; ++i) {
            curr_val = curr_val + diff_array[i];
            cout << (curr_val) << ' ';
        }

        cout << '\n';

    }

    return 0;
}
