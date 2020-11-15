#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

int Base = 10;
namespace Lab01 {

    struct BigInt {
    private:
        std::vector<int> long_number;
    public:
        BigInt() = default;

        explicit BigInt(const std::string &init_str) {
            long_number.resize(init_str.length());
            for (int i = static_cast<int>(init_str.length() - 1); i >= 0; i--) {
                char symbol = init_str[i];
                long_number[long_number.size() - i - 1] = symbol - '0';
            }
        }

        BigInt(unsigned int init_value) {
            unsigned int i = init_value;
            int length_of_number = 0;
            while (i != 0) {
                length_of_number++;
                i /= Base;
            }
            i = init_value;
            long_number.resize(length_of_number);
            for (int j = length_of_number - 1; j >= 0; j--) {
                long_number[long_number.size() - j - 1] = i % Base;
                i = i / Base;
            }
        }
        BigInt sum_Big(const BigInt &x, const BigInt &y) {
            BigInt sum;
            for (unsigned int i = 0; i < x.long_number.size(); i++) {
                if (i < y.long_number.size())
                    sum.long_number[i] += x.long_number[i] + y.long_number[i];
                else
                    sum.long_number[i] += x.long_number[i];
                if (sum.long_number[i] >= Base) {
                    sum.long_number[i] %= Base;
                    sum.long_number[i + 1]++;
                }
            }
            if (sum.long_number[sum.long_number.size() - 1] == 0) {
                sum.long_number.resize(sum.long_number.size() - 1);
            }
            return sum;
        }
        [[nodiscard]] std::string to_string() const {
            std::string str;
            str = "";
            for (int i = long_number.size() - 1; i >= 0; i--) {
                char current = long_number[i] + '0';
                str = str + current;
            }
            return str;

        }

        friend std::ostream &operator<<(std::ostream &out, const BigInt &a);

        friend bool operator==(const BigInt &x, const BigInt &y);
        friend BigInt operator+(const BigInt &x, const BigInt &y);

        friend bool operator<(const BigInt &y, const BigInt &x);

        friend BigInt operator-(const BigInt &x, const BigInt &y);
    };

    bool operator==(const BigInt &x, const BigInt &y) {
        return (x.long_number == y.long_number) ? true : false;
    }

    bool operator!=(const BigInt &x, const BigInt &y) {
        return (!(x == y));
    }

    bool operator<(const BigInt &x, const BigInt &y) {
        if (x != y) {
            if (x.long_number.size() < y.long_number.size())
                return true;
            else if (x.long_number.size() > y.long_number.size())
                return false;
            else {
                for (int i = x.long_number.size() - 1; i >= 0; i--) {
                    if (x.long_number[i] < y.long_number[i])
                        return true;
                    else if (x.long_number[i] > y.long_number[i])
                        return false;
                }
            }
        }
        return false;
    }

    bool operator>(const BigInt &x, const BigInt &y) {
        return (y < x) ? true : false;
    }

    bool operator<=(const BigInt &x, const BigInt &y) {
        return (x < y || x == y) ? true : false;
    }

    bool operator>=(const BigInt &x, const BigInt &y) {
        return (!(x < y));
    }

    BigInt operator+(const BigInt &x, const BigInt &y) {
        if (x>y)
        return sum_Big(x, y);
    }

    BigInt &operator+=(BigInt &x, const BigInt &y) {
        return x = x + y;
    }

    BigInt operator-(const BigInt &x, const BigInt &y) {
        BigInt difference;
        if (x > y) {
            difference.long_number.resize(x.long_number.size());
            for (unsigned int i = 0; i < x.long_number.size(); i++) {
                if (i < y.long_number.size())
                    difference.long_number[i] += x.long_number[i] - y.long_number[i];
                else
                    difference.long_number[i] += x.long_number[i];
                if (difference.long_number[i] < 0 && i + 1 < x.long_number.size()) {
                    difference.long_number[i] += Base;
                    difference.long_number[i + 1]--;
                }
            }
            unsigned int i = x.long_number.size() - 1;
            while (difference.long_number[i] == 0 && i >= 1) {
                difference.long_number.pop_back();
                i--;
            }
        } else {
            difference.long_number.resize(y.long_number.size());
            for (unsigned int i = 0; i < y.long_number.size(); i++) {
                if (i < x.long_number.size())
                    difference.long_number[i] += y.long_number[i] - x.long_number[i];
                else
                    difference.long_number[i] += y.long_number[i];
                if (difference.long_number[i] < 0 && i + 1 < y.long_number.size()) {
                    difference.long_number[i] += Base;
                    difference.long_number[i + 1]--;
                }
            }
            unsigned int i = y.long_number.size() - 1;
            while (difference.long_number[i] == 0 && i >= 1) {
                difference.long_number.pop_back();
                i--;
            }
        }
        return difference;
    }

