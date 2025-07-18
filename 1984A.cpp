#include <iostream>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int len, L;
        cin >> len;

        L = len;

        int arr[len];

        while (len--) {
            cin >> arr[len];
        }

        bool same = true;

        for (int i = 0; i<L-1; ++i) {
            if (arr[i] != arr[i+1]) {
                same = false;
                break;
            }
        }

        if (same) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        
        same = true;

        for (int i = 0; i<L; ++i) {
            if (arr[i] != arr[i+1] && same) {
                same = false;
                cout << 'B';
            } else {
                cout << 'R';
            }
        }

        cout << '\n';
    }

    return 0;
}
