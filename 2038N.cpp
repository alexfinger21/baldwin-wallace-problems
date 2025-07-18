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


        if (s[0] > s[2]) {
            s[1] = '>';
        } else if (s[0] < s[2]) {
            s[1] = '<';
        } else {
            s[1] = '=';
        }
        cout << s << '\n';
    }

    return 0;
}
