#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        cout << "digit" << endl;
        cout.flush();
        int res;
        cin >> res;
        cout << "digit" << endl;
        cout.flush();
        cin >> res;

        int upper = 16;
        while (upper > 1) {
            cout << "add -" << upper/2 << endl;
            cout.flush();
            cin >> res;

            if (res) {
                upper = upper/2;
            } else {
                upper = upper/2;
            }
        }

        cout << "add " << (n - 1) << endl;
        cout.flush();
        cin >> res;
        cout << "!" << endl;
        cout.flush();
        cin >> res;

        if (res == -1) {
            return 0;
        }
    }

    return 0;
}
