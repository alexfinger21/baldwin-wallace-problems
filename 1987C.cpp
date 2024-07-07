#include <iostream>

using namespace std;

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;


        long long flores[n];


        for (int i = 0; i<n; ++i) {
            long long h;
            cin >> h;

            flores[i] = h;
        }

        long long turns = flores[n-1];

        for (int i = n-2; i>=0; --i) {

            if (turns >= flores[i]) {
                ++turns;
            } else {
                turns += flores[i] - turns;
            }
            /*
            for (int j = 0; j<n; ++j) {
                cout << flores[j] << ' ';
            }
            cout << endl;
            //*/
            
        }

        cout << turns << '\n';
    }
    

    return 0;
}
