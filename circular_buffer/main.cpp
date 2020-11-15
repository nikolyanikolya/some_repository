#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define _GLIBCXX_DEBUG

#include <cassert>   // assert()
#include <cstddef>   // std::size_t
#include <iostream>  // Требуется из-за бага в библиотеке doctest: https://github.com/onqtam/doctest/issues/356
#include "doctest.h"

namespace lab_02 {

    template<typename T, long long MaxElements>
    struct circular_buffer {
    private:
        T cycle[MaxElements]{};
        long long begin = 0;  // указатели на начало и конец
        long long end = 0;
        bool is_full = false;  //заполнен ли буфер?
    public:
        circular_buffer() = default;

        T &operator[](std::size_t index) {
            return cycle[index];
        }

        T &front() {
            assert(!empty());
            return cycle[begin];
        }

        T &back() {
            assert(!empty());
            auto t = end - 1;
            if (t < 0) {
                t = MaxElements - 1;
            }

            return cycle[t];
        }

        const T &operator[](std::size_t index) const {
            return cycle[index];
        }

        [[nodiscard]] const T &front() const {
            assert(!empty());
            return cycle[begin];
        }

        [[nodiscard]] const T &back() const {
            assert(!empty());
            auto t = end - 1;
            if (t < 0) {
                t = MaxElements - 1;
            }
            return cycle[t];
        }

        long long get_begin() const {
            return begin;
        }

        [[nodiscard]] long long size() const {
            long long current = end - begin;
            if (is_full && current == 0) {
                return MaxElements;
            }
            if (current >= 0) {
                return current;
            } else {
                return current + MaxElements;
            }
        }

        [[nodiscard]] bool empty() const {
            return (begin == end);
        }

        void push_back(T value) {
            if (end == MaxElements) {
                end = 0;
            }
            cycle[end++] = value;
            if (end == begin) {
                is_full = true;
            }
        }

        void push_front(T value) {
            begin--;
            if (begin < 0) {
                begin = MaxElements - 1;
            }
            cycle[begin] = value;
            if (end == begin) {
                is_full = true;
            }
        }

        void pop_back() {
            end--;
            if (end < 0) {
                end = MaxElements - 1;
            }
            is_full = false;
        }

        void pop_front() {
            begin++;
            if (begin >= MaxElements) {
                begin -= MaxElements;
            }
            is_full = false;
        }
    };


    template<typename T, long long m, long long n>
    bool operator==(const circular_buffer<T, m> &r, const circular_buffer<T, n> &t) {
        long long counter = 0;
        if (r.size() != t.size()) {
            return false;
        }

        while (counter != r.size()) {
            if (!(r[counter] == t[counter])) {
                return false;
            }
            counter++;
        }
        return true;
    }

    template<typename T, long long m, long long n>
    bool operator!=(const circular_buffer<T, m> &r, const circular_buffer<T, n> &t) {
        return (!(r == t));
    }

    namespace tests {

// ТЕСТЫ

//

// main() будет автоматически написан библиотекой doctest, запрещается его

// создавать самостоятельно. Библиотека запустит все тесты вида TEST_CASE() и

// проверит в них все условия CHECK(), не прерывая тест. Запрещается изменять

// или отключать существующие тесты, но вы можете дописывать новые в конец.

        TEST_CASE ("Empty circular_buffer") {
            circular_buffer<int, 5> buffer;

                    CHECK(buffer.empty());

                    CHECK(buffer.size() == 0);
        }

        TEST_CASE ("push_back(), front(), back()") {
            circular_buffer<int, 5> buffer;

            buffer.push_back(10);

                    CHECK(buffer.front() == 10);

                    CHECK(buffer.back() == 10);

            buffer.push_back(20);

                    CHECK(buffer.front() == 10);

                    CHECK(buffer.back() == 20);

            buffer.push_back(30);

                    CHECK(buffer.front() == 10);

                    CHECK(buffer.back() == 30);
        }

        TEST_CASE ("push_back(), empty(), size()") {
            circular_buffer<int, 5> buffer;

            buffer.push_back(10);

                    CHECK(!buffer.empty());

                    CHECK(buffer.size() == 1);

            buffer.push_back(20);

                    CHECK(!buffer.empty());

                    CHECK(buffer.size() == 2);

            buffer.push_back(30);

                    CHECK(!buffer.empty());

                    CHECK(buffer.size() == 3);
        }

