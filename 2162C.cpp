#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;

        ll c_a = 0;
        ll md = 0;

        while (pow(2, md)-1 < a) {
            if (pow(2, md) > b) {
                c_a += pow(2, md);
            }
            ++md;
        }
        md = 0;

        while (pow(2, md)-1 < b) {
            if (pow(2, md) > a) {
                c_a = -1;
                break;
            }
            ++md;
        }

        ll xr = (a ^ b) ^ (c_a);


        if (c_a == -1) {
            cout << "-1\n";
        } else if (a == b) {
            cout << "0\n";
        } else {
            cout << ("2\n");
            cout << xr << ' ';
            cout << (c_a) << '\n';
        }
    }

    return 0;
}
