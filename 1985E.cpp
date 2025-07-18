#include <iostream>
#include <math.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        long long x, y, z, S, s, f1, f2, f3, div1, div2, res = 0;

        cin >> x >> y >> z >> S;
        //cout << pow(S, 1.0/3) << " - CUBE ROOT\n";

        div1 = x;

        while (div1) {
            s = S;
            if (s % div1 == 0) {
                div2 = y;
                s /= div1;

                while (div2) {
                    s = S/div1;
                    if (s % div2 == 0) {
                        s /= div2;

                        if (s <= z) {
                            res = max(res, (x-div1+1)*(y-div2+1)*(z-s+1));
                        }
                    }
                    --div2;
                }
            }
            --div1;
        }
        

        cout << res << '\n';
    }

    return 0;
}
