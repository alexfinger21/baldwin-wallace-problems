#include <iostream>
#include <string>

using namespace std;

int main() {
    int cases;
    cin >> cases;

    for (int c = 0; c<cases; ++c) {
        int nbr;
        cin >> nbr;

        string res = "";

        if (nbr % 2 != 0) {
            cout << "NO" << '\n';
            continue;
        }
        
        for (int i = 0; i<nbr/2; ++i) {
            if (i % 2 == 0) {
                res += "AA";
            } else {
                res += "BB";
            }
        }
            
        cout << "YES" << '\n';
        cout << res << '\n';
    }

    return 0;
}
