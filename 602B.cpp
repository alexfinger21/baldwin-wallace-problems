#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {

    int arLen;
    cin >> arLen;
    vector<int> vals;

    int minv = 0;
    int maxv = 0;
    int low = 0;
    int high = 0; 
    int res = 1;

    for (int i = 0; i<arLen; ++i) {
        int v;
        cin >> v;

        vals.push_back(v);
        if (vals[i] < vals[maxv]) {//possible min
            if (vals[maxv] - vals[i] <= 1) {
                high = i;

                if (vals[i] <= vals[minv]) {
                    minv = i;
                }
            } else {//new range
                res = max(res, high-low + 1);

                low = maxv + 1;
                high = i;
                minv = i;
                maxv = i-1;
            }
        } else if (vals[i] >= vals[minv]) {//possible max
            if (vals[i] - vals[minv] <= 1) {
                high = i;

                if (vals[i] >= vals[maxv]) {
                    maxv = i;
                }
            } else {//new range
                res = max(res, high-low + 1);

                low = minv + 1;
                high = i;
                maxv = i;
                minv = i-1;
            }
        } 

    }

    res = max(res, high-low + 1);

    cout << res << '\n';

    return 0;
}
