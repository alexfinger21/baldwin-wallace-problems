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

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        set<int> nums;
        set<int> nums2;

        nums.insert(a[0]);
        int res = 1;
        int cnt = 0;
        int goal = 1;

        for (int i = 1; i<n; ++i) {
            nums2.insert(a[i]);  
            if (nums.count(a[i])) {
                ++cnt;
                nums.erase(nums.find(a[i]));
            }
            if (goal == cnt) {
                cnt = 0;
                goal = nums2.size();
                nums = nums2;
                nums2.clear();
                ++res;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
