#include <iostream>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                if ((j + i) % 2 == 0) {
                    cout << "##";    
                } else {
                    cout << "..";    
                }
            }

            cout << '\n';

            for (int j = 0; j<n; ++j) {
                if ((j + i) % 2 == 0) {
                    cout << "##";    
                } else {
                    cout << "..";    
                }
            }

            cout << '\n';
        }
    }

    return 0;
}