    BigInt &operator-=(BigInt &x, const BigInt &y) {
        return x = x - y;
    }

    BigInt &operator++(BigInt &a) { //Prefix
        a += 1;
        return a;
    }

    BigInt operator++(BigInt &a, int) { //Postfix
        BigInt old_a = a;
        a += 1;
        return old_a;
    }

    BigInt &operator--(BigInt &a) {
        a -= 1;
        return a;
    }

    BigInt operator--(BigInt &a, int) {
        BigInt old_a = a;
        --a;
        return old_a;
    }

    std::istream &operator>>(std::istream &in, BigInt &a) {
        std::string str;
        in >> str;
        a = BigInt(str);
        return in;
    }

    std::ostream &operator<<(std::ostream &out, const BigInt &a) {
        for (int i = a.long_number.size() - 1; i >= 0; i--) {
            out << a.long_number[i];
        }
        return out;
    }


// При необходимости, можете дописать что-то сюда.

// Также по необходимости можно добавлять инклуды.



}



// При необходимости, можете дописать что-то сюда.
// Также по необходимости можно добавлять инклуды.



// Тесты.
// По умолчанию не запускается ни один тест. По мере готовности задания можно раскомментировать строчки ниже. Если
// раскомментировать строчку, перекомпилировать и запустить программу, запустится тест, проверяющий одну из требуемых
// частей задания. Для удобства справа предоставлен код, который необходимо (но не достаточно) должен компилироваться
// для прохождения теста.
// При сдаче необходимо раскомментировать все строчки ниже.
// РЕШЕНИЯ, В КОТОРЫХ ЧАСТЬ ТЕСТОВ ЗАКОММЕНТИРОВАНА, НЕ ПРОЙДУТ АВТОМАТИЧЕСКОЕ ТЕСТИРОВАНИЕ.

#define TEST_CONSTRUCTOR                // BigInt x("179"); BigInt y(57);
#define TEST_EQUAL_OPERATOR             // BigInt a("179"), b("57"); a == b; 179 == a; a == 179;
#define TEST_NOT_EQUAL_OPERATOR         // BigInt a("179"), b("57"); a != b; 179 != b; b != 179;
#define TEST_LESS_OPERATOR              // BigInt a("179"), b("57"); a < b;  57 < a;   b < 179;
#define TEST_GREATER_OPERATOR           // BigInt a("179"), b("57"); a > b;  179 > b;  a > 57;
#define TEST_LESS_OR_EQUAL_OPERATOR     // BigInt a("179"), b("57"); a <= b; 57 <= a;  b <= 179;
#define TEST_GREATER_OR_EQUAL_OPERATOR  // BigInt a("179"), b("57"); a >= b; 179 >= b; a >= 57;
#define TEST_PLUS_OPERATOR              // BigInt a("179"), b("57"); a + b;  122 + b;  b + 122; a += b; b += 122;
#define TEST_MINUS_OPERATOR             // BigInt a("179"), b("57"); a - b;  a - 122;  200 - a; a -= b; b -= 17;
#define TEST_INCREMENT_OPERATOR         // BigInt a("177"); a++; ++a;
#define TEST_DECREMENT_OPERATOR         // BigInt a("181"); a--; --a;
#define TEST_TO_STRING                  // BigInt a("179"); a.to_string();
#define TEST_INPUT                      // BigInt a; std::cin >> a;
#define TEST_OUTPUT                     // BigInt a("179"); std::cout << a;
#define TEST_ASSIGNMENT_OPERATORS       // BigInt a("179"), b("57"); BigInt c; c = a; c -= b; c += a;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// НИЖЕ НАХОДЯТСЯ АВТОТЕСТЫ
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Изменять любым способом код, находящийся ниже, запрещено. Решения, в которых это правило нарушено, не проверяются.

