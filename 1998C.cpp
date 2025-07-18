#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int check(vector<ll> &a, ll med) {
    int c = 0;

    for (auto x: a) {
        if (x < med) {
            ++c;
        } else {
            --c;
        }
    }

    return c;
}

ll findMed(vector<ll> &a) {
    ll l = 0, h = 1e9;
    while (l <= h) {
        ll med = (l + h) >> 1;

        int checkRes = check(a, med);
        //cout << "CHECK RES " << checkRes << "MEDIAN " << med << endl;
        if (checkRes >= 0) {
            h = med-1;
        } else {
            l = med+1;
        }
    }

    return h;
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll n, k;

        cin >> n >> k;

        vector<ll> a(n);
        vector<pair<ll, int>> total;
    
        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i<n; ++i) {
            int b;
            cin >> b;

            total.push_back(make_pair(a[i], b));
        }

        ll max1 = 0;

        sort(total.begin(), total.end());

        for (int i = 0; i<n; ++i) {
            if (total[i].second) {
                ll mp;

                if (i < n/2) {
                    mp = total[n/2].first;
                } else {
                    mp = total[(n-2)/2].first;
                }

                max1 = max(max1, total[i].first + k + mp);
            }
        }

        ll lo = 0, hi = 2e9; // highest k + highest a
                            
        while (lo < hi) {
            ll mid = (lo + hi + 1) >> 1;

            int mids = 0;

            vector<ll> smaller_totals;

            for (int i = 0; i<n-1; ++i) {
                if (total[i].first >= mid) {
                    ++mids;
                } else if (total[i].second) {
                    smaller_totals.push_back(total[i].first);
                }
            }

            reverse(smaller_totals.begin(), smaller_totals.end());

            ll k2 = k;

            for (auto x : smaller_totals) {
                if (mid-x <= k2) {
                    ++mids;
                    k2 -= mid-x;
                }
            }

            if (mids >= (n+1)/2) {
                lo = mid;
            } else {
                hi = mid-1;
            }
        }

        cout << max(max1, hi + total[n-1].first) << '\n';

    }

    return 0;
}
