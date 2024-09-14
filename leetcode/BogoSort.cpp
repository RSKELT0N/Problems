#include <iostream>

bool sorted(const int * values, const size_t n) noexcept
{
    int len = static_cast<int>(n);

    while(--len >= 0)
    {
        if(values[len] < values[len - 1])
            return false;
    }
    return true;
}

void shuffle(int * values, const size_t n)
{
    for(int * i = values; i != (values+n); i++)
    {
        std::swap(*i, values[rand() % n]);
    }
}

void bogo_sort(int * values, const size_t n) noexcept
{
    while(!sorted(values, n))
    {
        shuffle(values, n);
    }
}

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv) {

    static constexpr const size_t N = 10;
    static int values[N] = {6,5,3,7,3,2,6,6,2};
    bogo_sort(values, N);

    for(int * i = values; i != (values + N); i++)
    {
        std::cout << *(i) << " ";
    }

    return EXIT_SUCCESS;
}
