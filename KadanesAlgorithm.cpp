class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int currentMax = INT_MIN;
        int totalMax = INT_MIN;

    for(int i = 0; i < A.size(); i++){
        currentMax = max(currentMax, 0) + A[i];
        totalMax = max(totalMax, currentMax);
    }
    return totalMax;
