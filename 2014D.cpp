#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;

        vector<int> s(n);
        vector<int> e(n);

        for (int i = 0; i<k; ++i) {
            int l, r;
            cin >> l >> r;

            ++s[l-1];
            ++e[r-1];
        }

        int start = 0, end = 0;

        int rmin = k, rmax = 0, cr = 0;
        int mini = 0, maxi = 0;

        for (int i = 0; i<n; ++i) {
            cr += s[i];
            //cout << cr << endl;
            
            if (i - start + 1 > d) {
                cr -= e[start];
                ++start;
            }

            ++end;

            if (i - start + 1 == d) {
                if (rmin > cr) {
                    rmin = cr;
                    mini = start;
                } 

                if (rmax < cr) {
                    rmax = cr;
                    maxi = start;
                }
            }
        }

        cout << maxi+1 << ' ' << mini+1 << '\n';
    }

    return 0;
}
