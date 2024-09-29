#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s = "";

        bool isBack = true, isFront = true, has1 = false;
        int left0 = 0, right0 = 0, max0 = 0;
        while (s.size() < n) {
            int ans;
            if (isFront) {
                string ns = s + '0';
                if (!has1 | right0 < max0) {
                    ++right0;

                    cout << "? " << ns << endl;
                    cout.flush();

                    cin >> ans;

                    if (ans) {
                        s = ns;
                        continue;
                    }
                }

                ns = s + '1';

                cout << "? " << ns << endl;
                cout.flush();

                cin >> ans;

                if (ans) {
                    if (!has1) {
                        max0 = left0+right0;
                        left0 = right0;
                    }
                    right0 = 0;
                    s = ns;
                    has1 = true;
                    continue;
                } else {
                    isFront = false;
                }
            }

            if (isBack) {
                string ns = '0' + s;

                if (has1 && left0 < max0) {
                    ++left0;
                    cout << "? " << ns << endl;
                    cout.flush();

                    cin >> ans;

                    if (ans) {
                        s = ns;
                        continue;
                    }
                }

                ns = '1' + s;
                cout << "? " << ns << endl;
                cout.flush();

                cin >> ans;

                if (ans) {
                    if (!has1) {
                        max0 = left0+right0;
                        right0 = left0;
                    }
                    left0 = 0;
                    has1 = true;
                    s = ns;
                    continue;
                } else {
                    isBack = false;
                }
            }
        }

        cout << "! " << s << endl;
        cout.flush();
    }

    return 0;
}
