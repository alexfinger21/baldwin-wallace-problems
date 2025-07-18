#include <iostream>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        
        cin >> n;
        
        int cows = n/4;
        int chickens = (n%4)/2;
        
        cout << cows + chickens << '\n';
    }
    
    return 0;
}
