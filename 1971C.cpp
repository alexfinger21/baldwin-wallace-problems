#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int cc;
    cin >> cc;

    for (int c0 = 0; c0<cc; ++c0) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if (max(a, b) > max(c, d) && (min(a, b) > min(c, d) && max(c, d) > min(a, b))) {
            cout << "yES" << '\n';
        } else if (max(a, b) < max(c, d) && (min(a, b) < min(c, d) && max(a, b) > min(c, d))) {
            cout << "YeS" << '\n';
        } else {
            cout << "nO" << '\n';
        }
    }

    return 0;
}
