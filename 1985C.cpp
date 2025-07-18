#include <iostream>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int len;
        cin >> len;

        long long nums[len];
        long long sum = 0;
        int res = 0;
        int maxInd = 0;

        for (int i = 0; i<len; ++i) {
            long long n;
            cin >> n;
    

            nums[i] = n;
            sum += n;

            if (nums[maxInd] < n) {
                maxInd = i;
            }

            if (sum - nums[maxInd] == nums[maxInd]) {
                ++res;
            }

        }

        cout << res << '\n';
    }

    return 0;
}
