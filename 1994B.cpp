#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        int first1 = n;
        int second1 = n;

        for (int i = 0; i<n; ++i) {
            if (s[i] == '1' && first1 > i) {
                first1 = i;
            }

            if (t[i] == '1' && second1 > i) {
                second1 = i;
            }
        }

        cout << (first1 <= second1 ? "yES\n" : "nO\n");

    }

    return 0;
}
