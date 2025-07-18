#include <iostream>
#include <string>

using namespace std;

int main() {
    int cc;
    cin >> cc;

    for (int c = 0; c<cc; ++c) {
        string s;
        cin >> s;

        char last = s[0];
        int other;

        bool found = false;

        for (int i = 1; i<s.size(); ++i) {
            if (last != s[i]) {
                other = i;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "nO" << '\n';
        } else {
            char inter = last;
            s[0] = s[other];
            s[other] = last;

            cout << "yES" << '\n';
            cout << s << '\n';
        }
    }

    return 0;
}
