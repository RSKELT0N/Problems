class Solution {
public:
    std::unordered_set<int> found;
    int totalNumbers(vector<int>& digits) {

        int num1 = 0;
        int num2 = 0;
        int num3 = 0;
        for(int i = 0; i < digits.size(); i++)
        {
            if(digits[i] == 0) continue;
            num1 = digits[i];
            for(int j = 0; j < digits.size(); j++)
            {
                if(j == i) continue;
                num2 = num1 * 10 + digits[j];
                for(int k = 0; k < digits.size(); k++)
                {
                    if(k == i || k == j) continue;
                    num3 = num2 * 10 + digits[k];

                    if(num3 % 2 == 0)
                        found.insert(num3);
                }
            }
        }

        return found.size();
    }
};
