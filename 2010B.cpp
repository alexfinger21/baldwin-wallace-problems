#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int a, b;
    cin >> a >> b;

    vector<int> nums(3);

    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;

    for (int i = 0; i<3; ++i) {
        if (nums[i] == a || nums[i] == b) {
            nums[i] = 0;
        }
    }

    for (int i = 0; i<3; ++i) {
        if (nums[i]) {
            cout << nums[i] << '\n';
        }
    }

    return 0;
}