#ifdef TEST_CONSTRUCTOR

void test_constructor() {
    Lab01::BigInt x("179");
    Lab01::BigInt y(57);
    std::cout << "constructor test passed" << std::endl;
}

#endif // TEST_CONSTRUCTOR

#ifdef TEST_EQUAL_OPERATOR

void test_equal_operator() {
    assert(!(Lab01::BigInt("0") == Lab01::BigInt("1")));
    assert(!(Lab01::BigInt("111111111111111999999999999999") == Lab01::BigInt("999999999999999111111111111111")));
    assert(!(Lab01::BigInt("999999999999999999999999999999") == Lab01::BigInt("1000000000000000000000000000000")));
    assert(!(100 == Lab01::BigInt("101")));
    assert(!(Lab01::BigInt("100") == 101));

    assert(!(Lab01::BigInt("1") == Lab01::BigInt("0")));
    assert(!(Lab01::BigInt("999999999999999111111111111111") == Lab01::BigInt("111111111111111999999999999999")));
    assert(!(Lab01::BigInt("1000000000000000000000000000000") == Lab01::BigInt("999999999999999999999999999999")));
    assert(!(Lab01::BigInt("101") == 100));
    assert(!(101 == Lab01::BigInt("100")));

    assert(Lab01::BigInt("0") == Lab01::BigInt("0"));
    assert(Lab01::BigInt("111111111111111111111111111111111") ==
           Lab01::BigInt("111111111111111111111111111111111"));
    assert(100 == Lab01::BigInt("100"));
    assert(Lab01::BigInt("100") == 100);

    std::cout << "equal_operator test passed" << std::endl;
}

#endif // TEST_EQUAL_OPERATOR

#ifdef TEST_NOT_EQUAL_OPERATOR

void test_not_equal_operator() {
    assert(Lab01::BigInt("0") != Lab01::BigInt("1"));
    assert(Lab01::BigInt("111111111111111999999999999999") != Lab01::BigInt("999999999999999111111111111111"));
    assert(Lab01::BigInt("999999999999999999999999999999") != Lab01::BigInt("1000000000000000000000000000000"));
    assert(100 != Lab01::BigInt("101"));
    assert(Lab01::BigInt("100") != 101);

    assert(Lab01::BigInt("1") != Lab01::BigInt("0"));
    assert(Lab01::BigInt("999999999999999111111111111111") != Lab01::BigInt("111111111111111999999999999999"));
    assert(Lab01::BigInt("1000000000000000000000000000000") != Lab01::BigInt("999999999999999999999999999999"));
    assert(Lab01::BigInt("101") != 100);
    assert(101 != Lab01::BigInt("100"));

    assert(!(Lab01::BigInt("0") != Lab01::BigInt("0")));
    assert(!(Lab01::BigInt("111111111111111111111111111111111") !=
             Lab01::BigInt("111111111111111111111111111111111")));
    assert(!(100 != Lab01::BigInt("100")));
    assert(!(Lab01::BigInt("100") != 100));

    std::cout << "not_equal_operator test passed" << std::endl;
}

#endif // TEST_NOT_EQUAL_OPERATOR

#ifdef TEST_LESS_OPERATOR

