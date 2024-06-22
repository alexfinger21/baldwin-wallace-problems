#include <iostream>
#include <string>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        string num;
        cin >> num;

        if (num[num.size() - 1] == '9') {
            cout << "nO\n";
            continue;
        }

        if (num[0] != '1') {
            cout << "nO\n";
            continue;
        }

        bool found = false;

        for (int i = 1; i<num.size()-1; ++i) {
            if (num[i] == '0') {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "NO\n";
            continue;
        }

        cout << "YeS\n";
    }

    return 0;
}
