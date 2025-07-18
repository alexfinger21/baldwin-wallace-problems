#include <iostream>
#include <string>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int x, y;
        cin >> y >> x;

        int top = -1, bottom = -1, topX;

        for (int i = 0; i<y; ++i) {
            string s;
            cin >> s;

            int hashRes = s.find("#");

            if (hashRes != string::npos) {
                if (top == -1) {
                    top = i+1;
                    topX = hashRes + 1;
                }
            } else if (bottom == -1 && top != -1) {
                bottom = i;
            }
        }

        if (bottom == -1) {
            bottom = y;
        }
        
        cout << (top+bottom)/2 << ' ' << topX << '\n';
    }

    return 0;
}

