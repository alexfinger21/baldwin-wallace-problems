#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    --n; --m;

    string s1, s2;

    if (n == 0) {
        s1 = "0";
    }

    if (m == 0) {
        s2 = "0";
    }

    while (n > 0) {
        s1 = to_string(n % 7) + s1;
        n /= 7;
    }

    while (m > 0) {
        s2 = to_string(m % 7) + s2;
        m /= 7;
    }

    if ((s1.size() + s2.size()) > 7) {
        cout << "0\n";
        return 0;
    }

    ll x = stoll(s1), y = stoll(s2);

    ll res = 0;

    ll minx = pow(10, s1.size() - 2), miny = pow(10, s2.size() - 2);
    bool f = false;

    while (y >= 0 && y >= miny) {
        string y_str = to_string(y);
        if (y_str.size() < s2.size()) {
            y_str += '0';
        }

        f = false;

        for (int i = 0; i<y_str.size()-1; ++i) {
            if (y_str.find(y_str[i], i+1) != string::npos) {
                f = true;
                break;
            }
        }

        if (!f) {
            ll xx = x;
            while (xx >= 0 && xx >= minx) {
                string x_str = to_string(xx);
                if (x_str.size() < s1.size()) {
                    x_str += '0';
                }
                x_str = x_str + y_str;
                for (int i = 0; i<x_str.size()-1; ++i) {
                    if (x_str.find(x_str[i], i+1) != string::npos || x_str[i] - '0' > 6) {
                        f = true;
                        break;
                    }
                }
                if (!f) {
                    ++res;
                }
                f = false;

                --xx;
                if (xx % 10 == 9) {
                    xx -= 3;
                }
            }
        }

        --y;
        if (y % 10 == 9) {
            y -= 3;
        }
    }

    cout << res << '\n';


    return 0;
}
