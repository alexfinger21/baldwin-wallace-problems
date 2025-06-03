#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> p(n);

        unordered_map<int, int> posi;

        for (int i = 0; i<n; ++i) {
            cin >> p[i];
            posi[p[i]] = i;
        }

        for (int i = 0; i<q; ++i) {
            int l, r, k;
            cin >> l >> r >> k;

            int pos = posi[k];

            if (pos < l - 1 || pos > r - 1) {
                pos = -1;
            }

            if (pos == -1) {
                cout << "-1 ";
                continue;
            }

            int swp_less = 0;
            int swp_more = 0;

            --l; --r;

            int s_count = 0, b_count = 0, res = 0;

            while (l < r) {
                int m = (l + r) >> 1;
                //cout << m << ' ' << p[m] << endl;

                if (p[m] == k) {
                    break;
                }

                if (p[m] > k) {
                    if (m < pos) {
                        ++swp_more;
                        l = m + 1;
                    } else {
                        ++b_count;
                        r = m - 1;
                    }

                } 

                if (p[m] < k) {
                    if (m > pos) {
                        ++swp_less;
                        r = m - 1;
                    } else {
                        ++s_count;
                        l = m + 1;
                    }

                } 
                if (swp_less > (n-k-b_count) || swp_more > (k-1-s_count)) {
                    res = -1;
                    break;
                }
            }


            //cout << s_count << ' ' << b_count << endl;
            //cout << swp_less.size() << ' ' << swp_more.size() << endl;
            if (swp_less > (n-k-b_count) || swp_more > (k-1-s_count)) {
                res = -1;
            }

            if (res == -1) {
                cout << "-1 ";
                continue;
            }

            res = abs(swp_less - swp_more) * 2 + min(swp_less, swp_more) * 2;
            cout << res << ' ';
        }

        cout << '\n';
    }

    return 0;
}
