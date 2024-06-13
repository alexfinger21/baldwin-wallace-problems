#include <iostream>
#include <string>

using namespace std;

int main() {
    int cc;
    cin >> cc;

    for (int c = 0; c<cc; ++c) {
        string s;
        cin >> s;

        int res = 1;

        bool first01 = false;

        for (int i = 1; i<s.size(); ++i) {
            if (s[i-1] > s[i]) {
                ++res;
            } else if (!first01 && s[i-1] < s[i]) {
                first01 = true;
            } else if (s[i-1] != s[i]) {
                ++res;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
