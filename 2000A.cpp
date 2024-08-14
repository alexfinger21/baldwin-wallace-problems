#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;


        if (s.size() > 2 && s.substr(0,2) == "10") {
            if (stoi(s.substr(2)) > 1) {
                if (stoi(s.substr(2)) < 10 && s.substr(2).size() > 1) {
                    cout << "NO\n";
                    continue;
                }
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
