#include <iostream>
#include <iomanip>
int main() {
    int a, b, c, d;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    long double f;
    long double r = 1000000;
    long double l = -10000000;
    if (a < 0) {
        r *= -1;
        l *= -1;
    }
    for (int i = 0; i < 44; i++) {
        f = (r + l) / 2;
        if (a * f * f * f + b * f * f + c * f + d > 0)
            r = f;
        else
            l = f;
    }
    std::cout << std::fixed << std::setprecision(9) << std::setw(12) << l;
}
