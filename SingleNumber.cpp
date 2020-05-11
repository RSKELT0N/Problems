#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int singleNumber(vector<int> &nums) {
    unordered_set<int> vals;

    for (int i : nums)
        if (vals.find(i) == vals.end())
            vals.insert(i);
        else
            vals.erase(i);

    return *(vals.begin());
//    int x = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        x ^= nums[i];
//    }
//    return x;
}


int main() {
    vector<int> nums = {2,2, 1, 3,3};
    cout << "Single Number: " << singleNumber(nums) << "\n";
    return 0;
}
