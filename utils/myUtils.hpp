// myUtils.hpp
// if class template or function template is used, then it's NOT possible to separate
// class declaration (in h) and class implementation(in cpp)
// thus we choose to use hpp file here

#include <iostream>
#include <algorithm>
#include <vector>
  
class MyUtils
{
public:
    template<typename T>
    void swap(T &x, T &y);
};

template<typename T>
void MyUtils::swap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}
