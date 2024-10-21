#include <iostream>

using namespace std;

int main() {
    short n;
    cin >> n;

    short res = 0;
    for (int i = 0; i<n; ++i) {
        string s;
        cin >> s;

        if (s.find('+') != string::npos) {
            ++res;
        } else {
            --res;
        }
    }

    cout << res << '\n';
}
