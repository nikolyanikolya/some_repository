#include <iostream>

int main() {

   auto generator = [i=0]() mutable {return i++;};
   class _lambda{
       mutable int i=0;
   public:
       auto operator()() const{
           return i++;
       }
   };
   auto count_even()
}
