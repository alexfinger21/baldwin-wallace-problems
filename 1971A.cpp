    // Online C++ compiler to run C++ program online
    #include <iostream>
    #include <math.h>
    using namespace std;
     
    int main() {
        // Write C++ code here
        int cc;
        cin >> cc;
        
        for (int c = 0; c<cc; ++c) {
            int mi, ma;
            cin >> mi >> ma;
            
            cout << min(mi, ma) << ' ' << max(mi, ma) << '\n';
        }
     
        return 0;
    }
