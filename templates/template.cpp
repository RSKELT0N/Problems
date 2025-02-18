/******************
* Author: Ryan Skelton
* file: template.cpp
*******************/

#include <iostream>

template<long N>
struct fact
{
    static constexpr long value = N * fact<N - 1>::value;
};

template<>
struct fact<1>
{
    static constexpr long value = 1;
};

template<long N>
struct fib
{
    static constexpr long value = fib<N - 1>::value + fib<N - 2>::value;
};

template<>
struct fib<1>
{
    static constexpr long value = 1;
};

template<>
struct fib<0>
{
    static constexpr long value = 0;
};

template<typename... T>
void print(T && ... args)
{
    ((std::cout << args << " "), ...);
    std::cout << std::endl;
}

void solve()
{
}

int main(int argc, char * argv[])
{
    solve();
    return 0;
}
