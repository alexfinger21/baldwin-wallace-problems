#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int p1, p2, p3;

        cin >> p1 >> p2 >> p3;

        if ((p1 + p2 + p3) % 2 == 1) {
            cout << "-1\n";
        } else {
            if (p1 < p2) {
                p1 ^= p2;
                p2 ^= p1;
                p1 ^= p2;
            }
            if (p3 > p2) {
                p3 ^= p2;
                p2 ^= p3;
                p3 ^= p2;
            }
            if (p1 < p2) {
                p1 ^= p2;
                p2 ^= p1;
                p1 ^= p2;
            }
            
            int ties = 0;

            while ((p1 != 0) && (p3 + p2 != 0)) {
                if (p2 > p3) {
                    p1 -= 1;
                    p2 -= 1;
                } else {
                    p3 -= 1;
                    p1 -= 1;
                }
                ++ties;
            }

            if (p1 == 0) {
                ties += min(p2, p3);
            }

            cout << ties << '\n';
        }
    }

    return 0;
}
