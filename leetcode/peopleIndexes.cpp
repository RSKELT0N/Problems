class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        /*sort(favoriteCompanies.begin(), favoriteCompanies.end(), [](const vector<string> &f1, const vector<string> &f2) {
           return f1.size()  < f2.size();
        });*/
        
        vector<int> ans;
        bool found;
        
        for (auto &fc : favoriteCompanies)
            sort(fc.begin(), fc.end());
        
        /*for (int i = 0; i < favoriteCompanies.size(); i++) {
            found = false;
            for (int k = 0; k < favoriteCompanies[i].size(); k++)
                cout << favoriteCompanies[i][k] << " ";
            cout << endl;
            for (int j = 0; j < favoriteCompanies.size(); j++) {
                if (i == j || favoriteCompanies[j].size() < favoriteCompanies[i].size())
                    continue;
                bool foundCurr;
                for (auto x : favoriteCompanies[i]) {
                    foundCurr = false;
                    int l=0, r=favoriteCompanies[j].size()-1;
                    while (l <= r) {
                        int m = l+(r-l)/2;
                        if (favoriteCompanies[j][m] == x) {
                            foundCurr = true;
                            break;
                        }
                        if (x > favoriteCompanies[j][m])
                            l=m+1;
                        else r=m-1;
                    }
                    if (!foundCurr) {
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (!found)
                ans.push_back(i);
        }*/
        
        
       /* for (int i = 0; i < favoriteCompanies.size(); i++) {
            for (int k = 0; k < favoriteCompanies[i].size(); k++)
                cout << favoriteCompanies[i][k] << " ";
            cout << endl;
            
        }*/
        
        for (int i = 0; i < favoriteCompanies.size(); i++) {
            found = true;
            for (int j = 0; j < favoriteCompanies.size(); j++) {
                if (i == j || favoriteCompanies[j].size() < favoriteCompanies[i].size())
                    continue;
                if (includes(favoriteCompanies[j].begin(), favoriteCompanies[j].end(), 
                             favoriteCompanies[i].begin(), favoriteCompanies[i].end())) {
                    found = false;
                    break;
                }
            }
            if (found)
                ans.push_back(i);
        }
        return ans;
    }
};
