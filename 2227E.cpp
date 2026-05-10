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
        int max_h = 0;

        cin >> n;

        vector<int> a(n);
        vector<ll> dp(n);
        vector<int> elems;
        ll totl = 0;


        for (int i = 0; i<n; ++i) {
            cin >> a[i];
            totl += a[i];

            dp[i] = (i > 0 ? dp[i-1] : 0);

            int j = i;

            while (!elems.empty() && a[elems.back()] > a[i]) {
                int h = a[elems.back()];

                elems.pop_back();

                if (!elems.empty()) {
                    dp[i] += (j - elems.back() - 1) * (h - a[i]); 
                    j = elems.back() + 1;
                } else {
                    dp[i] += (j) * (h - a[i]); 
                } 
            }


            elems.push_back(i);

            // cout << elems.size() << ' ' << dp[i] << endl;
        }

        ll res = dp[n-1];

        for (int i = elems.size() - 1; i>=0; --i) {
            if (i > 0) {
                for (int j = i-1; j>=0; --j) {
                    /*
                    cout << "here: " << i << ' ' << j << endl;
                    cout << elems[i] << '-' << elems[j] << endl;
                    */
                    if (a[elems[j]] != a[elems[i]]) {
                        // cout << j << ' ' << i << " not equal\n";
                        res = max(res, dp[n-1] + elems[i] - elems[j] - 1);
                        i = j + 1;

                        break;
                    }

                    if (j == 0) {
                        res = max(res, dp[n-1] + elems[i]);
                        i = j;
                    }
                }
            }

            if (i == 0 && elems[i] > 0) {
                res = max(res, dp[n-1] + elems[i]);
            }
        }
        
        cout << res << '\n';
    }

    return 0;
}
