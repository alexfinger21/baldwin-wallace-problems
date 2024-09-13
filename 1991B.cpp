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

        vector<ll> nums(n-1);
        vector<ll> res;

        ll last = -1, last2 = -1;

        for (int i = 0; i<n-1; ++i) {
            cin >> nums[i]; 
        }

        res.push_back(nums[0]);

        bool found = false;

        for (int i = 0; i<n-1; ++i) {
            if (last2 == -1) {
                last2 = nums[i];
            } else if (last == -1) {
                last = nums[i];
            } else {
                if ((((last2 & nums[i]) | last) ^ last) != 0) {
                    //cout << (((last2 & nums[i]) | last) ^ last) << endl;
                    //cout << last2 << ' ' << last << ' ' << nums[i] << endl;
                    found = true;
                    break;
                }
                last2 = nums[i-1];
                last = nums[i];
            }
            res.push_back(i < n-2 ? (nums[i] | nums[i+1]) : nums[i]);
        }

        if (found) {
            cout << "-1\n";
        } else {
            for (auto x : res) {
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
