#include <iostream>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> x >> y;

        x ^= y;

        long long res = 1;

        while (x % 2 == 0) {
            res <<= 1;
            x >>= 1;
        }

        cout << res << '\n';
    }

    return 0;
}
