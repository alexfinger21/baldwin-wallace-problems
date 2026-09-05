#include <bits/stdc++.h>
#include "test.hpp"

using ll=long long;
using namespace std;

struct test {
     int i;
     int b;

     test() {
          i = 3;
          b = 3;
     }
};

int main() {
     test t;
     test t2{};

     cout << t.b << endl;
     cout << t2.b << endl;
}
