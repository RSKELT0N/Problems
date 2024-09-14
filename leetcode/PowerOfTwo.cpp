class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n < 0)
            return false;
        
        int one = 0;
        for(int i = 0; i<32; i++) {
            one += (n&(1<<i))>>i;
        }
        return (one==1);
    }
};
