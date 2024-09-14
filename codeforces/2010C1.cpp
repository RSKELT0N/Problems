#include <iostream>
#include <string>

int main()
{
    std::string in = {};
    std::cin >> in;

    bool found = false;
    std::string start_str, end_str;

    for(int i = 0; i < in.size(); i++)
    {
        if(found)
            break;

        start_str += in[i];
        end_str = in[in.size()-i-1] + end_str;

        if(start_str == end_str && (in.size()-i-1) <= i && start_str != in)
        {
            std::cout << "Yes\n";
            std::cout << end_str << "\n";
            found = !found;
        }
    }

    if(!found)
        std::cout << "No\n";

    return 0;
}
