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

        vector<pair<int, int>> ind(n, {-1, 0});
        vector<int> a(2*n);

        for (int i = 0; i<2*n; ++i) {
            int p;
            cin >> p;

            a[i] = p;

            if (ind[p].first == -1) {
                ind[p].first = i;
            } else {
                ind[p].second = i;
            }
        } 

        int ctr = (ind[0].first + ind[0].second) / 2;
        set<int> nums;

        if (n > 1) {
            int c = (ind[1].first + ind[1].second) / 2;                

            if (c != ctr) {
                if (ind[0].first == c || ind[0].second == c) {
                    ctr = c;
                } 
            }
        }


        for (int i = ctr+1; i<2*n; ++i) {
            if (((ind[a[i]].first) + (ind[a[i]].second)) / 2 == ctr) {
                nums.insert(a[i]);
            } else {
                break;
            }
        }

        int res = 0;

        for (auto x : nums) {
            if (x - res <= 1) {
                res = x;
            } else {
                break;
            }
        }
        
        ++res;

        nums.clear();

        for (int i = ctr-1; i<2*n; ++i) {
            if (((ind[a[i]].first) + (ind[a[i]].second)) / 2 == ctr) {
                nums.insert(a[i]);
            } else {
                break;
            }
        }

        int res2 = 0;

        for (auto x : nums) {
            if (x - res2 <= 1) {
                res2 = x;
            } else {
                break;
            }
        }

        ++res2;

        cout << (min(res, res2) + ((ind[0].second - ind[0].first) % 2 ? 0 : 1)) << '\n';
    } 

    return 0;
}
