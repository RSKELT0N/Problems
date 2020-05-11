 #include <iostream>
#include <vector>

using namespace std;

void sort(vector<int> &nums) {
    int c = 1;
    while (c > 0) {
        c = 0;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
                c++;
            }
    }
}

int binarySearch(vector<int> nums, int l, int r, int n) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (n == nums[m])
            return m;

        if (nums[m] > n)
            return binarySearch(nums, l, m - 1, n);

        return binarySearch(nums, m + 1, r, n);
    }
    return -1;
}


int main() {
    vector<int> nums = {3, 4, 7, 8, 8, 2, 1};
    sort(nums);
    cout << binarySearch(nums, 0, nums.size(), 8);
    return 0;
}
