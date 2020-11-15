#include <cassert>
#include <iostream>
#include <sstream>

#include <string>
#include <limits>

namespace Lab01 {

// Реализуйте этот класс.

    struct BigInt {
    private:
        unsigned int value;
    public:
        BigInt() {
            value = 0;
        }

        BigInt(const std::string &s) {
            unsigned int value_ = 0;
            for (int i = 0; i < s.length(); i++) {
                value_ *= 10;
                value_ += s[i] - '0';
            }
            value = value_;
            assert(value <= std::numeric_limits<unsigned int>::max());
            assert(value >= std::numeric_limits<unsigned int>::min());
        }

        BigInt(const unsigned int &value_) {
            value = value_;
            assert(value <= std::numeric_limits<unsigned int>::max());
            assert(value >= std::numeric_limits<unsigned int>::min());
        }

        bool operator==(const BigInt &x) const {
            return x.value == value;
        }

        friend bool operator==(const unsigned int &x, const BigInt &y);

        bool operator>=(const BigInt &x) {
            return value >= x.value;
        }

        bool operator<=(const BigInt &x) {
            return value <= x.value;
        }

        bool operator!=(const BigInt &x) {
            return x.value != value;
        }

        friend bool operator!=(const unsigned int &x, const BigInt &y);

        bool operator>(const BigInt &x) const {
            return value > x.value;
        }

        bool operator<(const BigInt &x) const {
            return value < x.value;
        }

        BigInt operator+(const BigInt &y) {
            return BigInt(value + y.value);
        }
        std::string to_string(){
            std::string str="";
            char cur;
            unsigned int value_= value;
            int i=0;
            while (value_!=0){
                value_/=10;
                i++;
            }
            int a[i];
            value_=value;
            for(int j=i-1; j>=0; j--){
                a[i]=value_%10;
                value/=10;
            }
            for(int j=0; j<i; j++){
                cur=a[i]+'0';
                str+=cur;
            }
            return str;
        }

        friend BigInt operator+(const BigInt &x, const BigInt &y);

        friend bool operator<(const unsigned int &y, const BigInt &x);

        friend bool operator>(const unsigned int &y, const BigInt &x);

        friend bool operator>=(const unsigned int &y, const BigInt &x);

        friend bool operator<=(const unsigned int &y, const BigInt &x);

    };

    bool operator==(const unsigned int &x, const BigInt &y) {
        BigInt compare_element(x);
        return compare_element.value == y.value;
    }

    bool operator!=(const unsigned int &x, const BigInt &y) {
        BigInt compare_element(x);
        return compare_element.value != y.value;
    }

    bool operator<(const unsigned int &y, const BigInt &x) {
        BigInt compare_element(y);
        return compare_element.value < x.value;
    }

    bool operator>(const unsigned int &y, const BigInt &x) {
        BigInt compare_element(y);
        return compare_element.value > x.value;
    }

    bool operator<=(const unsigned int &y, const BigInt &x) {
        BigInt compare_element(y);
        return compare_element.value <= x.value;
    }

    bool operator>=(const unsigned int &y, const BigInt &x) {
        BigInt compare_element(y);
        return compare_element.value >= x.value;
    }

    BigInt operator+(const BigInt &x, const BigInt &y) {
        return BigInt(x.value + y.value);
    }

    BigInt &operator+=(BigInt &x, const BigInt &y) {
        return x = x + y;
    }

    BigInt &operator+=(BigInt &x, const unsigned int &y) {
        BigInt compare_element(y);
        return x = x + compare_element;
    }


// При необходимости, можете дописать что-то сюда.

// Также по необходимости можно добавлять инклуды.



}



// Тесты.

// По умолчанию не запускается ни один тест. По мере готовности задания можно раскомментировать строчки ниже. Если

// раскомментировать строчку, перекомпилировать и запустить программу, запустится тест, проверяющий одну из требуемых

// частей задания. Для удобства справа предоставлен код, который необходимо (но не достаточно) должен компилироваться

// для прохождения теста.

// При сдаче необходимо раскомментировать все строчки ниже.

// РЕШЕНИЯ, В КОТОРЫХ ЧАСТЬ ТЕСТОВ ЗАКОММЕНТИРОВАНА, НЕ ПРОЙДУТ АВТОМАТИЧЕСКОЕ ТЕСТИРОВАНИЕ.



#define TEST_CONSTRUCTOR                BigInt x("179"); BigInt y(57);

#define TEST_EQUAL_OPERATOR             BigInt a("179"), b("57"); a == b; 179 == a; a == 179;

#define TEST_NOT_EQUAL_OPERATOR         BigInt a("179"), b("57"); a != b; 179 != b; b != 179;

#define TEST_LESS_OPERATOR              BigInt a("179"), b("57"); a < b;  57 < a;   b < 179;

#define TEST_GREATER_OPERATOR           BigInt a("179"), b("57"); a > b;  179 > b;  a > 57;

#define TEST_LESS_OR_EQUAL_OPERATOR      BigInt a("179"), b("57"); a <= b; 57 <= a;  b <= 179;

#define TEST_GREATER_OR_EQUAL_OPERATOR   BigInt a("179"), b("57"); a >= b; 179 >= b; a >= 57;

#define TEST_PLUS_OPERATOR               BigInt a("179"), b("57"); a + b;  122 + b;  b + 122; a += b; b += 122;

// #define TEST_MINUS_OPERATOR             // BigInt a("179"), b("57"); a - b;  a - 122;  200 - a; a -= b; b -= 17;

// #define TEST_INCREMENT_OPERATOR         // BigInt a("177"); a++; ++a;

// #define TEST_DECREMENT_OPERATOR         // BigInt a("181"); a--; --a;

// #define TEST_TO_STRING                  // BigInt a("179"); a.to_string();

// #define TEST_INPUT                      // BigInt a; std::cin >> a;

// #define TEST_OUTPUT                     // BigInt a("179"); std::cout << a;

// #define TEST_ASSIGNMENT_OPERATORS       // BigInt a("179"), b("57"); BigInt c; c = a; c -= b; c += a;



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

    assert(Lab01::BigInt("111111111111111111111111111111111") == Lab01::BigInt("111111111111111111111111111111111"));

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

    assert(!(Lab01::BigInt("111111111111111111111111111111111") != Lab01::BigInt("111111111111111111111111111111111")));

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

    assert(!(Lab01::BigInt("111111111111111111111111111111111") < Lab01::BigInt("111111111111111111111111111111111")));

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

    assert(!(Lab01::BigInt("111111111111111111111111111111111") > Lab01::BigInt("111111111111111111111111111111111")));

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

    assert(Lab01::BigInt("111111111111111111111111111111111") <= Lab01::BigInt("111111111111111111111111111111111"));

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

    assert(Lab01::BigInt("111111111111111111111111111111111") >= Lab01::BigInt("111111111111111111111111111111111"));

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


    assert("1000000000000000000000000009999" == (Lab01::BigInt("999999999999999999999999999999") + 10000).to_string());

    assert("1000000000000000000000000009999" == (10000 + Lab01::BigInt("999999999999999999999999999999")).to_string());


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



    assert("999999999999999999999999999999" == (Lab01::BigInt("1000000000000000000000000009999") - 10000).to_string());

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



bool check_to_string(const std::string& value) {

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



bool check_output(const std::string& value) {

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