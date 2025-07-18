        #include <iostream>
        #include <math.h>
         
        using namespace std;
         
        int32_t main() {
            int t;
            cin >> t;
            
            while (t--) {
                int x, y, x2, y2;
                cin >> x >> y >> x2 >> y2;
                
                if ((x < y && x2 < y2) || (x > y && x2 > y2)) {
                    cout << "YES\n";
                } else {
                    cout << "NO\n";
                }
            }
            
            return 0;
        }
