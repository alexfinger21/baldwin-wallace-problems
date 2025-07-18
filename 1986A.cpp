#include <iostream>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;

        cin >> a >> b >> c;

        if (a > b) {
            a ^= b;
            b ^= a;
            a ^= b;
        }

        if (b > c) {
            c ^= b;
            b ^= c;
            c ^= b;
        }

        if (a > b) {
            a ^= b;
            b ^= a;
            a ^= b;
        }

        cout << b - a + c - b << '\n';
    }

    return 0;
}
