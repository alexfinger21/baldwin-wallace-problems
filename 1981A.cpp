#include <iostream>
#include <math.h>

using namespace std;

int maxPrimeFactors(int n) {
    int count = 0;

    for (int i = 2; i<=int(sqrt(n)); ++i) {
        while (n % i == 0) {
            ++count;
            n /= i;
        }
    }

    if (n != 1) {
        ++count;
    }

    return count;
}

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c<cases; ++c) {
        int min, max;
        cin >> min >> max;

        int res = 0;

        cout << "hi" << endl;
        cout << (double)((max/min - 1)) / (max/min) << endl;
        cout << (int)(min+(max-min)*(double)((max/min - 1) / (max/min))) << endl;
        
        for (int i = max; i>=(int)(min+(max-min)*(double)((max/min - 1) / (max/min))); --i) {
            int maxP = maxPrimeFactors(i);
            if (maxP == 20) {
                cout << i << " : " << maxP << endl; 
            }
            if (maxP > res) {
                res = maxP;
            }
        }

        cout << res << '\n';
    }


    return 0;
}
