class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
//         int currentMax = INT_MIN;
//         int totalMax = INT_MIN;

//     for(int i = 0; i < A.size(); i++){
//         currentMax = max(currentMax, 0) + A[i];
//         cout << currentMax << endl;
//         totalMax = max(totalMax, currentMax);
//     }
//          cout << totalMax << endl;
//     return (totalMax > (A[0] +A[A.size()-1])) ? totalMax : (A[0] +A[A.size()-1]);
        
        
    //     int max = INT_MIN;
    //     for(int j = 0; j < A.size(); j++) {
    //     int curr = A[j];
    //     for(int i = j+1; i < A.size(); i++) {
    //         curr+=A[i];
    //         if(curr > max)
    //             max = curr;
    //         else curr-=A[i];
    //         }
    //     }
    //     int newMax = INT_MIN;
    //     int newCurr = 0;
    //     for(int i = 0; i < A.size(); i++) {
    //         newCurr = A[i];
    //         if(newCurr > newMax)
    //             newMax = newCurr;
    //     }
    //     int sum = A[0]+A[A.size()-1];
    //     if(sum > newMax)
    //         newMax = sum;
    //     if(max > newMax)
    //         return max;
    //     else return newMax;
    // }
        
    int sum1 = 0;
 	int sum2 = 0;
 	int min_sum = INT_MAX;
 	int max_sum = INT_MIN;
 	int total = 0;

 	for (int a : A) {
 		total += a;
 		sum1 += a, sum2 += a;
 		max_sum = max(max_sum, sum1);
 		min_sum = min(min_sum, sum2);
 		sum1 = max(0, sum1);
 		sum2 = min(0, sum2);
 	}
 	if (total == min_sum)
 			return max_sum;
 	return max(max_sum, total-min_sum);
 }
};
