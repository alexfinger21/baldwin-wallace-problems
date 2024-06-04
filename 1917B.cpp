#include <set>
#include <string>
#include <iostream>
int main()
{
    using namespace std;
    int cases;
    cin >> cases;
    
    for (int c = 0; c<cases; ++c) {
        int len;
        cin >> len;
        
        len = 1;
        
        string str;
        cin >> str;
        
        set<char> prevChar = {str[0]};
        
        int uniqueLen = 1;
        
        for (int i = 1; i<str.length(); ++i) {
            if (prevChar.find(str[i]) == prevChar.end()) {
                ++uniqueLen;
                prevChar.insert(str[i]);
            }
            
            len += uniqueLen;
        }
        cout << len << endl;
    }
 
    return 0;
}
