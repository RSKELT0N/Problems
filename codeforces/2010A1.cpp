#include <iostream>

int main()
{
    int n, m;
    std::cin >> n;
    int num, sum, flip;

    for(int i = 0; i < n ; i++)
    {
        sum = 0, flip = 1;
        std::cin >> m;
        for(int j = 0; j < m; j++)
        {
            std::cin >> num;
            sum += (num * flip);
            flip *= -1;
        }
        std::cout << sum << "\n";
    }
    return 0;
}
