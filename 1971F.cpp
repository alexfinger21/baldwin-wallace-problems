#include <iostream>
#include <math.h>
 
using namespace std;
 
long long getDist(long long x, long long y) {
    return sqrt(pow(x, 2)+pow(y, 2));
}
 
int32_t main() {
    int t;
    cin >> t;
 
    while (t--) {
        long long r, answ = 0;
 
        cin >> r;
 
        for (int x = 0; x<=r; ++x) {
            long long height = sqrt(pow(r+1, 2) - pow(x, 2));
            int tCounter = 0;
            bool exit = false;
 
            if (getDist(x, height) == r+1) {
                --height;
            }
           
            while (getDist(x, height) >= r && height >= 0) {
                //cout << "(" << x << " , " << height << ")" << endl;
                if (height == 0 || x == 0) {
                    tCounter += 2;
                } else {
                    tCounter += 4;
                }
 
                --height;
            }
            
            answ += tCounter;
        }
        
 
        cout << answ << '\n';
    }
 
    return 0;
}
