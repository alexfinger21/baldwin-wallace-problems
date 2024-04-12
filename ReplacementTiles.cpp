#include <iostream>
#include <vector>

using namespace std;

int main() {
    int cases;
    cin >> cases;


    for (int c = 0; c<cases; ++c) {
        bool meteorArr[10][10];

        for (int i = 0; i<10; ++i) {
            for (int j = 0; j<10; ++j) {
                meteorArr[i][j] = false;
            }
        }

        int meteors;
        cin >> meteors;

        for (int m = 0; m<meteors; ++m) {
            int x, y;

            cin >> x;
            cin >> y;
        
            if (x % 10 == 0 && x != 0 && x != 100) {
                if (y % 10 == 0 && y != 0 && y != 100) {
                    meteorArr[(x/10) - 1][y/10 - 1] = true;
                    meteorArr[(x/10)][y/10 - 1] = true;
                }

                meteorArr[(x/10) - 1][y/10] = true;
            }
            if (y % 10 == 0 && y != 0 && y != 100) {
                meteorArr[(x/10)][y/10 - 1] = true;
            }

            meteorArr[min(x/10, 9)][min(y/10, 9)] = true;
        }

        int count = 0;

        for (int i = 0; i<10; ++i) {
            for (int j = 0; j<10; ++j) {
                if (meteorArr[i][j]) {
                    ++count;
                }
            }
        }

        cout << "Case " << (c+1) << ": " << count << '\n';
    }
}
