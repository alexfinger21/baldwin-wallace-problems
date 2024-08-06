#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll l = 2, r = 999;

        while (l < r) {
            int md1 = (l + (r-l)/4);
            int md2 = (l + 3*(r-l)/4);

            cout << "? " << md1 << ' ' << md2 << endl;
            cout.flush();

            int resp;
            cin >> resp;

            bool divBy1 = !(resp % md1);
            bool divBy2 = !(resp % md2);

            if (divBy1 && divBy2) {
                //cout << "both div" << endl;
                l = md2+1;
            } else if (divBy1) {
                //cout << "1 div" << endl;
                l = md1+1;
                r = md2;
            } else if (divBy2) {
                //cout << "2 div" << endl;
                l = md1;
                r = md2-1;
            } else {
                //cout << "none div" << endl;
                r = md1;
            }
        }

        cout << "! " << (l+r)/2 << endl;
        //cout << l << ' ' << r << endl;
        cout.flush();
    }

    return 0;
}
