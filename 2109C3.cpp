#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        cout << "mul 999999999" << endl;
        int resp;
        cin >> resp;
        cout << "digit" << endl;
        cin >> resp;
        if (n != 81) {
            cout << "add " << (n-81) << endl;
            cin >> resp;
        }
        cout << "!" << endl;
        cin >> resp;
        assert(resp == 1);
    }

    return 0;
}
