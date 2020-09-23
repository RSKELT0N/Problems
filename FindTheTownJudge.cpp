#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findJudge(int N, vector<vector<int>> &trust) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    if (trust.size() == 0)
        return 1;

    unordered_set<int> invalid;
    unordered_set<int> valid;
    for (auto i = 0; i < trust.size(); i++) {
        invalid.insert(trust[i][0]);
        if (invalid.find(trust[i][1]) == invalid.end())
            valid.insert(trust[i][1]);
    }

    for (auto i : invalid)
        if (valid.find(i) != valid.end())
            valid.erase(i);

    if (valid.empty())
        return -1;


    int ans = 0;
    for (auto i = 0; i < trust.size(); i++) {
        if (trust[i][0] != *(valid.begin()) && trust[i][1] == *(valid.begin())) {
            ans++;
        }
    }

    return (valid.empty() || ans != N - 1 || ans == N ? -1 : *(valid.begin()));
}

int main() {
    vector<vector<int>> trust = {
            {1, 3},
            {2, 3}
    };

    cout << findJudge(3, trust);
    return 0;
}