void test_less_operator() {
    assert(Lab01::BigInt("0") < Lab01::BigInt("1"));
    assert(Lab01::BigInt("111111111111111999999999999999") < Lab01::BigInt("999999999999999111111111111111"));
    assert(Lab01::BigInt("999999999999999999999999999999") < Lab01::BigInt("1000000000000000000000000000000"));
    assert(100 < Lab01::BigInt("101"));
    assert(Lab01::BigInt("100") < 101);

    assert(!(Lab01::BigInt("1") < Lab01::BigInt("0")));
    assert(!(Lab01::BigInt("999999999999999111111111111111") < Lab01::BigInt("111111111111111999999999999999")));
    assert(!(Lab01::BigInt("1000000000000000000000000000000") < Lab01::BigInt("999999999999999999999999999999")));
    assert(!(Lab01::BigInt("101") < 100));
    assert(!(101 < Lab01::BigInt("100")));

    assert(!(Lab01::BigInt("0") < Lab01::BigInt("0")));
    assert(!(Lab01::BigInt("111111111111111111111111111111111") <
             Lab01::BigInt("111111111111111111111111111111111")));
    assert(!(100 < Lab01::BigInt("100")));
    assert(!(Lab01::BigInt("100") < 100));

    std::cout << "less_operator test passed" << std::endl;
}

#endif // TEST_LESS_OPERATOR

#ifdef TEST_GREATER_OPERATOR

void test_greater_operator() {
    assert(!(Lab01::BigInt("0") > Lab01::BigInt("1")));
    assert(!(Lab01::BigInt("111111111111111999999999999999") > Lab01::BigInt("999999999999999111111111111111")));
    assert(!(Lab01::BigInt("999999999999999999999999999999") > Lab01::BigInt("1000000000000000000000000000000")));
    assert(!(100 > Lab01::BigInt("101")));
    assert(!(Lab01::BigInt("100") > 101));

    assert(Lab01::BigInt("1") > Lab01::BigInt("0"));
    assert(Lab01::BigInt("999999999999999111111111111111") > Lab01::BigInt("111111111111111999999999999999"));
    assert(Lab01::BigInt("1000000000000000000000000000000") > Lab01::BigInt("999999999999999999999999999999"));
    assert(Lab01::BigInt("101") > 100);
    assert(101 > Lab01::BigInt("100"));

    assert(!(Lab01::BigInt("0") > Lab01::BigInt("0")));
    assert(!(Lab01::BigInt("111111111111111111111111111111111") >
             Lab01::BigInt("111111111111111111111111111111111")));
    assert(!(100 > Lab01::BigInt("100")));
    assert(!(Lab01::BigInt("100") > 100));

    std::cout << "greater_operator test passed" << std::endl;
}

#endif // TEST_GREATER_OPERATOR

#ifdef TEST_LESS_OR_EQUAL_OPERATOR

void test_less_or_equal_operator() {
    assert(Lab01::BigInt("0") <= Lab01::BigInt("1"));
    assert(Lab01::BigInt("111111111111111999999999999999") <= Lab01::BigInt("999999999999999111111111111111"));
    assert(Lab01::BigInt("999999999999999999999999999999") <= Lab01::BigInt("1000000000000000000000000000000"));
    assert(100 <= Lab01::BigInt("101"));
    assert(Lab01::BigInt("100") <= 101);

    assert(!(Lab01::BigInt("1") <= Lab01::BigInt("0")));
    assert(!(Lab01::BigInt("999999999999999111111111111111") <= Lab01::BigInt("111111111111111999999999999999")));
    assert(!(Lab01::BigInt("1000000000000000000000000000000") <= Lab01::BigInt("999999999999999999999999999999")));
    assert(!(Lab01::BigInt("101") <= 100));
    assert(!(101 <= Lab01::BigInt("100")));

    assert(Lab01::BigInt("0") <= Lab01::BigInt("0"));
    assert(Lab01::BigInt("111111111111111111111111111111111") <=
           Lab01::BigInt("111111111111111111111111111111111"));
    assert(100 <= Lab01::BigInt("100"));
    assert(Lab01::BigInt("100") <= 100);

    std::cout << "less_or_equal_operator test passed" << std::endl;
}

#endif // TEST_LESS_OR_EQUAL_OPERATOR

#ifdef TEST_GREATER_OR_EQUAL_OPERATOR

