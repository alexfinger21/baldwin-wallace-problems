#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll x, y;
        cin >> x >> y;

        ll k = 0;

        if (x == y) {
            cout << "-1\n";
            continue;
        }

        vector<int> a(32);
        vector<int> b(32);

        int ldiff = -1;
        int last = -1;

        for (int i = 31; i>=0; --i) {
            if (x >= pow(2, i)) {
                a[31-i] = 1;
                x -= pow(2, i);
            } else {
                a[31-i] = 0;
            }

            if (y >= pow(2, i)) {
                b[31-i] = 1;
                y -= pow(2, i);
            } else {
                b[31-i] = 0;
            }

            if (b[31-i] != a[31-i] && ldiff == -1) {
                ldiff = 31-i;
            }

            if ((b[31-i] + a[31-i]) && last == -1) {
                //cout << i << " last" << endl;
                last = 31-i;
            }
        }

        last = max(last-1, 0);
        for (int i = 31; i>=last; --i) {
            //cout << a[i] << ' ' << b[i] << endl;
            if ((a[i] == b[i] && (a[i] + b[i])) || (a[i] != b[i] && (i > 0 && a[i-1] == b[i-1]))) {
                //cout << i << endl;
                k += pow(2, 31-i);
                int carryx = a[i];
                int carryy = b[i];

                int j = i-1;
                while ((carryx || carryy) && j<=31) {
                    if (carryx) {
                        if (a[j]) {
                            a[j] = 0;
                        } else {
                            a[j] = 1;
                            carryx = 0;
                        }
                    }
                    if (carryy) {
                        if (b[j]) {
                            b[j] = 0;
                        } else {
                            b[j] = 1;
                            carryy = 0;
                        }
                    }
                    --j;
                }
            } 
        }

        cout << k << '\n';
    }

    return 0;
}
