#include <iostream>

using namespace std;

int main() {
    int cc;
    cin >> cc;

    for (int c = 0; c<cc; ++c) {
        int n, m;
        cin >> n >> m;

        if (n < m) {
            cout << "nO" << '\n';
        } else if (n == m || (m-n)%2 == 0) {
            cout << "yEs" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
