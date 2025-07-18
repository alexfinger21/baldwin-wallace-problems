#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c<cases; ++c) {
        int min, max;
        cin >> min >> max;

        int res = log2(max);

        cout << res << '\n';
    }


    return 0;
}
