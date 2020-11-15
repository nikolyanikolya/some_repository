#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
#include <limits>

namespace hse::cpp {
    long long gcd(long long a, long long b); //объявление метода
    long long gcd(long long a, long long b) {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            long long c = b;
            b = a % b;
            a = c;
        }
        return a;
    }
    struct ratio {
    private:
        int numerator, denominator;
    public:
        ratio(long long num = 0, long long den = 1) {
            assert (denominator != 0);
            long long g = gcd(num, den);
            if (den < 0) {
                g *= -1;
            }
            num = num / g;
            den = den / g;
            assert(num <= std::numeric_limits<int>::max());
            assert(num >= std::numeric_limits<int>::min());
            assert(den <= std::numeric_limits<int>::max());
            numerator = num;
            denominator = den;
        }

        int get_num() const{
            return numerator;
        }

        int get_den() const{
            return denominator;
        }

        void set(int num, int den) {
            numerator = num;
            denominator = den;
        }

        ratio operator+() const {
            return *this;
        }

        ratio operator-() const {
            return ratio(-numerator, denominator); //Унарный минус
        }

        ratio operator+(ratio const &b) const {
            return ratio(static_cast<long long>(numerator) * b.denominator +
                         static_cast<long long>(denominator) * b.numerator);
        }

        ratio operator-(ratio const &b) const {
            return ratio(static_cast<long long>(numerator) * b.denominator +
                         static_cast<long long>(denominator) * b.numerator,
                         static_cast<long long>(denominator) * b.denominator);
        }

        ratio operator*(ratio const &b) const {
            return ratio(static_cast<long long>(numerator) * b.numerator,
                         static_cast<long long>(denominator) * b.denominator);
        }

        ratio operator/(ratio const &b) const {
            return ratio(static_cast<long long>(numerator) * b.denominator,
                         static_cast<long long>(denominator) * b.numerator);
        }


        bool operator==(ratio const &b) const {
            return numerator == b.numerator && denominator == b.denominator;
        }

        friend std::ostream &operator<<(std::ostream &out, ratio const &r);
    };

    std::ostream &operator<<(std::ostream &out, ratio const &r) {
        return out << r.numerator << '/' << r.denominator;
    }
    std::istream& operator >>(std::istream& in, ratio &r){
        long long  a, b;
        char c;
        in>>a;
        if(in.peek)
    }
    bigint & operator++(bigint )
}

int main() {
    std::vector<int> v{1, 2, 3};
    using hse::cpp::ratio;
    ratio const a(1), b(2, 5);
    operator<<(std::cout, a + b) << std::endl;
    std::cout << a;
    return 0;
}
