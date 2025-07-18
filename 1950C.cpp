#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        string s1 = s.substr(0, s.find(':'));
        string s2 = s.substr(s.find(':') + 1, s.size());

        int n1 = stoi(s1);
        int n2 = stoi(s2);

        if (n1 > 12) {
            n1 %= 13;
            ++n1;
        } else if (n1 == 0) {
            n1 = 12;
        }

        cout << (n1 < 10 ? '0' + to_string(n1) : to_string(n1)) << ':' << (n2 < 10 ? '0' + to_string(n2) : to_string(n2)) << ' ' << (stoi(s1) < 12 ? "AM" : "PM") << '\n';
    }

    return 0;
}
