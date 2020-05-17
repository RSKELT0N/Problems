class Solution {
public:
// unordered_map<char, int> letters;
// vector<int> ans;
// int currVal = 0;
// bool found = false;

// vector<int> findAnagrams(string s, string p) {
//     for (auto c : p)
//         letters[c] = 0;

//     for (int i = 0; i < s.size(); i++) {
//         currVal = 0;
//         if (letters.find(s[i]) != letters.end())
//             letters[s[i]]++;
//         else
//             for (char c : p)
//                 letters[c] = 0;

//         for (auto c : letters)
//             currVal += c.second;

//         if (currVal == p.size()) {
//             currVal = 0;
//             ans.push_back(i - p.size() + 1);
//             for (char c : p)
//                 if (c != p[p.size() - 1])
//                     letters[c] = 0;
//                 else letters[c] = 1;
//         }
//     }
//     return ans;
// }
    int mp1[26], mp2[26];
    bool same = true;
    vector<int> ans;
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length())
            return ans;
        for(int i = 0; i < 26; i++) {
            mp1[i] = 0;
            mp2[i] = 0;
        }
        
        for(auto a : p)
            mp1[a-'a']++;
        
        for(int i = 0; i < p.length(); i++) {
            mp2[s[i]-'a']++;
        }
        
        for(int k = 0; ; k++) {
            same = true;
            for(int i = 0; i < 26; i++) {
                if(mp1[i] != mp2[i]) {
                    same = false;
                    break;
                }   
            }
            if(same) {
                ans.push_back(k);
            }
            if(k >= s.length()-p.length())
                break;
            mp2[s[k]-'a']--;
            mp2[s[p.size()+k]-'a']++;
        }
        return ans;
    }
};
