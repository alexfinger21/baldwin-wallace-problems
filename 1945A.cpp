#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        if (3 - (3-((b+c) % 3)) > c) {
            cout << "-1\n";
        } else {
            cout << fixed << setprecision(0) << a + (b+c)/3 + ceil((b+c)%3*1.0/3) << '\n';
        }
    }

    return 0;
}
