#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int c0 = 0, c1 = 0;

        int current = -1;

        for (int i = 0; i<s.size(); ++i) {
            int c = s[i] - '0';

            if (c) {
                ++c1;
                current = 1;
            } else if (current != 0) {
                ++c0;
                current = 0;
            }
        }
        
        cout << (c0 >= c1 ? "nO\n" : "yES\n");
    }

    return 0;
}
