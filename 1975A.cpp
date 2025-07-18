#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int found = false;
        int count = 1;
        int last;
        cin >> last;
        int first = last;

        for (int i = 1; i<n; ++i) {
            int num;
            cin >> num;

            if (num < last) {
                ++count;
            }

            if (count > 1 && num > first) {
                found = true;
            }

            last = num;
        }

        if (count > 2 || found) {
            cout << "nO\n";
        } else {
            cout << "yES\n";
        }
    }

    return 0;
}
