#include <iostream>
#include "Class_Vector.h"

template class Vector<int>;

int main() {
    Vector<int> vec {5, 6};
    Vector<int> vec1 {5, 6, 8};
    Vector<int> vec2;
    vec.reserve(10);
    //std::cout << vec.size();
    //std::cout << std::endl;
    //std::cout << vec.capacity(); 
    vec1.emplace(2,5);
    vec1.emplace(2,10);
    std::cout << vec1[2] << std::endl;
    //vec2 += vec1;
    //std::cout << vec2;
    //std::cout << vec = vec + vec1;
    // vec2 = vec;
    //std::cout << (vec == vec1);
    // tmp.reserve(10);
    // std::cout << tmp.capacity() << std::endl;
    // std::cout << tmp.size();
    //tmp.emplace(1,0);
    //tmp.erase(0);
    //std::cout << tmp;
    return 0;
}