void test_greater_or_equal_operator() {
    assert(!(Lab01::BigInt("0") >= Lab01::BigInt("1")));
    assert(!(Lab01::BigInt("111111111111111999999999999999") >= Lab01::BigInt("999999999999999111111111111111")));
    assert(!(Lab01::BigInt("999999999999999999999999999999") >= Lab01::BigInt("1000000000000000000000000000000")));
    assert(!(100 >= Lab01::BigInt("101")));
    assert(!(Lab01::BigInt("100") >= 101));

    assert(Lab01::BigInt("1") >= Lab01::BigInt("0"));
    assert(Lab01::BigInt("999999999999999111111111111111") >= Lab01::BigInt("111111111111111999999999999999"));
    assert(Lab01::BigInt("1000000000000000000000000000000") >= Lab01::BigInt("999999999999999999999999999999"));
    assert(Lab01::BigInt("101") >= 100);
    assert(101 >= Lab01::BigInt("100"));

    assert(Lab01::BigInt("0") >= Lab01::BigInt("0"));
    assert(Lab01::BigInt("111111111111111111111111111111111") >=
           Lab01::BigInt("111111111111111111111111111111111"));
    assert(100 >= Lab01::BigInt("100"));
    assert(Lab01::BigInt("100") >= 100);

    std::cout << "greater_or_equal_operator test passed" << std::endl;
}

#endif // TEST_GREATER_OR_EQUAL_OPERATOR

#ifdef TEST_PLUS_OPERATOR

void test_plus_operator() {
    Lab01::BigInt a;
    Lab01::BigInt b = a += 10000;
    assert("10000" == a.to_string());
    assert("10000" == b.to_string());
    a += 0;
    assert("10000" == a.to_string());
    a += Lab01::BigInt("999999999999999999999999999999");
    assert("1000000000000000000000000009999" == a.to_string());
    a += 1;
    assert("1000000000000000000000000010000" == a.to_string());

    assert("1000000000000000000000000009999" ==
           (Lab01::BigInt("999999999999999999999999999999") + 10000).to_string());
    assert("1000000000000000000000000009999" ==
           (10000 + Lab01::BigInt("999999999999999999999999999999")).to_string());

    std::cout << "plus_operator test passed" << std::endl;
}

#endif // TEST_PLUS_OPERATOR

#ifdef TEST_MINUS_OPERATOR

void test_minus_operator() {
    Lab01::BigInt a("1000000000000000000000000010000");
    Lab01::BigInt b = a -= 1;
    assert("1000000000000000000000000009999" == a.to_string());
    assert("1000000000000000000000000009999" == b.to_string());
    a -= 0;
    assert("1000000000000000000000000009999" == a.to_string());
    a -= Lab01::BigInt("999999999999999999999999999999");
    assert("10000" == a.to_string());
    a -= 10000;
    assert("0" == a.to_string());
    assert("999999999999999999999999999999" ==
           (Lab01::BigInt("1000000000000000000000000009999") - 10000).to_string());
    assert("9999" == (10000 - Lab01::BigInt("1")).to_string());
    std::cout << "minus_operator test passed" << std::endl;
}

#endif // TEST_MINUS_OPERATOR

#ifdef TEST_INCREMENT_OPERATOR

void test_increment_operator() {
    Lab01::BigInt a("999999999999998");
    Lab01::BigInt b = ++a;
    assert("999999999999999" == a.to_string());
    assert("999999999999999" == b.to_string());
    b = a++;
    assert("999999999999999" == b.to_string());
    assert("1000000000000000" == a.to_string());
    (a++) = 10;
    assert("1000000000000001" == a.to_string());

    std::cout << "increment_operator test passed" << std::endl;
}

#endif // TEST_INCREMENT_OPERATOR

#ifdef TEST_DECREMENT_OPERATOR

void test_decrement_operator() {
    Lab01::BigInt a("1000000000000001");
    Lab01::BigInt b = --a;
    assert("1000000000000000" == a.to_string());
    assert("1000000000000000" == b.to_string());
    b = a--;
    assert("1000000000000000" == b.to_string());
    assert("999999999999999" == a.to_string());
    (a--) = 10;
    assert("999999999999998" == a.to_string());

    std::cout << "decrement_operator test passed" << std::endl;
}

#endif // TEST_DECREMENT_OPERATOR

#ifdef TEST_TO_STRING

bool check_to_string(const std::string &value) {
    return value == Lab01::BigInt(value).to_string();
}