        TEST_CASE ("push_back(), operator[]") {
            circular_buffer<int, 5> buffer;

            buffer.push_back(10);

                    CHECK(buffer[0] == 10);

            buffer.push_back(20);

                    CHECK(buffer[0] == 10);

                    CHECK(buffer[1] == 20);

            buffer.push_back(30);

                    CHECK(buffer[0] == 10);

                    CHECK(buffer[1] == 20);

                    CHECK(buffer[2] == 30);
        }

        TEST_CASE ("modifying values") {
            circular_buffer<int, 5> buffer;

            buffer.push_back(10);

            buffer.front() = 20;

                    CHECK(buffer.front() == 20);

                    CHECK(buffer.back() == 20);

                    CHECK(buffer[0] == 20);

            buffer.back() = 30;

                    CHECK(buffer.front() == 30);

                    CHECK(buffer.back() == 30);

                    CHECK(buffer[0] == 30);

            buffer[0] = 40;

                    CHECK(buffer.front() == 40);

                    CHECK(buffer.back() == 40);

                    CHECK(buffer[0] == 40);
        }

        TEST_CASE ("const circular_buffer") {
            circular_buffer<int, 5> buffer;

            buffer.push_back(10);

            const auto &const_buffer = buffer;

                    CHECK(!const_buffer.empty());

                    CHECK(const_buffer.size() == 1);

                    CHECK(const_buffer.front() == 10);

                    CHECK(const_buffer.back() == 10);

                    CHECK(const_buffer[0] == 10);
        }

        TEST_CASE ("push_front(), front(), back()") {
            circular_buffer<int, 5> buffer;

            buffer.push_front(10);

                    CHECK(buffer.front() == 10);

                    CHECK(buffer.back() == 10);

            buffer.push_front(20);

                    CHECK(buffer.front() == 20);

                    CHECK(buffer.back() == 10);

            buffer.push_front(30);

                    CHECK(buffer.front() == 30);

                    CHECK(buffer.back() == 10);
        }

        TEST_CASE ("push_front(), empty(), size()") {
            circular_buffer<int, 5> buffer;

            buffer.push_front(10);

                    CHECK(!buffer.empty());

                    CHECK(buffer.size() == 1);

            buffer.push_front(20);

                    CHECK(!buffer.empty());

                    CHECK(buffer.size() == 2);

            buffer.push_front(30);

                    CHECK(!buffer.empty());

                    CHECK(buffer.size() == 3);
        }

        TEST_CASE ("push_back followed by pop_back") {
            circular_buffer<int, 5> buffer;

            buffer.push_back(10);

            buffer.pop_back();

                    CHECK(buffer.empty());

                    CHECK(buffer.size() == 0);
        }

        TEST_CASE ("push_back followed by pop_front") {
            circular_buffer<int, 5> buffer;

            buffer.push_back(10);

            buffer.pop_front();

                    CHECK(buffer.empty());

                    CHECK(buffer.size() == 0);
        }

        TEST_CASE ("comparison operators") {
            circular_buffer<int, 5> buf_a;

            circular_buffer<int, 6> buf_b;

            circular_buffer<int, 7> buf_c;

            buf_a.push_back(10);

            buf_b.push_back(10);

                    CHECK(buf_a == buf_a);

                    CHECK(buf_b == buf_b);

                    CHECK(buf_a == buf_b);

                    CHECK(buf_b == buf_a);

                    CHECK(buf_a != buf_c);

                    CHECK(buf_c != buf_a);

                    CHECK(buf_b != buf_c);

                    CHECK(buf_c != buf_b);
        }

        TEST_CASE ("custom struct inside") {
            struct Foo {
                int data = 0;
            };

            circular_buffer<Foo, 5> buffer;

            buffer.push_back(Foo{123});

                    CHECK(!buffer.empty());

                    CHECK(buffer.size() == 1);

                    CHECK(buffer.front().data == 123);

                    CHECK(buffer.back().data == 123);

                    CHECK(buffer[0].data == 123);

            buffer.pop_back();
        }

        TEST_CASE ("comparison only uses operator==") {
            struct Foo {
                bool operator==(const Foo &) const {
                    return true;
                }
            };

            circular_buffer<Foo, 5> buffer;

                    CHECK(buffer == buffer);
        }

    }  // namespace tests

}  // namespace lab_02

TEST_CASE ("in correct namespace") {
    [[maybe_unused]] lab_02::circular_buffer<int, 5> buffer;
}
