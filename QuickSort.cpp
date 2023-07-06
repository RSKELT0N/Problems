#include <iostream>


int partition(int * vals, int lower, int upper) noexcept
{
    int pi = vals[upper];
    int i = lower - 1;

    for(int swp = lower; swp <= upper - 1; swp++)
    {
        if(vals[swp] < pi)
        {
            i++;
            std::swap(vals[i], vals[swp]);
        }
    }
    std::swap(vals[i + 1], vals[upper]);
    return i+1;
}

void quick_sort(int * values, int lower, int upper) noexcept
{
    if(lower < upper) {
        int pi = partition(values, lower, upper);

        quick_sort(values, lower, pi - 1);
        quick_sort(values, pi + 1, upper);
    }
}

int main([[maybe_unused]]int argc, [[maybe_unused]]char** argv) {

    static constexpr const size_t N = 10;
    static int values[N] = {6,5,3,7,3,2,6,6,2};
    quick_sort(values, 0, static_cast<int>(N - 1));

    for(int * i = values; i != (values + N); i++)
    {
        std::cout << *(i) << " ";
    }

    return EXIT_SUCCESS;
}
