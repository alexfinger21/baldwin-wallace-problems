    #include <iostream>
     
    using namespace std;
     
    int32_t main() {
        int t;
        cin >> t;
        
        while (t--) {
            long long n;
            cin >> n;
            if (n != 3) {
                cout << '2' << '\n';
            } else {
                cout << '3' << '\n';
            }
        }
        
        return 0;
    }
