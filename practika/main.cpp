#include <iostream>
#include <cassert>
template <typename T, std:: size_t N>
class my_array {
private:
    T data[N];
public:
    std::size_t
    my_array() = default;
    const T &get(std::size_t index) const{
        assert(index<N);
        return data[index];
    }
    void set(std:: size_t index, const T &value){
        assert(index < N);
        data[index] = value;
    }
    class iterator{
    private:
        my_array & arr;
        size_t index;
    public:
    iterator(my_array &arr, size_t index) : arr();
    bool operator != (iterator const &other) const;
    T &operator *() const;
    void operator++();
    iterator begin(){
        return iterator (*this, 0);
    }
    iterator end(){
        return iterator (*this, 0);
    }
    const_iterator begin()
    };
};
int main() {
    my_array<int, 5> arr;
    std:: cout<< arr.get(4);
    return 0;
}
