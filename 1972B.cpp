#include <iostream>
#include <string>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int len;

        cin >> len;

        string s;
        cin >> s;

        int counter = 0;

        for (int i = 0; i<s.size(); ++i) {
            if (s[i] == 'U') { 
                ++counter;
            }
        }

        cout << (counter % 2 == 1 ? "yES" : "nO") << '\n';
    }

    return 0;
}
