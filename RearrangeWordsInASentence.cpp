class Solution {
public:
    vector<string> res;
    string arrangeWords(string text) {
        stringstream ss(text);
        string word;
        while(ss >> word) {
            for(char& a : word)
                if(a >= 'A' && a <= 'Z')
                    a+='a'-'A';
            res.push_back(word);
        }
        stable_sort(res.begin(),res.end(), [](const string &s1,const string &s2){
           return s1.length() < s2.length(); 
        });
        string ans = "";
        for(auto c : res) {
            ans+= c;
            ans+= " ";
        }
        ans.pop_back();
        ans[0]-='a'-'A';
        
        return ans;
    }
};
