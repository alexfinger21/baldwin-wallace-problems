#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c<cases; ++c) {
        vector<int> nums;

        int n, idx, rm, less = 0, equal = 0;

        cin >> n >> idx >> rm;

        --idx;

        for (int i =  0; i<n; ++i) {
            int v;
            cin >> v;

            nums.push_back(v);
        }

        for (int i = 0; i<n; ++i) {
            if (nums[idx] > nums[i]) {
                ++less;
            } else if (nums[idx] == nums[i]) {
                ++equal;
            }
        }

        if (rm >= (n-less)) {
            cout << "YES" << '\n';
        } else if (rm <= (n-less-equal)) {
            cout << "NO" << '\n';
        } else {
            cout << "MaYbE" << '\n';
        }
    }

    return 0;
}
