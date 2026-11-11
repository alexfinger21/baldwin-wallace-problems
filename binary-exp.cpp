#include <iostream>

int ternary_exp(int a, int b) {
    if (!b) {
        return 1;
    }

    int prev_res = ternary_exp(a, b / 3);

    prev_res *= prev_res * prev_res;

    if (b % 3 == 2) {
        return a * a * prev_res;
    } else if (b % 3 == 1) {
        return a * prev_res;
    }

    return prev_res;
}

int main() {
    int a = 7;
    int b = 5;

    std::cout << ternary_exp(a, b) << std::endl;

    return 0;
}
