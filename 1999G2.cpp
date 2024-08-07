#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll l = 2, r = 999;

        while (l < r) {
            int md1 = (l + (r-l)/3);
            int md2 = (l + 2*(r-l)/3);

            cout << "? " << md1 << ' ' << md2 << endl;
            cout.flush();

            int resp;
            cin >> resp;

            if (resp == md1*md2) {
                l = md2+1;
            } else if (resp == md1*(md2+1)) {
                l = md1+1;
                r = md2;
            } else {
                r = md1;
            }
        }

        cout << "! " << (l+r)/2 << endl;
        //cout << l << ' ' << r << endl;
        cout.flush();
    }

    return 0;
}
