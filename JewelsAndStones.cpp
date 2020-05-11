#include <iostream>
#include <unordered_set>

using namespace std;

class problem {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> jewels = unordered_set<char>();
        int c = 0;
        for (int i = 0; i < J.length(); i++) {
            if(jewels.find(J[i]) == jewels.end())
                jewels.insert(J[i]);
        }
        for (int i = 0; i < S.length(); i++) {
            if (jewels.find(S[i]) != jewels.end())
                c++;
        }
        return c;
    }
};

int main() {
    cout << problem().numJewelsInStones("aAA","aAAbbbbbbbbbb");
    return 0;
}
