#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unordered_map<int,int> appear;

    for(auto i: nums) {
        if(++appear[i] > nums.size()/2)
            return i;
    }
    return 0;
}

int main() {
    vector<int> nums = {3,2,3};
    cout << majorityElement(nums);
    return 0;
}
