#include <bits/stdc++.h>

using namespace std;

bool isBin(int n) {
    while (n > 0) {
        if (!(n % 10 == 0 || n % 10 == 1)) {
            return false;
        }

        n /= 10;
    }

    return true;
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        for (int i = (int)(pow(2, 5)); i>=2; --i) {
            long long div = 0;
            int old = i;

            for (int j = log2(i); j >= 0; --j) {
                if (pow(2, j) <= old) {
                    old -= pow(2, j);
                    div += pow(10, j);
                }
            }

            while (n % div == 0) {
                n /= div; 
            }

            if (n == 1) {
                break;
            }
        }

        if (n == 1) {
            cout << "yES\n";
        } else {
            cout << "nO\n";
        }
    }

    return 0;
}
