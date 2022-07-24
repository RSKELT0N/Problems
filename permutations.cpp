#include <stdio.h>
#include <stdint.h>
#include <vector>

void swap(int& a, int& b) {
    int tmp = a;
     a = b;
     b = tmp;
}
    
 std::vector<std::vector<int>> permute(std::vector<int>& nums, int32_t pos, size_t size) {
    static std::vector<std::vector<int>> res;
    if(pos == size) {
         res.push_back(nums);
}
        
    for(int i = pos; i <= size; i++) {
        swap(nums[pos], nums[i]);
        permute(nums, pos+1, size);
        swap(nums[pos], nums[i]);
    }
    return res;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    auto res = permute(nums, 0, nums.size() - 1);

    for(auto& permutation : res) {
        for(auto& val : permutation) {
            printf("%d ", val);
        }
        printf("\n");
    }
    return 0;
}
