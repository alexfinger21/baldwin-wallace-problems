#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;
        
        --k;
        ++x;

        long long calc = k-(y-(x%y == 0 ? y : x%y));

        long long res = 0;


        if (calc < 0) {
            res = x + k;
        } else {
            
            x += y-(x%y == 0 ? y : x%y);

            //cout << x << endl;

            while (x % y == 0) {
                x /= y;
            }

            //cout << x << endl;

            while (calc >= (y-(x%y == 0 ? y : x%y)) && x >= y) {
                calc -= y-(x%y == 0 ? y : x%y);
                x += y-(x%y == 0 ? y : x%y);

                //cout << x << endl << "-------" << endl;

                while (x % y == 0) {
                    x /= y;
                }

                //cout << x << endl;
            }
            
            if (x < y) {
                //cout << "yes" << calc << x << endl;
                res = 1 + (x+calc-1)%(y-1);
            } else {
                res = x+calc;
            }
        }


        cout << res << '\n';
    }

    return 0;
}
