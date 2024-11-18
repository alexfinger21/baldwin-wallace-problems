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

        int last = -1;
        bool found = false;
        for (int i = 0; i<n; ++i) {
            short num;
            cin >> num;

            if (last != -1) {
                if (abs(num - last) == 5 || abs(num - last) == 7) {

                } else {
                    found = true;
                } 
            }
            last = num;
        }

        cout << (found ? "NO\n" : "YES\n");
    }

    return 0;
}
