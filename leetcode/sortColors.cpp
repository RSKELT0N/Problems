class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0=0;
        int pn =n-1;
        int curr =0;
        while(curr<=pn){
            if(nums[curr] == 0){
                swap(nums[p0], nums[curr]);
                p0++;
                curr++;
            } else if(nums[curr] == 2){
                 swap(nums[pn], nums[curr]);
                pn--;
            } else{
                curr++;
            }
        }
    }
};