void test_to_string() {
    assert(check_to_string("0"));
    assert(check_to_string("1"));
    assert(check_to_string("10"));
    assert(check_to_string("999"));
    assert(check_to_string("1234567890123456"));
    assert(check_to_string("100000000000000000000000000000000"));
    assert(check_to_string("14759328346542391834675032346958210394540"));

    std::cout << "to_string test passed" << std::endl;
}

#endif // TEST_TO_STRING

#ifdef TEST_INPUT

void test_input() {
    Lab01::BigInt a;

    std::stringstream("1234") >> a;
    assert(1234 == a);
    std::stringstream("438758234729356000000000000001230000000000000000000") >> a;
    assert(Lab01::BigInt("438758234729356000000000000001230000000000000000000") == a);

    std::cout << "input test passed" << std::endl;
}

#endif // TEST_INPUT

#ifdef TEST_OUTPUT

bool check_output(const std::string &value) {
    std::stringstream ss;
    ss << Lab01::BigInt(value);
    return value == ss.str();
}

void test_output() {
    assert(check_output("0"));
    assert(check_output("1"));
    assert(check_output("10"));
    assert(check_output("999"));
    assert(check_output("1234567890123456"));
    assert(check_output("100000000000000000000000000000000"));

    std::cout << "output test passed" << std::endl;
}

#endif // TEST_OUTPUT

#ifdef TEST_ASSIGNMENT_OPERATORS

void test_assignment_operators() {
    const Lab01::BigInt a("1234");
    const Lab01::BigInt b("56");

    assert(a == Lab01::BigInt(a));
    assert(1290 == a + b);
    assert(1178 == a - b);
    assert("1234" == a.to_string());
    assert(!(a == b));
    assert(a != b);
    assert(b < a);
    assert(b <= a);
    assert(a > b);
    assert(a >= b);

    Lab01::BigInt c;
    c += a;
    assert(1234 == c);
    c = a;
    assert(1234 == c);
    c -= b;
    assert(1178 == c);

    std::stringstream ss;
    ss << a << " " << b;
    assert("1234 56" == ss.str());

    std::cout << "assignment_operators test passed" << std::endl;
}

#endif // TEST_ASSIGNMENT_OPERATORS

int main() {
#ifdef TEST_CONSTRUCTOR
    test_constructor();
#endif // TEST_CONSTRUCTOR

#ifdef TEST_EQUAL_OPERATOR
    test_equal_operator();
#endif // TEST_EQUAL_OPERATOR

#ifdef TEST_NOT_EQUAL_OPERATOR
    test_not_equal_operator();
#endif // TEST_NOT_EQUAL_OPERATOR

#ifdef TEST_LESS_OPERATOR
    test_less_operator();
#endif // TEST_LESS_OPERATOR

#ifdef TEST_GREATER_OPERATOR
    test_greater_operator();
#endif // TEST_GREATER_OPERATOR

#ifdef TEST_LESS_OR_EQUAL_OPERATOR
    test_less_or_equal_operator();
#endif // TEST_LESS_OR_EQUAL_OPERATOR

#ifdef TEST_GREATER_OR_EQUAL_OPERATOR
    test_greater_or_equal_operator();
#endif // TEST_GREATER_OR_EQUAL_OPERATOR

#ifdef TEST_PLUS_OPERATOR
    test_plus_operator();
#endif // TEST_PLUS_OPERATOR

#ifdef TEST_MINUS_OPERATOR
    test_minus_operator();
#endif // TEST_MINUS_OPERATOR

#ifdef TEST_INCREMENT_OPERATOR
    test_increment_operator();
#endif // TEST_INCREMENT_OPERATOR

#ifdef TEST_DECREMENT_OPERATOR
    test_decrement_operator();
#endif // TEST_DECREMENT_OPERATOR

#ifdef TEST_TO_STRING
    test_to_string();
#endif // TEST_TO_STRING

#ifdef TEST_INPUT
    test_input();
#endif // TEST_INPUT

#ifdef TEST_OUTPUT
    test_output();
#endif // TEST_OUTPUT

#ifdef TEST_ASSIGNMENT_OPERATORS
    test_assignment_operators();
#endif // TEST_ASSIGNMENT_OPERATORS

    return 0;
}
