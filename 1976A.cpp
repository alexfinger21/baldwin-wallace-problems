#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int len;
        cin >> len;

        string pass;
        cin >> pass;
        
        bool found = false;

        for (int i = 0; i<len-1; ++i) {
            if (pass[i+1] < pass[i]) {
                found = true;
                break;
            }
        }
        
        cout << (!found ?"YES" : "NO") << '\n';
    }

    return 0;
}
