#include <iostream>
#include <unordered_map>

using namespace std;

static auto _______ = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return 0;
}();

int firstUniqChar(string s) {
    unordered_map<char, int> values;

    for (char c : s)
        values[c]++;

    for (int i = 0; i < s.length(); i++)
        if (values[s[i]] == 1)
            return i;

    return -1;
}

int main() {
    cout << firstUniqChar("ppl");
    return 0;
}
